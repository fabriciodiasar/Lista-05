// Escreva um programa em C que informe o endereço do menor elemento de um vetor de inteiros gerado. A quantidade de elementos desse array deve ser fornecido por linha de comando.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 20

void enderecoVetor(int *, int);
void preencherVetor (int *, int, int);

int main(int argc, char *argv[]){
  int *v = NULL, *menor = NULL, k;

  if(argc != 2){
    printf("Uso> \n\t%s qtdLin qtdCol\n\n", argv[0]);
	  exit(1);
  }

  k = atoi(argv[1]);

  v = malloc(k * sizeof(int));

  if(!v){
    puts("\nSem memória!");
    exit(2);
  }

  srand(time(0));
  preencherVetor(v, k, MX);

  puts("\nEndereço dos valores:");
  enderecoVetor(v, k);
  
  for(int i = 0; i < k; i++)
    if ((i == 0) || (*(v + i) < *menor)) menor = (v + i);

  puts("\nEndereço do menor valor:");
  printf("[%p] = %d\n\n", menor, *menor);

  free(v);
  
  return 0;
}

void preencherVetor (int *p, int t, int mx) {
  for (int i = 0; i < t; i++) {
    *(p + i) = rand() % mx;  
  }
}

void enderecoVetor(int *v, int k){
  for(int i = 0; i < k; i++) 
    printf("[%p] = %d\n", (v + i), *(v + i));
}
