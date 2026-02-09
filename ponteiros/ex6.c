/* 1) O que acontece com os valores de x e y após a chamada da função troca? R: x se torna 9, y se torna 7
2) Como o ponteiro permite modificar variáveis fora da função? R: utilizando endereços de memória, que podem ser realocados por parâmetros nas linhas de execução (passagem por referência), sem precisar alterar o conteúdo da variável diretamente (passagem por valor)
*/
#include <stdio.h>

void troca (int *a, int *b) {
    int temp = *a; // temp atribui o conteúdo de a, ou seja, preserva o conteúdo de a antes da troca
    *a = *b; // o conteúdo do ponteiro a é igual ao conteúdo do ponteiro b, ou seja, acontece a troca de a por b
    *b = temp; // o conteúdo do ponteiro b é igual a temp (que é o conteúdo de a), ou seja, acontece a troca de b por a
}

int main (void) {
    int x = 7, y = 9; // x atribui 7; y atribui 9
    int *px = &x; // o ponteiro px atribui o endereço de x
    int *py = &y; // o ponteiro py atribui o endereço de y

    troca(px, py); // x se torna 9, y se torna 7

    printf("x = %d, y = %d\n", x, y); // 9, 7
    return 0;
}