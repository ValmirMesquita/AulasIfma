/**
 * Copyright (c) 2023 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

 #include <stdio.h>
 #include "btstack.h"
 #include "hardware/adc.h"
 
 #include "temp_sensor.h"
 #include "server_common.h"
 
 #define APP_AD_FLAGS 0x06  // Define os flags de anúncio BLE
 
 // Pacote de dados de anúncio BLE
 static uint8_t adv_data[] = {
     // Flags para indicar que o dispositivo é descoberto normalmente
     0x02, BLUETOOTH_DATA_TYPE_FLAGS, APP_AD_FLAGS,
     // Nome do dispositivo (substituir conforme necessário)
     0x17, BLUETOOTH_DATA_TYPE_COMPLETE_LOCAL_NAME, 'P', 'i', 'c', 'o', ' ', '0', '0', ':', '0', '0', ':', '0', '0', ':', '0', '0', ':', '0', '0', ':', '0', '0',
     // UUID do serviço (exemplo: 0x181A -> Serviço ambiental)
     0x03, BLUETOOTH_DATA_TYPE_COMPLETE_LIST_OF_16_BIT_SERVICE_CLASS_UUIDS, 0x1a, 0x18,
 };
 static const uint8_t adv_data_len = sizeof(adv_data);
 
 // Variáveis globais para armazenar informações da conexão BLE
 int le_notification_enabled;
 hci_con_handle_t con_handle;
 uint16_t current_temp;  // Temperatura atual
 
 // Callback para lidar com eventos BLE
 void packet_handler(uint8_t packet_type, uint16_t channel, uint8_t *packet, uint16_t size) {
     UNUSED(size);
     UNUSED(channel);
     bd_addr_t local_addr;
     
     if (packet_type != HCI_EVENT_PACKET) return;
 
     uint8_t event_type = hci_event_packet_get_type(packet);
     switch(event_type){
         case BTSTACK_EVENT_STATE:
             if (btstack_event_state_get_state(packet) != HCI_STATE_WORKING) return;
             gap_local_bd_addr(local_addr);
             printf("BTstack inicializado no endereço %s.\n", bd_addr_to_str(local_addr));
 
             // Configurar parâmetros de anúncio BLE
             uint16_t adv_int_min = 800;
             uint16_t adv_int_max = 800;
             uint8_t adv_type = 0;
             bd_addr_t null_addr;
             memset(null_addr, 0, 6);
             gap_advertisements_set_params(adv_int_min, adv_int_max, adv_type, 0, null_addr, 0x07, 0x00);
             assert(adv_data_len <= 31); // Limitação do BLE
             gap_advertisements_set_data(adv_data_len, (uint8_t*) adv_data);
             gap_advertisements_enable(1);
 
             // Atualizar temperatura
             poll_temp();
             break;
 
         case HCI_EVENT_DISCONNECTION_COMPLETE:
             // Se a conexão foi encerrada, desativar notificações
             le_notification_enabled = 0;
             break;
 
         case ATT_EVENT_CAN_SEND_NOW:
             // Enviar temperatura quando possível
             att_server_notify(con_handle, ATT_CHARACTERISTIC_ORG_BLUETOOTH_CHARACTERISTIC_TEMPERATURE_01_VALUE_HANDLE, (uint8_t*)&current_temp, sizeof(current_temp));
             break;
 
         default:
             break;
     }
 }
 
 // Função para ler a temperatura quando solicitado por um cliente BLE
 uint16_t att_read_callback(hci_con_handle_t connection_handle, uint16_t att_handle, uint16_t offset, uint8_t * buffer, uint16_t buffer_size) {
     UNUSED(connection_handle);
 
     if (att_handle == ATT_CHARACTERISTIC_ORG_BLUETOOTH_CHARACTERISTIC_TEMPERATURE_01_VALUE_HANDLE){
         return att_read_callback_handle_blob((const uint8_t *)&current_temp, sizeof(current_temp), offset, buffer, buffer_size);
     }
     return 0;
 }
 
 // Callback para lidar com escrita de características BLE
 int att_write_callback(hci_con_handle_t connection_handle, uint16_t att_handle, uint16_t transaction_mode, uint16_t offset, uint8_t *buffer, uint16_t buffer_size) {
     UNUSED(transaction_mode);
     UNUSED(offset);
     UNUSED(buffer_size);
     
     if (att_handle != ATT_CHARACTERISTIC_ORG_BLUETOOTH_CHARACTERISTIC_TEMPERATURE_01_CLIENT_CONFIGURATION_HANDLE) return 0;
     
     // Ativar ou desativar notificações baseando-se no valor recebido
     le_notification_enabled = little_endian_read_16(buffer, 0) == GATT_CLIENT_CHARACTERISTICS_CONFIGURATION_NOTIFICATION;
     con_handle = connection_handle;
 
     if (le_notification_enabled) {
         att_server_request_can_send_now_event(con_handle);
     }
     return 0;
 }
 
 // Função para medir e armazenar a temperatura
 void poll_temp(void) {
     adc_select_input(ADC_CHANNEL_TEMPSENSOR);
     uint32_t raw32 = adc_read();
     const uint32_t bits = 12;
 
     // Converter leitura bruta para um valor de 16 bits
     uint16_t raw16 = raw32 << (16 - bits) | raw32 >> (2 * bits - 16);
 
     // Converter leitura para temperatura em Celsius
     const float conversion_factor = 3.3 / (65535);
     float reading = raw16 * conversion_factor;
 
     // Aplicar equação de conversão
     float deg_c = 27 - (reading - 0.706) / 0.001721;
     current_temp = deg_c * 100;
     printf("Temperatura medida: %.2f °C\n", deg_c);
 }
 