//bibliotecas e importação de outros arquivos
	#include<stdio.h>
	#include<stdlib.h>
	#include"File.h"
	#include"matriz.h"
	#include"PilhaDFS.h"
	#include"Fila.h"
	#include"Bernoulli.h"
	#include"time.h"
//fim

int main()
{	
	Matriz M;
	FILE *File;
	signed short int Ordem;
	Fila F;
	clock_t inicio, fim;
    double tempo_de_uso_CPU;
    srand(time(NULL));


    inicio = clock(); // Captura o tempo de início

	//entra no arquivo de entrada e extrai o tamanho do mesmo
		LeituraTamanho(&Ordem,&File);

	//reserva espaço para a matriz na memória 
		Alocacao(&M,&Ordem);

	//preenche a matriz com os elementos existentes no arquivo de entrada
		Preencher(&File,&M,&Ordem);

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

		fim = clock(); // Captura o tempo de término

		tempo_de_uso_CPU = ((double) (fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo de execução em segundos

		printf("Tempo de execução: %.8f segundos\n", tempo_de_uso_CPU);

	return 0;
}
