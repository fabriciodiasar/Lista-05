// Escreva um programa em C que apresente a média, a mediana e a moda de um vetor de inteiros gerados aleatoriamente em tempo de execução.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 20

void geraValores(int *, int);
void imprimirVetor(int *, int);
void ordenacao(int *, int);
void media(int *, int);
void mediana(int *, int);
void moda(int *, int);

int main(){
  int *v = NULL, tam;
  
  puts("\nQual o tamanho do vetor?");
  scanf("%d", &tam);

  v = malloc(tam * sizeof(int));

  if(!v){
    puts("\nSem memória");
    exit(1);
  }

  geraValores(v, tam);
  ordenacao(v, tam);

  puts("\nVetor:");
  imprimirVetor(v, tam);

  puts("\n\n============== Média ==============");
  media(v, tam);

  puts("\n\n============== Mediana ============");
  mediana(v, tam);

  puts("\n\n============== Moda ================");
  moda(v, tam);

  puts("");

  free(v);
  
  return 0;
}

void geraValores(int *v, int t){
  srand(time(0));
  for(int i = 0; i < t; i++){
    *(v + i) = rand() % MX;
  }
}

void imprimirVetor(int *v, int k){
  for(int i = 0; i < k; i++)
    printf("%d ", *(v + i));
}

void ordenacao(int *v, int tam){
  for (int i = 0; i < tam; i++)
    for (int j= 0; j < tam - 1 ;j++) 
      if (*(v + j) > *(v + j + 1)) {
        *(v + j) = *(v + j) ^ *(v + j + 1);
        *(v + j + 1) = *(v + j) ^ *(v + j + 1);
        *(v + j) = *(v + j) ^ *(v + j + 1);
      }
}

void media(int *v, int tam) {
  int somatorio = 0;

  for(int i = 0; i < tam; i++)
    somatorio += *(v + i);

  float media = (float) somatorio / tam;

  printf("A média dos valores do vetor é %.2f.", media);
}

void mediana(int *v, int tam){
  if(!(tam % 2)) {
    printf("A mediana é = %.2f.", (float) ((*(v + tam / 2) + *(v + tam / 2 - 1))) / 2);
  } else {
    printf("A mediana é %d.", *(v + (tam - 1) / 2));
  }
}

void moda(int *v, int tam) {
  int m = 0, countAtual, countModa = 0;
  
  for(int i = 0; i < tam; i++){
    countAtual = 0;
    
    for(int j = 0; j < tam; j++)
      if (*(v + j) == *(v + i) && (i != j)) countAtual++;

    if ((countAtual > countModa) && (countAtual != 0)){
      m = *(v + i);
      countModa = countAtual;
    }
  }

  if (countModa == 0)
    puts("Não existe moda entre os valores desse vetor.\n");
  else
    printf("A moda é %d.\n", m);
}