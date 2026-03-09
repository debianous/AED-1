// ANÁLISE: MATRIZ DINÂMICA TRIDIMENSIONAL (3D)
#include <stdio.h>
#include <stdlib.h>

void desalocaMatriz3D (int ***mat, int fatia, int linha) {
    if (*mat == NULL) return;

    for (int k = 0; k < fatia; k++) {
        for (int i = 0; i < linha; i++) {
            free(mat[k][i]);
        }
        free(mat[k]);
    }
    free(mat);
    mat = NULL;
}

int main (void) {
    const int fat = 2, lin = 2, col = 3;
    int ***m = NULL;

    m = (int ***) calloc(fat, sizeof(int **)); // criada uma matriz na memória Heap de 2 fatias de profundidade, 2 linhas, 3 colunas

    for (int k = 0; k < fat; k++) { // para cada fatia
        m[k] = (int **) calloc(lin, sizeof(int *)); // aloca linhas
        for (int i = 0; i < lin; i++) { // para cada linha
            m[k][i] = (int *) calloc(col, sizeof(int)); // aloca colunas
        }
    }
    printf("&m = %p, m = %p\n\n", &m, m);

    int cont = 0;
    for (int k = 0; k < fat; k++) { // para cada fatia
        printf("&m[%d] = %p, m[%d] = %p\n\n", k, &m[k], k, m[k]);
        for (int i = 0; i < lin; i++) { // para cada linha
            printf("&m[%d][%d] = %p, m[%d][%d] = %p\n\n", k, i, &m[k][i], k, i, m[k][i]);
            for (int j = 0; j < col; j++) { // para cada coluna
                m[k][i][j] = cont++;
                printf("&m[%d][%d][%d] = %p, m[%d][%d][%d] = %d\n", k, i, j, &m[k][i][j], k, i, j, m[k][i][j]);
            }
            puts("");
        }
        puts("");
    }
    desalocaMatriz3D(m, fat, lin); // desaloca a matriz com sucesso, sem memória acumulada, liberando as linhas de cada fatia, por sua vez
    return 0;
}