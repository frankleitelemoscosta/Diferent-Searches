#ifndef LISTA_H 
#define LISTA_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXTAM 10

typedef struct ItemL{
	int x;
  	int y;
}ItemL;

typedef struct Lista{
	ItemL vet[MAXTAM];
	int first;
	int last;
}Lista;


void FLVazia(Lista *l);
void LInsert(Lista *l, ItemL d);
void LRemove(Lista *l, ItemL d);
void Swap(ItemL *posicao_procurada, ItemL *posicao_sucessora);
void LImprime(Lista *l);

#endif

//end code


/*
 O ponteiro first alem de ser um checkpoint tambem desempenha a função de guardar um indice
a lista é um vetor estático onde se percorre usando first e last

*/
