// ANÁLISE: MANIPULANDO PONTEIROS
#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int n = 10;
    int *p1 = NULL; // ponteiro de inteiro p1 tem por conteúdo NULL
    int *p2; // ponteiro de inteiro p2 (contém lixo de memória)

    printf("&n = %p, n = %d\n", &n, n);
    printf("&p1 = %p, p1 = %p\n", &p1, p1);
    printf("&p2 = %p, p2 = %p\n", &p2, p2);
    
    p1 = &n; // p1 aponta para o endereço do inteiro n
    p2 = p1; // p2 aponta para o mesmo endereço que p1 (também aponta para o endereço de n)
    *p2 = 4; // o conteúdo de p2 é 4 (logo, o conteúdo de p1 também foi alterado para 4)

    printf("\n&n = %p, n = %d\n", &n, n);
    printf("&p1 = %p, p1 = %p, *p1 = %d\n", &p1, p1, *p1);
    printf("&p2 = %p, p2 = %p, *p2 = %d\n", &p2, p2, *p2);
    return 0;
}