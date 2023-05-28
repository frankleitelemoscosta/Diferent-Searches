#include"Pilha.h"
#include<stdbool.h>
#include"DesviosCondicionais_e_escolhas_DFS.h"
#include"DFS.h"

void MudancadeLocalizacao(signed short int *escolha,int *Linha,int *Coluna)
{
    //aqui se faz a escolha para onde andar
        if(*escolha == 1)//para a direita
        {
            *Coluna = *Coluna + 1;
        }
        else if(*escolha == 2)//para baixo
        {
            *Linha = *Linha + 1;
        }
        else if(*escolha == 3)//diagonal inferior direita
        {
            *Linha = *Linha + 1;
            *Coluna = *Coluna + 1;
        }
        else if(*escolha == 4)//para a esquerda
        {
            *Coluna = *Coluna - 1;
        }
        else if(*escolha == 5)//para cima
        {
            *Linha = *Linha - 1;
        }else if(*escolha == 6)//na diagonal superior esquerda
        {
            *Linha = *Linha - 1;
            *Coluna = *Coluna - 1;
        }
        else if(*escolha == 7)//diagonal superior direita
        {
            *Linha = *Linha - 1;
            *Coluna = *Coluna + 1;
        }else if(*escolha == 8)//diagonal inferior esquerda
        {
            *Linha = *Linha + 1;
            *Coluna = *Coluna - 1;
        }
}

void CaminhamentoDFS(Matriz *M,signed short int *Ordem){
    
    //variaveis de ambiente
        signed short int escolha = 1;
        int Linha = 0;
        int Coluna = 0;
        bool parada = true;
        Pilha Ponteiro;
        Item Ponteiro_Item;
        int tamanho;
    //fim das variaveis

    //inicializa a pilha
    FPVazia(&Ponteiro);

    while(parada == true){
    //alterando a variavel que identifica se ja passou naquela casa
        M->MAT[Linha][Coluna].validacao = true;

    //se for encontrado o interrogação o loop é quebrado com o break
        if(M->MAT[Linha][Coluna].item == '?')
        {
            printf("\nProfundidade (Linha,Coluna)(%d,%d)\n",Linha,Coluna);
            break;
        }
        
        DesviodeParedes(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item);

        MudancadeLocalizacao(&escolha,&Linha,&Coluna);

        Ponteiro_Item.Linha = Linha;
        Ponteiro_Item.Coluna = Coluna;

        //empilhando
        Push(&Ponteiro,Ponteiro_Item);

        //verificando se esta em um perigo
        if(M->MAT[Linha][Coluna].item == '*')
        {
            Reset(M,Ordem,&Linha,&Coluna);            

            //resetando a pilha
            tamanho = Tamanho(&Ponteiro);
            for(int i = 0 ; i < tamanho ; i++)
            {
                Pop(&Ponteiro,&Ponteiro_Item);
            }
        }
    }

    //para reiniciar todas as variaveis de validação
        ResetandoValidacao(M,Ordem);
}

//fim do código