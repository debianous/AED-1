/* 1) Mostre todos os passos (teste de mesa) do programa abaixo e identifique o que é impresso pelo programa.
*/
#include <stdio.h>

void func (int *px, int *py) { /* *px = &x, *py = &y */
    px = py; /* endereço de *px fica igual ao endereço de py (aponta para y) */
    *py = (*py) * (*px); /* *py = 9 * 9 = 81 */
    *px = *px + 2; /* *px = 81 + 2 = 83 */
}

int main (void) {
    int x, y; // x = #, y = #
    scanf("%d", &x); // recebe x = 2
    scanf("%d", &y); // recebe y = 9
    func(&x, &y); // chama a função, passando por referência os endereços de x e y
    printf("x = %d, y = %d\n", x, y); // x = 2, y = 83
    return 0;
}