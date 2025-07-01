#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "teclado.h"

// --- Detalhes de implementação ---

#define NUM_ROWS 4
#define NUM_COLS 4

// =============================================================================
// Mapeamento das teclas para o teclado 4x4
// =============================================================================
const char keys[NUM_ROWS][NUM_COLS] = {
    {'1', 'A', '2', '3'}, // Mapeamento para a linha física conectada a GP16
    {'*', 'D', '0', '#'}, // Mapeamento para a linha física conectada a GP17
    {'7', 'C', '8', '9'}, // Mapeamento para a linha física conectada a GP18
    {'4', 'B', '5', '6'}  // Mapeamento para a linha física conectada a GP19
};

// --- Pinos do teclado 4x4 ---
// Definição dos pinos para as linhas e colunas do teclado
const uint row_pins[NUM_ROWS] = {16, 17, 18, 19}; 
const uint col_pins[NUM_COLS] = {20, 4, 9, 8};   

// --- Implementação das funções públicas ---

void teclado_init() {
    // Configura os pinos das linhas como SAÍDA
    for (int i = 0; i < NUM_ROWS; i++) {
        gpio_init(row_pins[i]);
        gpio_set_dir(row_pins[i], GPIO_OUT);
    }

    // Configura os pinos das colunas como ENTRADA com PULL-UP
    for (int i = 0; i < NUM_COLS; i++) {
        gpio_init(col_pins[i]);
        gpio_set_dir(col_pins[i], GPIO_IN);
        gpio_pull_up(col_pins[i]);
    }
}

char teclado_get_key() {
    for (int r = 0; r < NUM_ROWS; r++) {
        // Ativa uma linha de cada vez, colocando-a em nível baixo
        for (int i = 0; i < NUM_ROWS; i++) {
            gpio_put(row_pins[i], 1);
        }
        gpio_put(row_pins[r], 0);

        // Varre as colunas
        for (int c = 0; c < NUM_COLS; c++) {
            if (gpio_get(col_pins[c]) == 0) {
                sleep_ms(50); // Debounce simples
                while(gpio_get(col_pins[c]) == 0); // Espera soltar
                
                gpio_put(row_pins[r], 1); // Restaura a linha
                return keys[r][c];
            }
        }
    }
    // Nenhuma tecla pressionada
    return '\0';
}