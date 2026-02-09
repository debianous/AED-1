/* 1) O que está sendo alocado em cada chamada de malloc? R: 
2) Como acessar os elementos da matriz usando ponteiros de ponteiros? R: 
3) Qual é a saída do programa? R: 
4) Por que é importante liberar a memória com free? R: 
*/
#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int **mat; // o ponteiro de ponteiro mat atribui lixo de memória
    mat = (int **)malloc(sizeof(int *) * 2); // o ponteiro de ponteiro mat atribui: 

    for (int i = 0; i < 2; i++) {
        mat[i] = (int *)malloc(sizeof(int) * 2);
    }

    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[1][0] = 3;
    mat[1][1] = 4;

    printf("%d\n", mat[1][0]);

    for (int i = 0; i < 2; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}