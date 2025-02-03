#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

const uint16_t PERIOD = 2000;
const float DIVIDER_PWM = 10.0;
const uint16_t LED_STEP = 10;
uint16_t led_level = 100;

void setup(int l)
{

    uint slice;
    gpio_set_function(l, GPIO_FUNC_PWM);
    slice = pwm_gpio_to_slice_num(l);
    pwm_set_clkdiv(slice, DIVIDER_PWM);
    pwm_set_wrap(slice, PERIOD);
    pwm_set_gpio_level(l, led_level);
    pwm_set_enabled(slice, true);
}

void botao(int b)
{
    gpio_init(b);
    gpio_set_dir(b, GPIO_IN);
    gpio_pull_up(b);
}

int main()
{
    botao(5);
    botao(6);
    botao(22);

    led_level = 0;
    stdio_init_all();
    setup(11);
    setup(12);
    setup(13);
    int ledAtual = 11;
    while (true)
    {
        pwm_set_gpio_level(ledAtual, led_level);
        if (!gpio_get(22))
        {
            led_level = 0;
            if (ledAtual == 11)
            {
                ledAtual = 12;
            }
            else if (ledAtual == 12)
            {
                ledAtual = 13;
            }
            else if (ledAtual == 13)
            {
                ledAtual = 11;
            }
            sleep_ms(500);
        }
        if (!gpio_get(6) && !gpio_get(5))
        {
            led_level = 0;
            sleep_ms(200);
        }
        else if (!gpio_get(5))
        {
            led_level += LED_STEP;
            sleep_ms(200);
        }
        else if (!gpio_get(6))
        {
            led_level -= LED_STEP;
            sleep_ms(200);
        }
    }
}
