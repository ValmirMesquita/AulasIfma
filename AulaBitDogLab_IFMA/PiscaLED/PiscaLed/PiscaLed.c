#include <stdio.h>
#include "pico/stdlib.h"
//#include "hardware/pwm.h"
#include "hardware/clocks.h"

#define LEDR_PIN 13
#define LEDG_PIN 12
#define LEDB_PIN 11

#define BUTTON_LE_PIN 5

#define BUZZERA_PIN 21
#define BUZZER_FREQUENCY 100
// Definição de uma função para inicializar o PWM no pino do buzzer
void pwm_init_buzzer(uint pin) {
    // Configurar o pino como saída de PWM
    gpio_set_function(pin, GPIO_FUNC_PWM);

    // Obter o slice do PWM associado ao pino
    uint slice_num = pwm_gpio_to_slice_num(pin);

    // Configurar o PWM com frequência desejada
    //pwm_config config = pwm_get_default_config();
   // pwm_config_set_clkdiv(&config, clock_get_hz(clk_sys) / (BUZZER_FREQUENCY * 4096)); // Divisor de clock
   // pwm_init(slice_num, &config, true);

    // Iniciar o PWM no nível baixo
    pwm_set_gpio_level(pin, 0);
}

// Definição de uma função para emitir um beep com duração especificada
void beep(uint pin, uint duration_ms) {
    // Obter o slice do PWM associado ao pino
    uint slice_num = pwm_gpio_to_slice_num(pin);

    // Configurar o duty cycle para 50% (ativo)
    pwm_set_gpio_level(pin, 2048);

    // Temporização
    sleep_ms(duration_ms);

    // Desativar o sinal PWM (duty cycle 0)
    pwm_set_gpio_level(pin, 0);

    // Pausa entre os beeps
    sleep_ms(100); // Pausa de 100ms
}
int main()
{
    stdio_init_all();
    pwm_init_buzzer(BUZZERA_PIN);

    gpio_init(LEDR_PIN);
    gpio_set_dir(LEDR_PIN, GPIO_OUT);

    gpio_init(LEDG_PIN);
    gpio_set_dir(LEDG_PIN, GPIO_OUT);

    gpio_init(LEDB_PIN);
    gpio_set_dir(LEDB_PIN, GPIO_OUT);

    gpio_init(BUTTON_LE_PIN);
    gpio_set_dir(BUTTON_LE_PIN, GPIO_IN);

    gpio_init(BUZZERA_PIN);
    gpio_set_dir(BUZZERA_PIN, GPIO_OUT);

    while (true) {

        gpio_put(LEDR_PIN,1);
        gpio_put(LEDG_PIN,0);
        gpio_put(LEDB_PIN,0);
        
        beep(BUZZERA_PIN, 500); // Bipe de 500ms
        sleep_ms(5000); 

        gpio_put(LEDR_PIN,0);
        gpio_put(LEDG_PIN,1);
        gpio_put(LEDB_PIN,0);
        
        beep(BUZZERA_PIN, 500); // Bipe de 500ms
        sleep_ms(5000);

        gpio_put(LEDR_PIN,0);
        gpio_put(LEDG_PIN,0);
        gpio_put(LEDB_PIN,1);
       
        beep(BUZZERA_PIN, 500); // Bipe de 500ms
        sleep_ms(5000);


        printf("Hello, world!\n");
        sleep_ms(1000);     
        
    }
    
}
