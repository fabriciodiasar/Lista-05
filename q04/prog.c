// Escreva um programa que dado um vetor X de inteiros, realize a seguinte normalização dos dados (min-max):

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define MX 100

void geraValores(int *, int);
void normalizacao(int *, int *, int, int);
void imprimirVetor(int *, int);

int main(){
  int x[TAM], x1[TAM], maior, menor;

  geraValores(x, TAM);

  for(int i = 0; *(x + i) != '\0'; i++){
    if ((i == 0) || *(x + i) < menor) menor = *(x + i);
    if ((i == 0) || *(x + i) > maior) maior = *(x + i);
  }

  normalizacao(x, x1, menor, maior);

  puts("\nVetor X:");
  imprimirVetor(x, TAM);

  printf("O menor valor é %d, e o maior é %d.\n\n", menor, maior);

  puts("Vetor X':");
  imprimirVetor(x1, TAM);

  return 0;
}

void geraValores(int *v, int t){
  srand(time(0));
  for(int i = 0; i < t; i++){
    *(v + i) = rand() % MX;
  }
}

void normalizacao(int *x, int *x1, int min, int max) {
  for(int i = 0; *(x + i) != '\0'; i++)
    *(x1 + i) = (*(x + i) - min) / (max - min);
}

void imprimirVetor(int *v, int k){
  for(int i = 0; i < k; i++)
    printf("%d ", *(v + i));

  puts("\n");
}