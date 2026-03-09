/* 1) Implemente e simule a memória para o que se pede abaixo:
    d) Crie uma função que faça a cópia de um vetor: faça a versão com retorno por referência
*/
// SIMULANDO A MEMÓRIA
#include <stdio.h>
#include <stdlib.h>

void copiaVetor (float *v, int n, float **dest) {
    *dest = (float *) malloc (n * sizeof(float));
    for (int i = 0; i < n; i++) {
        (*dest)[i] = v[i]; // o conteúdo do elemento do vetor que está no ponteiro recebe o mesmo elemento do vetor original
    }
} // v2 é alterado por referência, através da passagem por referência de seu endereço ao ponteiro de ponteiro, o que garante a alteração de v2 automaticamente sem precisar do retorno da função

void desalocaVetor (float **vetor) {
    float *aux = *vetor;
    free(aux);
    *vetor = NULL;
}

int main (void) {
    float *v1, *v2;
    const int tam = 8;

    v1 = (float *) malloc (tam * sizeof(float)); // v1 é alocado dinamicamente na memória Heap, gerando um espaço de 32 B de bloco contíguo de memória, e, pelo malloc, inicialmente todos os elementos possuem lixo de memória
    printf("VETOR 1:\n");
    for (int i = 0; i < tam; i++) {
        printf("v[%d] = %f\n", i, v1[i]);
    }
    printf("\nVETOR 2:\n");
    copiaVetor(v1, tam, &v2); // não é preciso passar a função para v2, pois ele já é alterado durante a execução dessa função
    for (int i = 0; i < tam; i++) {
        printf("v2[%d] = %f\n", i, v2[i]);
    }
    desalocaVetor(&v1); // vetor v1 é desalocado corretamente, sem acúmulo de memória
    desalocaVetor(&v2); // v2 também é desalocado
    return 0;
}