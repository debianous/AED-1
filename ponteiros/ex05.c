/*1) Analise o código abaixo. 
a) Qual o valor de x após cada linha de modificação? R: 10, 10, 10, 15, 30, 27, 27.
b) O que está acontecendo em **pp = **pp + 5? R: as variáveis x, p e pp são alteradas para 15.
c) Qual a saída final do programa? R: 27.
*/
#include <stdio.h>

int main (void) {
    int x = 10; // x atribui 10
    int *p = &x; // o ponteiro p aponta para o endereço de x
    int **pp = &p; // o ponteiro de ponteiro pp aponta para o endereço do ponteiro p, que é x (igual a 10)

    **pp = **pp + 5; // o ponteiro de ponteiro pp é igual ao ponteiro de ponteiro pp + 5 (x, p e pp agora são iguais a 15)
    *p = *p * 2; // o conteúdo de p é o conteúdo de p (que agora é 15) * 2 (x, p e pp agora são iguais a 30)
    x = x - 3; // x é igual a x (que agora é 30)- 3 (igual a 27)

    printf("%d\n", x); // 27
    return 0;
}
