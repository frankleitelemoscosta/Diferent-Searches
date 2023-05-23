#include"PilhaDFS.h"

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


void PImprime(Pilha *p){
	Block *aux;

	aux = p->top;
	while(aux != p->base){
		printf("Linha: %d\n", aux->data.Linha);
		printf("Coluna: %d\n", aux->data.Coluna);
		aux = aux->prox;
	}

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

/*

O método push é simples e sequencial sendo executado uma vez por inserção, ele recebe um ponteiro da pilha e acessa o topo dessa pilha(linha 12), fazendo com que o novo nó aponte para o antigo elemento, e após faz com que o ponteiro que antes apontava para o elemento anterior agora aponte para o nove elemento criado(linha 10)

O método pop elimina um elemento da cabeça a cada vez que é chamado, o mesmo cria um nó vazio apenas para ser intermédio para eliminar a cabeça sem perder o endereço do elemento anterior, primeiramente esse ponteiro recebe a cabeça(linha 14), dai ele muda a cabeça para o elemento anterior da mesma(linha 25)

*/