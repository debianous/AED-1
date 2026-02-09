// ANÁLISE: PASSAGEM POR REFERÊNCIA
#include <stdio.h>

void dobraValor (int *ptr) {
  *ptr = *ptr * 2; // multiplica o conteúdo apontado pelo ponteiro
}

int main (void) {
  int numero = 5;
  printf("Valor original: %d\n", numero);
  
  dobraValor(&numero); // passa o endereço da variável 'numero' para a função 'dobraValor'

  printf("Valor dobrado: %d\n", numero); // o valor de 'numero' foi modificado
  return 0;
}