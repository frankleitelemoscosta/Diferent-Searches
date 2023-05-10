#include "Lista.h"

void Swap(ItemL *posicao_procurada, ItemL *Posicao_sucessora){
	
	ItemL aux;

	aux = *posicao_procurada;
	*posicao_procurada  = *Posicao_sucessora;
	*Posicao_sucessora  = aux;

}

void FLVazia(Lista *l){

	l->first = 0;
	l->last  = 0;

}

void LInsert(Lista *l, ItemL d){
	
	if (l->last >= MAXTAM)
	{
		printf("LISTA CHEIA!\n");
	}
	else
	{

		l->vet[l->last] = d;
		l->last ++;
	
	}
}

void LRemove(Lista *l, ItemL d){

	bool ok = false;

	if(l->first == l->last)
	{
		printf("LISTA VAZIA!\n");
	}
	else
	{
		for(int i = l->first ; i < l->last ; i++)
		{
			if(l->vet[i].x == d.x)
			{
			
				Swap( &l->vet[i], &l->vet[i+1]);
				ok = true;	
			
			}
		}
	
		if(ok)
		{
			l->last --;
		}
	}
}

void LImprime(Lista *l){
	for(int i = l->first ; i < l->last ; i++)
	{
		printf("%d/%d", l->vet[i].x, l->vet[i].y);
	}
	printf("\n");
}

/*
 A função FLVazia é chamada neste código para averiguar se ela se esta sem nenhum elemento
o que pode ocorrer em dois casos, quando inicia-se o programa e quando se reseta tudo.

 A função LRemove realiza remoção de elemento informado por parametro pelo usuário se a lista não estiver vazia

 A função LInsert inseri elementos na lista, o mesmo recebe a lista em si e uma variavel
do tipo item que contem o que deve ser guardado na lista naquela posição.

 A função LImprime mostra todos os elementos que foram inseridos na lista
*/

