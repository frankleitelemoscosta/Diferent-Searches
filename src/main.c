//bibliotecas e importação de outros arquivos
	#include<stdio.h>
	#include<stdlib.h>
	#include"Lista.h"
	#include"File.h"
	#include"matriz.h"
	#include"PilhaDFS.h"
	#include"Fila.h"
	#include"Bernoulli.h"
//fim

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

	//aqui é chamado o método que realiza o caminhamento em profundidade
		CaminhamentoDFS(&M,&Ordem);

	//O preenchimento da matriz é refeito para que seja possivel reiniciar o novo caminhamento
		LeituraTamanho(&Ordem,&File);

		Preencher(&File,&M,&Ordem);

	//aqui é chamado o método que realiza o caminhamento em largura
		CaminhamentoBFS(&M,&Ordem,&F);

	//O preenchimento da matriz é refeito para que seja possivel reiniciar o novo caminhamento
		LeituraTamanho(&Ordem,&File);

		Preencher(&File,&M,&Ordem);

	//aqui é chamado o método que realiza o caminhamento de maneira aleatória
		CaminhamentoBernoulli(&M,&Ordem);


return 0;
}
