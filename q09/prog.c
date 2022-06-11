// Escreva um programa em C que informe se o somatório da diagonal principal de matriz N x N gerada é par ou ímpar.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 20

void preencherVetor(int *, int, int);
void imprimirMatriz(int *, int, int);
int somaDiagonalPrincipal(int *, int, int);

int main(int argc, char *argv[]) {
  int *m = NULL, n;

  if(argc != 2){
    printf("Uso> \n\t%s qtdLin qtdCol\n\n", argv[0]);
	  exit(1);
  }

  n = atoi(argv[1]);
  
  m = malloc(n * n * sizeof(int));

  if(!m){
    puts("\nSem memória!");
    exit(2);
  }

  srand(time(0));
  preencherVetor(m, n * n, MX);

  puts("\nMatriz:");
  imprimirMatriz(m, n, n);

  if(!(somaDiagonalPrincipal(m, n, n) % 2))
    printf("\nA soma da diagonal principal da matriz é par!\n\n");
  else
    printf("\nA soma da diagonal principal da matriz é ímpar!\n\n");

  free(m);

  return 0;
}

void preencherVetor (int *p, int t, int max) {
  for (int i = 0; i < t; i++) {
    *(p + i) = rand() % max;  
  }
}

void imprimirMatriz (int *p, int lin, int col) {
  puts("");
  
  for(int k = 0; k < lin * col; k++) {
    printf("%d\t", *(p + k));

    if(((k + 1) % col) == 0) printf("\n");
  }
  printf("\n");
}

int somaDiagonalPrincipal(int *v, int lin, int col){
  int somatorio = 0;
  
  for(int i = 0; i < lin * col; i++){
    if(i == 0) 
      somatorio += *v;
    else
      somatorio += *(v + lin * i + i);
  }

  return somatorio;
}