// ANÁLISE: MATRIZ ESTÁTICA TRIDIMENSIONAL (3D)
#include <stdio.h>
#include <stdlib.h>

int main (void) {
    const int fat = 2, lin = 2, col = 3;

    // criada uma matriz na memória Stack de 2 fatias de profundidade, 2 linhas, 3 colunas
    int m[fat][lin][col] = {{{0, 1, 2}, {3, 4, 5}}, // fatia [0], linhas [0] e [1]
                            {{6, 7, 8}, {9, 10, 11}}}; // fatia [1], linhas [0] e [1]
    
    printf("&m = %p, m = %p\n\n", &m, m);
    for (int k = 0; k < fat; k++) { // para cada fatia
        for (int i = 0; i < lin; i++) { // para cada linha
            for (int j = 0; j < col; j++) { // para cada coluna
                printf("&m[%d][%d][%d] = %p, m[%d][%d][%d] = %p", fat, lin, col, &m[k][i][j], fat, lin, col, m[k][i][j]);
            }
        }
    }
    return 0;
}