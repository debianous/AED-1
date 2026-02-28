/* 1) Simule a memória, usando Heap e Stack, para o seguinte trecho de código: */
#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int n = 5; // n atribui 5
    int *v; // criado o ponteiro de inteiro v, na memória Stack (armazena o endereço de memória do elemento base)
    v = (int *) malloc(n * sizeof(int)); // v é alocado dinamicamente por malloc, na memória Heap, ou seja, guarda um bloco contíguo de memória (20 B) que possui 5 elementos (array), que inicialmente guardam lixos de memória; o malloc retorna sempre o endereço de memória do primeiro elemento desse bloco

    for (int i = 0; i < 5; i++) { // i é o índice do contador 
        v[i] = i; // o contador aloca os 5 elementos na memória Heap do vetor dinâmico v de acordo com seu índice, ou seja, v[5] = {0, 1, 2, 3, 4}
    }
    return 0;
}