/* Escreva um programa que gere dois vetores (X e Y ) com números pseudoaleatórios no intervalo [0,N − 1]. 
  Crie uma matriz M com dimensões NxN que armazene as coocorrências dos elementos de X e Y. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetor (int *, int, int);
void imprimirVetor (int *, int);
void imprimirMatriz (int *, int, int);
void MatrizOcorrencia(int *, int *, int *, int);

int main(int argc, char *argv[]){
  int *x = NULL, *y = NULL, *m = NULL, n;

  if(argc != 2){
    printf("Uso> \n\t%s qtdLin qtdCol\n\n", argv[0]);
	  exit(1);
  }

  n = atoi(argv[1]);

  x = malloc(2 * n * sizeof(int));
  y = malloc(2 * n * sizeof(int));
  m = malloc(n * n * sizeof(int));

  if(!x || !y || !m){
    puts("\nSem memória!");
    exit(2);
  }
  
  srand(time(0));
  preencherVetor(x, 2 * n, n);
  preencherVetor(y, 2 * n, n);

  puts("\nVetor X:");
  imprimirVetor(x, 2 * n);

  puts("\n\nVetor Y:");
  imprimirVetor(y, 2 * n);

  MatrizOcorrencia(x, y, m, n);

  puts("\n\nMatriz:");
  imprimirMatriz(m, n, n);

  free(x);
  free(y);
  free(m);

  return 0;
}

void preencherVetor (int *p, int t, int mx) {
  for (int i = 0; i < t; i++) {
    *(p + i) = rand() % mx;  
  }
}

void imprimirVetor (int *v, int t) {
  for (int i = 0; i < t; i++) {
    printf("%d ", *(v + i));
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

void MatrizOcorrencia(int *x, int *y, int *m, int n){
  int z;
  for(int i = 0; i < 2 * n; i++){
    z = n * (*(y + i)) + *(x + i);
    *(m + z) += 1; 
  }
}
