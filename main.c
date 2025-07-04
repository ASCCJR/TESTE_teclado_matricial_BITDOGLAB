#include "pico/stdlib.h"
#include <stdio.h>

// Pinagem
const uint ROW_PINS[4] = {4, 8, 9, 16};      // Linhas como INPUT com PULL_UP
const uint COL_PINS[4] = {17, 18, 19, 20};   // Colunas como OUTPUT

// Keymap
const char keymap[4][4] = {
    {'D', 'C', 'B', 'A'},
    {'#', '9', '6', '3'},
    {'0', '8', '5', '2'},
    {'*', '7', '4', '1'}
};

int main() {
    stdio_init_all();
    while (!stdio_usb_connected()) {
        sleep_ms(100);
    }
    printf("=== TECLADO MATRICIAL 4x4 ===\n");
    printf("Pressione uma tecla...\n");

    // Configura linhas como INPUT com PULL_UP
    for (int i = 0; i < 4; i++) {
        gpio_init(ROW_PINS[i]);
        gpio_set_dir(ROW_PINS[i], GPIO_IN);
        gpio_pull_up(ROW_PINS[i]);
    }

    // Configura colunas como OUTPUT
    for (int i = 0; i < 4; i++) {
        gpio_init(COL_PINS[i]);
        gpio_set_dir(COL_PINS[i], GPIO_OUT);
        gpio_put(COL_PINS[i], 1); // Inicialmente HIGH
    }

    while (1) {
        for (int c = 0; c < 4; c++) {
            // Coloca coluna atual em LOW
            gpio_put(COL_PINS[c], 0);

            sleep_ms(1); // Pequeno delay para estabilizar

            for (int r = 0; r < 4; r++) {
                // Verifica se linha está LOW (tecla pressionada)
                if (!gpio_get(ROW_PINS[r])) {
                    char tecla = keymap[r][c];

                    // <<< saíde >>> 
                    printf("Tecla pressionada: %c\n", tecla);
                    
                    // Debounce - espera soltar a tecla
                    while(!gpio_get(ROW_PINS[r])) {
                        sleep_ms(20);
                    }
                    sleep_ms(50); // Delay adicional após soltar
                }
            }

            // Volta coluna para HIGH
            gpio_put(COL_PINS[c], 1);
        }
        sleep_ms(10);
    }
    return 0;
}
