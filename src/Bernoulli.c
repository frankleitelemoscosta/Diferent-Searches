#include"Bernoulli.h"

void EscolhaRandomica(short int *numeroColuna,short int *numeroLinha)
{
    signed short int escolha = 0;
    
    escolha = rand()%20;

        if(escolha > 5 && escolha < 12)
        {
            *numeroColuna = 1;
        }
        else if(escolha >= 0 && escolha < 6)
        {
            *numeroColuna = -1;
        }
        else{
            *numeroColuna = 0; 
        }

    escolha = rand()%20;

        if(escolha > 5 && escolha < 12)
        {
            *numeroLinha = 1;
        }
        else if(escolha >= 0 && escolha < 6)
        {
            *numeroLinha = -1;
        }
        else{
            *numeroLinha = 0; 
        }
}

void AlterandoasVariaveis(short int *numeroLinha,short int *numeroColuna,int *Coluna,int *Linha,signed short int *Ordem)
{
        *Coluna = *numeroColuna + *Coluna;

        *Linha = *numeroLinha + *Linha;

        //evitando segmentation fault
            if(*Coluna < 0)
            {
                *Coluna += 1;
            }

            if(*Linha < 0)
            {
                *Linha += 1;
            }
        //fim

        //evitando segmentation fault
            if(*Coluna > (*Ordem - 1))
            {
                *Coluna = (*Ordem - 1);
            }

            if(*Linha > (*Ordem - 1))
            {
                *Linha = (*Ordem - 1);
            }
        //fim
}

void EvitandoParedes(Matriz *M,short int *numeroLinha,short int *numeroColuna,int *Coluna,int *Linha,short int *LinhaAtual,short int *ColunaAtual,signed short int *Ordem)
{
    signed short int parada = 0;

    //este loop encerra quando a posição para onde se caminha não for uma parede
    while(parada != 1)
    {
            if(M->MAT[*Linha][*Coluna].item == '#')
            {

                *Linha = *LinhaAtual;
                *Coluna = *ColunaAtual;
                EscolhaRandomica(numeroColuna,numeroLinha);
                *Coluna = *numeroColuna + *Coluna;
                *Linha = *numeroLinha + *Linha;

            //evitando segmentation fault
                if(*Coluna < 0)
                {
                    *Coluna += 1;
                }

                if(*Linha < 0)
                {
                    *Linha += 1;
                }
            //fim

            //evitando segmentation fault
                if(*Coluna > (*Ordem - 1))
                {
                    *Coluna = (*Ordem - 1);
                }

                if(*Linha > (*Ordem - 1))
                {
                    *Linha = (*Ordem - 1);
                }
            //fim
            }
            else{
                parada = 1;
            }
    }
}

void MudancadePosicao(Matriz *M,int *Linha,int *Coluna,signed short int *Ordem)
{

    //variaveis locais	
        short int numeroLinha;
        short int numeroColuna;
        short int parada = 0;
        short int LinhaAtual = *Linha;
        short int ColunaAtual = *Coluna;

    //nesta função é decidido para onde vai se caminhar
        EscolhaRandomica(&numeroColuna,&numeroLinha);

    //se acaso não mudar a linha muda obrigatoriamente
        while(parada != 1)
        {
            if(numeroColuna == 0 && numeroLinha == 0){
                numeroLinha = 1;
            }
            else{
                parada = 1;
            }
        }

    //onde ocorre a alteração da linha e coluna
        AlterandoasVariaveis(&numeroLinha,&numeroColuna,Coluna,Linha,Ordem);
   
    //esta função é chamada para corrigir quando se depara com uma parede
        EvitandoParedes(M,&numeroLinha,&numeroColuna,Coluna,Linha,&LinhaAtual,&ColunaAtual,Ordem);
            
}

void CaminhamentoBernoulli(Matriz *M,signed short int *Ordem)
{

    int Linha = 0;
    int Coluna = 0;
    bool parada = true;

    //loop para repetir a troca de posição pela matriz
    while(parada != false)
    {
        M->MAT[Linha][Coluna].validacao = true;
        if(M->MAT[Linha][Coluna].item == '?')
        {
            printf("Bernoulli(%d,%d)\n",Linha,Coluna);
            break;
        }
        else if(M->MAT[Linha][Coluna].item == '*')
        {
            Reset(M,Ordem,&Linha,&Coluna);
        }

        //função que intermedia os processos de escolha randomica, alteração da linha e coluna e o desvio das paredes
        MudancadePosicao(M,&Linha,&Coluna,Ordem);
    }
}
//fim do código
