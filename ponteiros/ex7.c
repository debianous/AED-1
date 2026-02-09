// ANÁLISE: PASSAGEM POR VALOR
#include <stdio.h>

void dobrarValor (int numero) {
  numero = numero * 2;
  printf("Dentro da função: %d\n", numero); // imprime o valor dobrado
}

int main (void) {
  int n = 10;
  printf("Antes da função: %d\n", n); // imprime 10
  dobrarValor(n);
  printf("Depois da função: %d\n", n); // imprime 10, não 20
  return 0;
}