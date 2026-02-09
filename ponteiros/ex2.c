// ANÁLISE: MANIPULANDO PONTEIROS
#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int n = 10;
    int *p1 = NULL;
    int *p2;

    printf("&n = %p, n = %d\n", &n, n);
    printf("&p1 = %p, p1 = %p\n", &p1, p1);
    printf("&p2 = %p, p2 = %p\n", &p2, p2);
    
    p1 = &n;
    p2 = p1;
    *p2 = 4;

    printf("\n&n = %p, n = %d\n", &n, n);
    printf("&p1 = %p, p1 = %p, *p1 = %d\n", &p1, p1, *p1);
    printf("&p2 = %p, p2 = %p, *p2 = %d\n", &p2, p2, *p2);
    return 0;
}