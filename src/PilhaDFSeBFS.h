#ifndef __PILHADFSEBFS_H
#define __PILHADFSEBFS_H

#include"matriz.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Item Item;
typedef struct Block Block;
typedef struct Pilha Pilha;

struct Item{
	int val;
};

struct Block{
	Item data;
	Block *prox;
};

struct Pilha{
	Block *base;
	Block *top;
};


void FPVazia(Pilha *p);
void Push(Pilha *p, Item d);
void Pop(Pilha *p, Item *d);
void PImprime(Pilha *p);

void CaminhamentoDFS(Matriz *M,signed short int *Ordem);
void Desimpilhando(Matriz *M,signed short int *Ordem,int *Linha,int *Coluna,signed short int *escolha );
void Reset();

#endif

//fim do código