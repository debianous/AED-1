/* 1) Implemente e simule a memória para o que se pede abaixo:
    c) Crie uma função que desaloque um dado vetor, "setando-o" como NULL após a desalocação
*/
// SIMULANDO A MEMÓRIA
#include <stdio.h>
#include <stdlib.h>

void desalocaVetor (float **vetor) {
    float *aux = *vetor;
    free(aux);
    *vetor = NULL;
}

int main (void) {
    float *v; // criado o ponteiro de float v
    const int tam = 4; 

    v = (float *) malloc (tam * sizeof(float)); // v armazena o endereço base de memória do bloco contíguo de memória para o vetor na Heap, por malloc, então seus elementos contêm lixo de memória
    printf("\nVETOR ALOCADO: %p\n", (void*)v); // mostra o endereço base que v armazena
    printf("VETOR:\n");
    for (int i = 0; i < tam; i++) {
        printf("v[%d] = %f\n", i, v[i]);
    }
    desalocaVetor(&v); // desaloca o vetor corretamente, por referência
    printf("\nVETOR DESALOCADO: %p\n", (void*)v); // mostra que o vetor foi desalocado e está NULL
    return 0;
}