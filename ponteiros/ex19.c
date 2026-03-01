/* 1) Implemente e simule a memória para o que se pede abaixo:
    b) Crie uma função que aloque um vetor de double, retornando-o por referência
*/
// SIMULANDO A MEMÓRIA
#include <stdio.h>
#include <stdlib.h>

void desalocaVetor (double **v) {
    double *aux = *v;
    free(aux);
    *v = NULL;
}

int main (void) {
    double *v; // criado o ponteiro de double v
    const int tam = 7;

    v = (double *) malloc (tam * sizeof(double)); // o ponteiro v guarda o endereço base de memória desse bloco contíguo criado por malloc, de acordo com o tamanho definido em tam; cada elemento possui lixo de memória
    for (int i = 0; i < tam; i++) {
        printf("v[%d] = %lf\n", i, v[i]);
    }
    desalocaVetor(&v); // o bloco de memória em Heap é desalocado corretamente, por referência
    return 0;
}