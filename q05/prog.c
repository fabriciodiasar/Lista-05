/* Escreva um programa que some todos os elementos de um vetor de float alocado dinamicamente.
A quantidade de elementos devem ser fornecidas por linha de comando. 
Utilize a função rand() para alimentar o vetor com valores pseudo-aleatórios. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 100

void geraValores(float *, int);
void imprimirVetor(float *, int);

int main(int argc, char *argv[]){
  float *v = NULL;
  int tam;

  if(argc != 2){
    printf("Uso \n\t %s quantidade inicio máximo\n\n", argv[0]); 
    exit(1);
  }

  tam = atoi(argv[1]);
  
  v = (float *) malloc(tam * sizeof(float));

  if(!v) {
    puts("Sem memória!");
    exit(2);
  }

  geraValores(v, tam);

  puts("\nVetor float V:");
  imprimirVetor(v, tam);

  free(v);

  return 0;
}

void geraValores(float *v, int t){
  srand(time(0)); 
  
  for(int i = 0; i < t; i++){
    *(v + i) = rand() * MX * 100 / ((float) RAND_MAX / 100);

    *(v + i) = (*(v + i) < 0) ? *(v + i) * -1 : *(v + i);
  }
}

void imprimirVetor(float *v, int k){
  for(int i = 0; i < k; i++)
    printf("%.2f ", *(v + i));

  puts("\n");
}