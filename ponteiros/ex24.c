// ANÁLISE: MATRIZ ESTÁTICA BIDIMENSIONAL (2D)
#include <stdio.h>

int main (void) {
    const int lin = 2, col = 3;
    
    int m[lin][col] = {{0, 1, 2}, {3, 4, 5}}; // matriz de inteiros alocada estaticamente com valores inicializados

    printf("&m = %p, m = %p\n\n", &m, m); // verifica igualdade entre o endereço de m e o endereço do primeiro elemento de m (&m[0][0])
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]);
        }
        puts("");
    } // demonstra que os elementos são alocados sequencialmente na estrutura linha-coluna, respeitando a memória exigida pela tipagem da matriz
    return 0;
}