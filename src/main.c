#include<stdio.h>
#include<stdlib.h>
#include"Lista.h"
#include"File.h"
#include"matriz.h"
#include"PilhaDFSeBFS.h"



int main()
{
	
	Matriz M;
	FILE *File;
	signed short int Ordem;

	//entra no arquivo de entrada e extrai o tamanho do mesmo
		LeituraTamanho(&Ordem,&File);

	//reserva espaço para a matriz na memória 
		Alocacao(&M,&Ordem);

	//preenche a matriz com os elementos existentes no arquivo de entrada
		Preencher(&File,&M,&Ordem);

	//foi utilizado apenas para ver se estava funcionando o preenchimento da matriz, não tem uso depois de averiguado
		//MostrandoMatriz(&M,&Ordem);

	//aqui é chamado o método que realiza o caminhamento em profundida
		CaminhamentoDFS(&M,&Ordem);

 	/*Lista l;
	Item aux;

	FLVazia(&l);

	aux.x = 10;
  aux.y = 5;
	LInsert(&l, aux);
	aux.x = 20;
	LInsert(&l, aux);
	aux.y = 30;
	LInsert(&l, aux);

	LImprime(&l);

	aux.x = 2;
	LRemove(&l, aux);

	LImprime(&l);
  */


return 0;
}
