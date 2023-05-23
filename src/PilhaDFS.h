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
void PImprime(Pilha *p);
int Tamanho(Pilha *P);

void CaminhamentoDFS(Matriz *M,signed short int *Ordem);
void Selecionando(Matriz *M,signed short int *Ordem,int *Linha,int *Coluna,signed short int *escolha,Pilha *Ponteiro, Item *Ponteiro_Item );

#endif

//fim do código

/*
Este código se trata das assinaturas referentes a pilha, juntamente as assinaturas dos métodos de caminhamento em profundidade e em largura 

as structs são componentes da pilha, sendo:
Item possui o int que armazena cada item que esta na pilha
Block se trata de cada nó que a pilha tem
Pilha se trata da cabeça e da cauda da pilha

Os métodos da pilha propriamente dita são:
FPvazia recebe um ponteiro do tipo pilha para que seja possivel acessar os ponteiros da cauda e da cabeça e verificar se eles não são null, se forem justifica dizer que a lista não tem elementos, pois esta apontando para nada

Push insere elementos na cabeça da lista e vai linkando o prox com o elemento anterior

o POP retira os elementos do topo da lista, recebe um ponteiro da pilha para acessar o top e vai mudando o ponteiro que a ponto para o nó do topo, fazendo ele apontar para o elemento anterior da cabeça antes de deleta-la
*/