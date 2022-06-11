// Escreva um programa em C que binarize os elementos da matriz M gerada aleatoriamente e com dimensões obtidas em tempo de execução.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 20

void preencherVetor(int *, int, int);
void imprimirMatriz(int *, int, int);
void binarizacao(int *, int *, int, int);

int main (){
  int *m = NULL, *s = NULL, lin, col, t;

  puts("\nQual o número de linhas?");
  scanf("%d", &lin);

  puts("\nQual o número de colunas?");
  scanf("%d", &col);

  m = malloc(lin * col * sizeof(int));
  s = malloc(lin * col * sizeof(int));

  if(!m || !s){
    puts("\nSem memória");
    exit(1);
  }

  puts("\nMatriz M:");
  preencherVetor(m, lin * col, MX);
  imprimirMatriz(m, lin, col);

  puts("\nQual o valor de t?");
  scanf("%d", &t);

  binarizacao(m, s, t, lin * col);

  puts("\nMatriz S:");
  imprimirMatriz(s, lin, col);
  
  free(m);
  free(s);
  
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

void binarizacao(int *m, int *s, int t, int tam){
  for(int i = 0; i < tam; i++)
    *(s + i) = (*(m + i) > t) ? 1 : 0;
}