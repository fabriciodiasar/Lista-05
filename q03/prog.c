// Modifique a questão anterior criando uma função que armazena em um vetor os endereços do menor e do maior elemento do vetor.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 20

void preencherVetor(int *, int, int);
void enderecoVetor(int *, int);
void menorMaior(int *, int *, int);
void vetor(int *, int *, int*);

int main(int argc, char *argv[]){
  int *v = NULL, *p = NULL, k;

  if(argc != 2){
    printf("Uso> \n\t%s qtdLin qtdCol\n\n", argv[0]);
	  exit(1);
  }

  k = atoi(argv[1]);

  v = malloc(k * sizeof(int));
  p = malloc(2 * sizeof(int));

  if(!v || !p){
    puts("\nSem memória!");
    exit(2);
  }

  srand(time(0));
  preencherVetor(v, k, MX);

  puts("\nEndereço dos valores:");
  enderecoVetor(v, k);

  menorMaior(v, p, k);
  
  puts("\nVetor com os endereços:");
  for(int i = 0; i < 2; i++)
    printf("p[%d] = %x\n", i, *(p + i));
  puts("");

  free(v);
  free(p);
  
  return 0;
}

void preencherVetor (int *p, int t, int mx) {
  for (int i = 0; i < t; i++) {
    *(p + i) = rand() % mx;  
  }
}

void enderecoVetor (int *v, int tam) {
  for (int i = 0; i < tam; i++) 
    printf("[%p] = %d\n", (v + i), *(v + i));
}

void menorMaior(int *v, int *p, int k){
  int *menor = NULL, *maior = NULL;
  
  for(int i = 0; i < k; i++){
    if((i == 0) || (*(v + i) < *menor)) menor = v + i;
    if((i == 0) || (*(v + i) > *maior)) maior = v + i;
  }

  puts("\nEndereço do menor e maior valor:");
  printf("[%p] = %d\n", menor, *menor);
  printf("[%p] = %d\n", maior, *maior);

  vetor(menor, maior, p);
}

void vetor(int *menor, int *maior, int *p){
  *(p + 0) = (unsigned long) menor;
  *(p + 1) = (unsigned long) maior;
}