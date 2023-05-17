#include<stdio.h>
#include<stdlib.h>
#include"Lista.h"
#include"File.h"
#include"matriz.h"
#include"PilhaDFS.h"
#include"Fila.h"
#include"Bernoulli.h"




int main()
{
	
	Matriz M;
	FILE *File;
	signed short int Ordem;
	Fila F;

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

		LeituraTamanho(&Ordem,&File);

		Preencher(&File,&M,&Ordem);

		CaminhamentoBFS(&M,&Ordem,&F);

		LeituraTamanho(&Ordem,&File);

		Preencher(&File,&M,&Ordem);

		CaminhamentoBernoulli(&M,&Ordem);


return 0;
}
