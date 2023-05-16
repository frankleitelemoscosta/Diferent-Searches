#include "Fila.h"

void FFVazia(Fila *f){
	
    f->first = (BlockF*) malloc (sizeof(BlockF));
	f->last  = f->first;
	f->first->prox = NULL;

}

bool isVazia(Fila *f){

	return f->first == f->last;

}

void Enfileira(Fila *f, ItemF d){

	f->last->prox = (BlockF*) malloc (sizeof(BlockF));
	f->last = f->last->prox;
	f->last->data = d;
	f->last->prox = NULL;

}

void Desenfileira(Fila *f, ItemF *d){
	
    BlockF *aux;

	if(f->first == f->last){
		printf("FILA VAZIA!\n");
		return;
	}
	
	aux = f->first->prox;
	f->first->prox = aux->prox;
	
	if (f->first->prox == NULL)
		f->last = f->first;
	
	*d = aux->data;
	free(aux);

}



void FImprime(Fila *f){
	
    BlockF *aux;

	aux = f->first->prox;
	while(aux != NULL){
		printf("%d\n", aux->data.Linha);
		aux = aux->prox;
	}

}