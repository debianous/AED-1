/*1) Codifique uma função para:
    c) Adicionar um escalar a uma matriz (in place)
*/
#include <stdio.h>
#include <stdlib.h>

void adicionaEscalar (int **mat, int linha, int coluna, int escalar) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            mat[i][j] += escalar; // percorre a matriz elemento a elemento e adiciona o escalar ao conteúdo já passado para ele 
        }
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
    int **m = NULL, esc;
    const int lin = 2, col = 2;

    m = (int **) calloc(lin, sizeof(int *));
    for (int i = 0; i < lin; i++) {
        m[i] = (int *) calloc(col, sizeof(int));
    }

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            m[i][j] = (i + 4) * (j + 5);
        }
    } // inicializando valores diferentes para os elementos da matriz

    printf("ANTES DA FUNCAO 'AdicionaEscalar':\n");
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("m[%d][%d] = %d\n", i, j, m[i][j]);
        }
        puts("");
    } // para verificar a matriz antes da chamada da função
    
    printf("Escolha um escalar para adicionar a matriz:\n");
    scanf("%d", &esc);

    adicionaEscalar(m, lin, col, esc);
    printf("DEPOIS DA FUNCAO 'AdicionaEscalar':\n");
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("m[%d][%d] = %d\n", i, j, m[i][j]);
        }
        puts("");
    }
    desalocaMatriz(&m, lin); // desaloca corretamente a matriz por suas linhas e depois desaloca m, garantindo que não há gap de memória
    return 0;
}