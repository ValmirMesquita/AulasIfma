/**
 * Projeto contagem crescente e decrescente com alteração de chave e botão precionado
 *  Valmir Linhares de Sousa de Mesquita
 *  Data 31 de Janeiro de 2025
 */
 #include "pico/stdlib.h"

// Definição dos pinos dos segmentos do display
// Definimos uma array no formato vetor
const uint8_t segment_pins[] = {2, 3, 4, 5, 6, 7, 8};

// Mapeamento dos dígitos para os segmentos do display
// Definimos uma array no formato matriz
const uint8_t display[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 0, 0, 1, 1}  // 9
};

// Função para exibir um dígito no display
void display_digit(uint8_t digit) {
    for (int i = 0; i < 7; i++) {
        gpio_put(segment_pins[i], display[digit][i]);
    }
}

int main() {
    stdio_init_all();
    
    // Inicializa e configura os pinos dos segmentos como saída
    for (int i = 0; i < 7; i++) {
        gpio_init(segment_pins[i]);
        gpio_set_dir(segment_pins[i], GPIO_OUT);
        
    }

    uint8_t contador = 0;

    while (true) {
        display_digit(contador);  // Exibe o dígito atual no display
        sleep_ms(1000);  // Espera 1 segundo
        contador++;  // Incrementa o contador
        if (contador > 9) {
            contador = 0;  // Reinicia o contador após 9
        }
    }
    return 0;
}
