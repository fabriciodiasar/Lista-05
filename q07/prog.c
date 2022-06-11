// Calcule o erro médio quadrático entre dois vetores A e B de dimensão N gerados aleatoriamente. Pesquise a equação.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MX 20

void geraValores(int *, int);
void imprimirVetor(int *, int);
void imprimirVetorF(float *, int);
void erroMedioA(int *, int *, int);
void erroMedioQ(float *, float *, int);

int main(){
  int *a = NULL, *b = NULL, n;

  puts("\nQual a dimensão dos vetores?");
  scanf("%d", &n);

  a = malloc(n * sizeof(int));
  b = malloc(n * sizeof(int));

  if(!a || !b){
    puts("\nSem memória");
    exit(1);
  }

  srand(time(0));
  geraValores(a, n);
  geraValores(b, n);
  
  puts("\nVetor A:");
  imprimirVetor(a, n);

  puts("\nVetor B:");
  imprimirVetor(b, n);

  erroMedioA(a, b, n);
 
  free(a);
  free(b);

  return 0;
}

void geraValores(int *v, int t){
  for(int i = 0; i < t; i++)
    *(v + i) = rand() % MX;
}

void imprimirVetor(int *v, int k){
  for(int i = 0; i < k; i++)
    printf("%d ", *(v + i));

  puts("");
}

void imprimirVetorF(float *v, int k){
  for(int i = 0; i < k; i++)
    printf("%.2f ", *(v + i));

  puts("");
}

void erroMedioA(int *a, int *b, int tam){
  float mediaA, mediaB;
  int somatorio = 0;
  
  for(int i = 0; i < tam; i++)
    somatorio += *(a + i);

  mediaA = (float) somatorio / tam;

  somatorio = 0;

  for(int i = 0; i < tam; i++)
    somatorio += *(b + i);

  mediaB = (float) somatorio / tam;

  float *r = NULL, *s = NULL;

  r = malloc(tam * sizeof(float));
  s = malloc(tam * sizeof(float));

  for(int i = 0; i < tam; i++){
    *(r + i) = mediaA - *(a + i);
    *(s + i) = mediaB - *(b + i);
  }

  for(int i = 0; i < tam; i++){
    if (*(r + i) < 0) *(r + i) *= -1;
    if (*(s + i) < 0) *(s + i) *= -1;
  }

  puts("\n======= Erro Médio Absoluto =======");

  puts("\nVetor A:");
  imprimirVetorF(r, tam);

  puts("\nVetor B:");
  imprimirVetorF(s, tam);

  erroMedioQ(r, s, tam);

  free(r);
  free(s);
}

void erroMedioQ(float *r, float *s, int tam) {
  float *aQ = NULL, *bQ = NULL;

  aQ = malloc(tam * sizeof(float));
  bQ = malloc(tam * sizeof(float));

  for(int i = 0; i < tam; i++) {
    *(aQ + i) = pow(*(r + i), 2);
    *(bQ + i) = pow(*(s + i), 2);
  }

  puts("\n======= Erro Médio Quadrático =======");

  puts("\nVetor A:");
  imprimirVetorF(aQ, tam);

  puts("\nVetor B:");
  imprimirVetorF(bQ, tam);

  free(aQ);
  free(bQ);
}