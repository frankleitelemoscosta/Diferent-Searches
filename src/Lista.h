#ifndef LISTA_H 
#define LISTA_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXTAM 10

typedef struct Item{
	int x;
  	int y;
}Item;

typedef struct Lista{
	Item vet[MAXTAM];
	int first;
	int last;
}Lista;


void FLVazia(Lista *l);
void LInsert(Lista *l, Item d);
void LRemove(Lista *l, Item d);
void Swap(Item *posicao_procurada, Item *posicao_sucessora);
void LImprime(Lista *l);

#endif

//end code


/*
 O ponteiro first alem de ser um checkpoint tambem desempenha a função de guardar um indice
a lista é um vetor estático onde se percorre usando first e last

*/
