/* 2) Qual o problema do trecho de código abaixo? Corrija-o!*/
#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int i; // criado o inteiro i (contém lixo de memória)
    char *v; // criado o ponteiro de char v (contém lixo de memória)

    for (i = 0; i < 9999999; i++) {
        v = (char *) malloc (5000 * sizeof(char));
    } // ERRO: pelo malloc, a cada iteração do for está sendo gerado um bloco de memória na Heap de 5000 B, que perde sua referência assim que ocorre a próxima iteração, pois não é criado outro ponteiro para que receba mais um endereço base de um bloco da Heap, além de que está sem a liberação de memória correta, o que vai acumulando memória desnecessariamente (memory leak) e pode gerar o erro de segmentation fault
    return 0;
}
/* CORREÇÃO: alterar o for, incluindo a função que vai liberando a memória nas iterações

int main (void) {
    int i;
    char v;

    for (i = 0; i < 9999999; i++) {
        v = (char *) malloc (5000 * sizeof(char));
        free(v);
    }
    return 0;
*/