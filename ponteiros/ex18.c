/* 1) Implemente e simule a memória para o que se pede abaixo:
    a) Crie uma função que aloque um vetor de double e o retorne
*/
// SIMULANDO A MEMÓRIA
#include <stdio.h>
#include <stdlib.h>

#define TAM 100 // define o número máximo do tamanho do vetor

int main (void) {
    double v[TAM]; // cria o vetor estático com o tamanho máximo
    int tam;

    printf("Digite o tamanho do vetor (max. %d): ", TAM);
    scanf("%d", &tam); // armazena o tamanho no endereço da variável tam

    if (tam <= 0 || tam > TAM) {
        printf("Tamanho invalido! Deve estar entre 1 e %d.\n", TAM);
        return 1;
    }
    
    printf("Digite os valores do vetor:\n");
    for (int i = 0; i < tam; i++) {
        scanf("%lf", &v[i]); // cada double é alocado estaticamente na memória Stack, nos endereços de cada elemento do vetor
    }
    printf("\nVETOR ALOCADO:\n");
    for (int i = 0; i < tam; i++) {
        printf("v[%d] = %f\n", i, v[i]);
    }
    return 0;
}