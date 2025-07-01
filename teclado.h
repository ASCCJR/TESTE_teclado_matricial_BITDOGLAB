#ifndef TECLADO_H
#define TECLADO_H

/**
 * @brief Inicializa os pinos GPIO necessários para a varredura do teclado.
 * Deve ser chamada uma vez no início do programa.
 */
void teclado_init();

/**
 * @brief Realiza a varredura do teclado e retorna o caractere da tecla pressionada.
 * * @return Retorna o caractere correspondente ('1', 'A', etc.) se uma tecla 
 * for pressionada. Retorna o caractere nulo ('\0') se nenhuma 
 * tecla for pressionada. A função já inclui um pequeno debounce.
 */
char teclado_get_key();

#endif // TECLADO_H