/* 1) Qual o problema do trecho de código abaixo? Corrija-o!*/
#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int v1[5] = {0, 1, 2, 3, 4, 9}; // criado o vetor estático v1, com 6 elementos
    int *v2; // criado o ponteiro de inteiro v2 (contém lixo de memória)

    v2 = (int *) malloc(6 * sizeof(int)); // o ponteiro v2 é alocado dinamicamente por malloc, criando um bloco contíguo de memória (24 B) para os 6 elementos do vetor dinâmico
    v2 = v1; // indica que o ponteiro v2 atribui o endereço de memória base do vetor v1
    free(v2); // 1º ERRO: tentativa de liberar a memória do ponteiro v2, porém, a função "free" é feita para memórias Heap, e, como v2 está apontando para o vetor estático v1, há erro de execução e o programa é abortado; 2º ERRO: não houve a liberação correta da memória em Heap criada pelo malloc e v2 não aponta mais para essa região, ou seja, a memória foi perdida e ainda está ocupada
    return 0;
}
/* CORREÇÃO: excluir as linhas 10 e 11, criar a função de liberação de memória de v2

void desalocaVetor (int **v) {
    int *aux = *v;
    free(aux);
    *v = NULL;
}

int main (void) {
    int v1[5] = {0, 1, 2, 3, 4, 9};
    int *v2;

    v2 = (int *) malloc(6 * sizeof(int));
    desalocaVetor(&v2);
    return 0;
*/