/*1) Codifique uma função para:
    d) Desalocar uma matriz, atribuindo valor NULL ao seu ponteiro
*/
#include <stdio.h>
#include <stdlib.h>

void desalocaMatriz (int ***mat, int linha) {
    int **aux = *mat;
    
    for (int i = 0; i < linha; i++) {
        free(aux[i]);
    }
    free(aux);
    *mat = NULL;
} // desaloca a matriz por referência, primeiro liberando as linhas, para depois liberar a variável da matriz e setar seu ponteiro para NULL

int main (void) {
    int **m = NULL;
    const int lin = 3, col = 6;

    m = (int **) calloc(lin, sizeof(int *));
    if (m == NULL) {
        printf ("ERRO: Alocacao incorreta.\n");
        return -1;
    } // verificação para erro de falta de alocação
    for (int i = 0; i < lin; i++) {
        m[i] = (int *) calloc(col, sizeof(int));
        if (m[i] == NULL) {
            printf ("ERRO: Alocacao incorreta.\n");
            return -1;
        }
    } // mesma verificação
    desalocaMatriz(&m, lin);
    printf("A variavel m aponta para NULL? %d\n", m == NULL);
    return 0;
}