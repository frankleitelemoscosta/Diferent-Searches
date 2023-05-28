#ifndef __PILHADFSEBFS_H
#define __PILHADFSEBFS_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Item Item;
typedef struct Block Block;
typedef struct Pilha Pilha;

struct Item{
	int Linha;
	int Coluna;
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
int Tamanho(Pilha *P);


#endif

//fim do código