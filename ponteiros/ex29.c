/*1) Codifique uma função para:
    b) Imprimir os elementos de uma matriz e seus endereços de memória
*/
#include <stdio.h>
#include <stdlib.h>

void imprimeMatriz (int **mat, int linha, int coluna) {
    printf("&m = %p, m = %p\n\n", &mat, mat);
    for (int i = 0; i < linha; i++) {
        printf("&m[%d] = %p, m[%d] = %p\n\n", i, &mat[i], i, mat[i]); // impressão dos parâmetros das linhas e seus endereços
        for (int j = 0; j < coluna; j++) {
            printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &mat[i][j], i, j, mat[i][j]); // impressão dos parâmetros dos elementos das colunas e seus endereços
        }
        puts("");
    }
}

void desalocaMatriz (int ***mat, int linha) {
    int **aux = *mat;
    
    for (int i = 0; i < linha; i++) {
        free(aux[i]);
    }
    free(aux);
    *mat = NULL;
}

int main (void) {
    int **m = NULL;
    const int lin = 5, col = 2;

    m = (int **) calloc(lin, sizeof(int *));
    for (int i = 0; i < lin; i++) {
        m[i] = (int *) calloc(col, sizeof(int));
    }
    imprimeMatriz(m, lin, col);
    desalocaMatriz(&m, lin); // desalocação correta e sem acúmulo de memória
    return 0;
}