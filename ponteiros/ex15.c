/* 2) Simule a memória, usando Heap e Stack, para o seguinte trecho de código: */
#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int v1[5] = {0, 1, 2, 3, 4}; // criado um vetor estático com 5 elementos
    int *v2, *p; // criado o ponteiro v2 e o ponteiro p, ambos na memória Stack, e possuem lixos de memória

    p = v1; // o ponteiro p recebe o endereço de memória base do vetor v1 
    p[3] = p[4] = 10; // altera o conteúdo do vetor v por meio do ponteiro p (pela aritmética de ponteiros, p[3] == *(p + 3)), portanto, o vetor fica v1[5] = {0, 1, 2, 10, 10}

    v2 = (int *) malloc(5 * sizeof(int)); // o ponteiro v2 é alocado dinamicamente por malloc, na memória Heap, ou seja, reserva um bloco contíguo de memória (20 B) para os 5 elementos de vetor, inicializados com lixos de memória (por ser malloc)
    for (int i = 0; i < 5; i++) {
        v2[i] = v1[i];
    } // iguala os elementos do vetor v2 aos do vetor v1
    free(v2); // faz a liberação de memória do ponteiro v2
    v2 = NULL; // v2 armazena null para evitar erros inesperados (boa prática)
    return 0;
}