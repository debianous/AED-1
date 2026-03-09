// ANÁLISE: MATRIZ DINÂMICA BIDIMENSIONAL (2D)
#include <stdio.h>
#include <stdlib.h>

void desalocaMatriz2D (int **mat, int linha) {
    for (int i = 0; i < linha; i++) {
        free(mat[i]);
    }
    free(mat);
    mat = NULL;
}

int main (void) {
    const int lin = 2, col = 3;
    int **m = NULL;

    m = (int **) calloc(lin, sizeof(int*)); // a alocação da matriz é feita sempre primeiro para as linhas
    for (int i = 0; i < lin; i++) {
        m[i] = (int *) calloc(col, sizeof(int)); // dentro do loop, a alocação das colunas é feita
    }
    printf("&m = %p, m = %p\n\n", &m, m); // verifica a diferença entre os endereços da variável m e &m[0][0]
    
    int cont = 0;
    for (int i = 0; i < lin; i++) {
        printf("&m[%d] = %p, m[%d] = %p\n\n", i, &m[i], i, m[i]);
        for (int j = 0; j < col; j++) {
            m[i][j] = cont++;
            printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]);
        }
        puts("");
    }
    desalocaMatriz2D(m, lin); // desaloca a matriz corretamente, pois não deixa memória acumulada na Heap, limpando as linhas e depois redirecionando o ponteiro da matriz m para NULL
    return 0;
}