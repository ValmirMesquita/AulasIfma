#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "dht.h"
#include "lcd_i2c.h"

#define DHT_PIN 2       // Pino de dados do sensor DHT22
#define I2C_SDA 4       // Pino SDA do I2C
#define I2C_SCL 5       // Pino SCL do I2C
#define LCD_ADDR 0x27   // Endereço I2C do LCD

void init_hardware() {
    stdio_init_all();

    // Inicializa I2C para o LCD
    i2c_init(i2c1, 100000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    // Inicializa LCD
    lcd_init(LCD_ADDR, i2c1);
    lcd_clear();
    lcd_set_cursor(0, 0);
    lcd_print("Temp: --.- C");
    lcd_set_cursor(0, 1);
    lcd_print("Umid: --.- %");
}

void read_dht22() {
    float temperature, humidity;

    if (dht_read(DHT_PIN, &temperature, &humidity) == 0) {
        char buffer[16];

        // Exibe no LCD
        lcd_set_cursor(6, 0);
        sprintf(buffer, "%.1f C", temperature);
        lcd_print(buffer);

        lcd_set_cursor(6, 1);
        sprintf(buffer, "%.1f %%", humidity);
        lcd_print(buffer);

        // Envia para a serial
        printf("Temperatura: %.1f C\n", temperature);
        printf("Umidade: %.1f %%\n", humidity);
    } else {
        printf("Erro ao ler DHT22\n");
    }
}

int main() {
    init_hardware();

    while (1) {
        read_dht22();
        sleep_ms(2000);
    }
}
