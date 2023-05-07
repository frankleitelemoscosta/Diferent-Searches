#include "matriz.h"
#include<stdio.h>
#include<stdlib.h>

void LeituraTamanho(signed short int *Ordem,FILE **File)
{
    //variaveis de ambiente
        signed short int *Lixo = (signed short int *)malloc(1*sizeof(signed short int));
    //fim das variaveis de ambiente

    //abertura do arquivo
        *File = fopen("dataset/input.data","r");
        if(*File == NULL)
        {
            printf("\nThe file is not opened for read matrix\n");
            exit(-1);
        }
    //fim da abertura

    //lendo a linha onde esta o tamanho da matrix
        fscanf(*File,"%hd",&(*Ordem));

    //para ler as duas outras informações geradas que não serviram de nada
        for(int i = 0 ; i < 2 ; i++)
        {
            fscanf(*File,"%hd",Lixo);
        }

    //limpando a memória
        Lixo = (signed short int *)realloc(Lixo,0);

}

//fim do código