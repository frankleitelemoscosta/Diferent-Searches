#ifndef FILA_H 
#define FILA_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"matriz.h"

typedef struct ItemF ItemF;
typedef struct BlockF BlockF;
typedef struct Fila Fila;

struct ItemF{

	int Linha;
	int Coluna;

};

struct BlockF{

	ItemF data;
	BlockF *prox;

};

struct Fila{

	BlockF *first;
	BlockF *last;

};


void FFVazia(Fila *f);
bool isVazia(Fila *f);
void Enfileira(Fila *f, ItemF d);
void Desenfileira(Fila *f, ItemF *d);
void FImprime(Fila *f);

void CaminhamentoBFS(Matriz *M,signed short int *Ordem,Fila *F);

#endif