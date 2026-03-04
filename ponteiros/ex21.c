/* 1) Implemente e simule a memória para o que se pede abaixo:
    d) Crie uma função que faça a cópia de um vetor: faça a versão com retorno da função
*/
// SIMULANDO A MEMÓRIA
#include <stdio.h>
#include <stdlib.h>

int* copiaVetor (int *ori, int n) {
    int *cop = (int *) malloc (n * sizeof(int));
    for (int i = 0; i < n; i++) {
        cop[i] = ori[i]; // cada valor do vetor cópia recebe o mesmo valor do vetor original, por referência
    }
    return cop; 
} // a função retorna um ponteiro de inteiro, que será a referência para o vetor que é cópia de v1, o vetor v2, alocado na memória Heap; no caso, são ocupados 20 B em um bloco contíguo de memória

void desalocaVetor (int **vetor) {
    int *aux = *vetor;
    free(aux);
    *vetor = NULL;
}

int main (void) {
    int *v1, *v2; // criados os ponteiros para inteiros correspondentes aos vetores, na memória Stack
    const int tam = 5;

    v1 = (int *) malloc (tam * sizeof(int)); // o vetor v1 é alocado dinamicamente na memória Heap, seus elementos inicialmente possuem lixo de memória (pelo malloc)
    printf("VETOR 1:\n");
    for (int i = 0; i < tam; i++) {
        printf("v[%d] = %d\n", i, v1[i]);
    }
    printf("\nVETOR 2:\n");
    v2 = copiaVetor(v1, tam); // v2 é alterado por referência, através da chamada do retorno da função
    for (int i = 0; i < tam; i++) {
        printf("v[%d] = %d\n", i, v2[i]);
    }
    desalocaVetor(&v1); // desaloca v1 corretamente para não ocorrer acúmulo de memória
    desalocaVetor(&v2); // também desaloca v2

    return 0;
}