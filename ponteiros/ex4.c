/* 1) Escreva os valores das variáveis para cada instrução do programa abaixo. Qual a saída do programa? R: 21 8 e 8 21.
*/
#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int a, b, *p1, *p2; // a = #, b = #, *p1 = #, *p2 = #

    a = 4; // a atribui 4
    b = 3; // b atribui 3
    p1 = &a; // o ponteiro p1 aponta para o endereço de a (que aponta para 4)
    p2 = p1; // o ponteiro p2 também aponta para o endereço de a
    *p2 = *p1 + 3; // o conteúdo do ponteiro p2 é igual ao conteúdo do ponteiro p1 + 3 (igual a 7), ou seja, p1, p2 e a agora são 7
    b = b * (*p1); // b é igual a 3 * conteúdo do ponteiro p1, que agora é 7 (b é igual a 21)
    (*p2)++; // o conteúdo de p2 (e consequentemente p1 e a) incrementa em 1 unidade (fica 8)
    p1 = &b; // o ponteiro p1 aponta para o endereço de b (fica 21)

    printf("%d %d\n", *p1, *p2); // 21, 8
    printf("%d %d\n", a, b); // 8, 21
    return 0;
}