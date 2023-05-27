#ifndef __PILHADFSEBFS_H
#define __PILHADFSEBFS_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"matriz.h"

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

void MudancadeLocalizacao(signed short int *escolha,int *Linha,int *Coluna);
void CaminhamentoDFS(Matriz *M,signed short int *Ordem);

#endif

//fim do código