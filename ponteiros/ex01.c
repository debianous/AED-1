// ANÁLISE: ALOCAÇÃO DE PONTEIROS
#include <stdio.h>

int main (void) {
    int a = 10;
    int *p1 = NULL; // o conteúdo do ponteiro p1 é nulo (inicializar evita lixos de memória)
    int *p2; // o conteúdo do ponteiro p2 é lixo de memória

    p1 = &a; // o ponteiro p1 armazena o endereço de memória de a
    p2 = p1; // o ponteiro p2 armazena o mesmo endereço de memória de p1
    *p2 = 4; // o conteúdo do ponteiro p2 é 4
    printf("a = %d", a); // o conteúdo do ponteiro p1 e de a passa a ser 4 também
    return 0;
}