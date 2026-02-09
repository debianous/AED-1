// ANÁLISE: ALOCAÇÃO ESTÁTICA E DINÂMICA
#include <stdio.h>
#include <stdlib.h> // contém NULL, calloc, malloc, free, etc.

int main (void) {
    // alocação de um vetor estático na memória Stack
    int vStack[5] = {0, 10, 20, 30, 40};

    puts("### VETOR ESTATICO");
    for (int i = 0; i < 5; i++) {
        printf("&vStack[%d] = %p, vStack[%d] = %d\n", i, &vStack[i], i, vStack[i]);
    }
    puts("\n");

    // alocação de um vetor dinâmico na memória Heap, usando malloc
    puts("### VETOR DINAMICO COM MALLOC");
    int* vMalloc = (int *) malloc(5 * sizeof(int)); // todos os elementos possuem lixo de memória

    for (int i = 0; i < 5; i++) {
        printf("&vMalloc[%d] = %p, vMalloc[%d] = %d\n", i, &vMalloc[i], i, vMalloc[i]);
    }
    puts("\n");

    // alocação de um vetor dinâmico na memória Heap, usando calloc
    puts("### VETOR DINAMICO COM CALLOC");
    int *vCalloc = (int *) calloc(5, sizeof(int)); // todos os elementos possuem NULL

    for (int i = 0; i < 5; i++) {
        printf("&vCalloc[%d] = %p, vCalloc[%d] = %d\n", i, &vCalloc[i], i, vCalloc[i]);
    }
    puts("\n");

    return 0;
}