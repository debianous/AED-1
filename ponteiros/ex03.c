// ANÁLISE: PONTEIRO DE PONTEIRO
#include <stdio.h>

int main (void) {
    int a = 10;
    int *p1 = &a;
    int **p2 = &p1;
    **p2 = 99;
    printf("%d", a);
    return 0;
}