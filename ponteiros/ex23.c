/* 1) Implemente e simule a memória para o que se pede abaixo:
    f) Crie uma função que calcule o mínimo e o máximo de um vetor de inteiros e retorne os valores em duas variáveis diferentes
*/
// SIMULANDO A MEMÓRIA
#include <stdio.h>
#include <stdlib.h>

#define TAM 100

void calculaMaxMin (int *vet, int *MIN, int *MAX, int n) {
    *MIN = vet[0]; // o ponteiro de inteiro recebe por conteúdo o endereço de memória de vet[0], ou seja, o primeiro elemento, como flag criada para percorrer o vetor e setar o menor elemento
    *MAX = vet[0]; // é feito o mesmo para o ponteiro *MAX
    for (int i = 0; i < n; i++) {
        if (vet[i] <= *MIN) {
            *MIN = vet[i];
        }
        if (vet[i] >= *MAX) {
            *MAX = vet[i];
        }
    } // os ponteiros *MIN e *MAX percorrem o vetor elemento a elemento e analisam se encontraram o menor/maior elemento ao mesmo tempo, conforme a comparação é feita, sempre com o elemento atual e o elemento que é conteúdo do ponteiro, até o fim do vetor
}

int main (void) {
    int v[TAM], tam, max, min; // o vetor e as demais variáveis são alocadas estaticamente na memória Stack, os valores são escolhidos pelo usuário

    printf("Insira o tamanho do vetor (max. %d): ", TAM);
    scanf("%d", &tam);

    if (tam <= 0 || tam > TAM) {
        printf("Tamanho invalido! Deve estar entre 1 e %d.\n", TAM);
        return 1;
    }

    printf("Digite os valores do vetor:\n");
    for (int i = 0; i < tam; i++) {
        scanf("%d", &v[i]);
    }
    calculaMaxMin(v, &min, &max, tam); // max e min são alterados por referência
    printf("\n\t--------- RESULTADOS ----------");
    printf("\nMAXIMO: %d\nMINIMO: %d\n\nVETOR:\n", max, min);
    for (int i = 0; i < tam; i++) {
        printf("v[%d] = %d\n", i, v[i]);
    }
    return 0;
}