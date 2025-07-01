#include <stdio.h>
#include "pico/stdlib.h"
#include "teclado.h"

int main() {
    // Inicializa o stdio (para o printf funcionar via USB)
    stdio_init_all();
    
    // Dá um tempo para o monitor serial conectar
    sleep_ms(2000); 
    printf("Aplicativo de Teclado Modular Iniciado\n");

    // Inicializa o nosso módulo de teclado
    teclado_init();

    // Loop principal da aplicação
    while (true) {
        // Pega a tecla pressionada do nosso módulo
        char key = teclado_get_key();

        // Se a tecla for válida, imprime
        if (key != '\0') {
            printf("Lido do teclado: %c\n", key);
        }
        
        sleep_ms(10); // Evita consumir 100% da CPU
    }

    return 0;
}