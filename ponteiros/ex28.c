/*1) Codifique uma função para:
    a) Alocar uma matriz dinâmica
*/
#include <stdio.h>
#include <stdlib.h>

float** criaMatriz (int linha, int coluna) {
    float **mat = (float **) calloc(linha, sizeof(float *)); // aloca o "vetor das linhas" pelo ponteiro de ponteiro, usando calloc, ou seja, todos os elementos são inicializados com NULL
    if (mat == NULL) {
        printf("ERRO: Alocação incorreta.\n");
        return NULL;
    } // verifica se houve alocação nula de linha

    for (int i = 0; i < linha; i++) {
        mat[i] = (float *) calloc(coluna, sizeof(float)); // aloca o "vetor das colunas" para cada linha, usando calloc, ou seja, todos os elementos também são inicializados com NULL
        if (mat[i] == NULL) {
            printf ("ERRO: Alocacao incorreta.\n");
            return NULL;
        }
    } // verifica se houve alocação nula de coluna
    return mat; // a matriz é o retorno da função
}

int main (void) {
    float **m = NULL;
    const int lin = 3, col = 3;

    m = criaMatriz(lin, col);

    for (int i = 0; i < lin; i++) { // inicializa os valores da matriz
        for (int j = 0; j < col; j++) {
            m[i][j] = (i + 1) * (j + 1); // exemplo: produto das posições
        }
    }

    for (int i = 0; i < lin; i++) {
        printf("&m[%d] = %p; m[%d] = %p\n\n", i, (void*)&m[i], i, m[i]); // imprime os endereços de m e m[0][0]
        for (int j = 0; j < col; j++) {
            printf("&m[%d][%d] = %p, m[%d][%d] = %f\n", i, j, (void*)&m[i][j], i, j, m[i][j]); // imprime os endereços e os valores dos elementos da matriz
        }
        puts("");
    }

    for (int i = 0; i < lin; i++) {
        free(m[i]);
    }
    free(m);
    m = NULL; // desalocação correta da matriz
    return 0;
}