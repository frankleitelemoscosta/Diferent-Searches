#include"Pilha.h"

void FPVazia(Pilha *p){
	
	p->base = (Block*) malloc (sizeof(Block));
	p->top  = p->base;
	p->base->prox = NULL;

}

void Push(Pilha *p, Item d){

	Block *aux = (Block*) malloc (sizeof(Block));
	aux->data = d;
	aux->prox = p->top;
	p->top = aux;

}

void Pop(Pilha *p, Item *d){

	Block *aux;

	if(p->base == p->top || p == NULL){
		//printf("PILHA VAZIA!\n");
		return;
	}
	
	aux = p->top;
	p->top = aux->prox;
	*d = aux->data;
	free(aux);
}

int Tamanho(Pilha *P){

	Block *aux;
	int contador = 0;

	aux = P->top;

	while(aux != NULL)
	{
		aux = aux->prox;
		contador += 1;
	}
	return contador;
}

