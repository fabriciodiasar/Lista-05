// Escreva um programa que receba dois valores por linha de execucao e realize a soma ou multiplicacão, conforme um código de operação também recebido por linha de execução.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 30

int main (int argc, char *argv[]) {
  int *a = NULL, *b = NULL, resultado;
  char opcao[TAM];
  
  *a = atoi(argv[1]);
  *b = atoi(argv[2]);

  strcpy(opcao, argv[3]);

  if (!strcmp(opcao, "soma"))
    resultado = *a + *b;
  else if (!strcmp(opcao, "multiplicação"))
    resultado = *a * *b;
  else {
    puts("\nOperação inválida!\n");
    exit(1);
  }
    
  printf("\nO resultado é %d.\n\n", resultado);

  return 0;
}