/* 1) PROGRAMA COM VETORES ESTÁTICOS
a) Crie uma função que recebe o ponteiro de um vetor e seu tamanho e imprime os elementos do vetor
b) Crie uma função que recebe o ponteiro de um vetor via colchetes [] e seu tamanho e imprime os elementos do vetor
c) Imprima os endereços de memória e valores do vetor na main e dentro de cada função

2) AGORA FAÇA O MESMO PROGRAMA PARA VETORES DINÂMICOS
*/
#include <stdio.h>
#include <stdlib.h>

void somaVetorEscalar (int v[], int n, int escalar) { // o escalar pode ser qualquer int
    for (int i = 0; i < n; i++) {
        v[i] += escalar;
    }
}

void imprimeVetor (const int *v, int n) { // v[] e *v trazem sempre o endereço base
    for (int i = 0; i < n; i++) {
        printf("&v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);
    }
    printf("\n");
}

void desalocaVetor (int **v) {
    int *aux = *v;
    free(aux);
    *v = NULL;
}

int main (void) {
    puts("### VETOR ESTATICO");
    int vStack[5] = {0, 10, 20, 30, 40};
    imprimeVetor(vStack, 5);
    somaVetorEscalar(vStack, 5, 9);
    imprimeVetor(vStack, 5);

    puts("### VETOR DINAMICO COM CALLOC");
    int *vHeap = (int *) calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++) {
        vHeap[i] = i * 100; // se diferencia dos valores do vetor estático
    }

    imprimeVetor(vHeap, 5);
    somaVetorEscalar(vHeap, 5, 9);
    imprimeVetor(vHeap, 5);
    // desalocando o vetor dinâmico
    puts("==> ANTES DA FUNCAO DESALOCA");
    printf("&vHeap = %p, vHeap = %p\n", &vHeap, vHeap);
    desalocaVetor(&vHeap);
    puts("==> DEPOIS DA FUNCAO DESALOCA");
    printf("&vHeap = %p, vHeap = %p\n", &vHeap, vHeap);

    return 0;
}