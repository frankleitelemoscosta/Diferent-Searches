#include"PilhaDFS.h"
#include<stdbool.h>


void Selecionando(Matriz *M,signed short int *Ordem,int *Linha,int *Coluna,signed short int *escolha,Pilha *Ponteiro, Item *Ponteiro_Item){

    bool sinal = false;
    bool aux = false;

    do{
    //para decidir onde deve se caminhar
        if((*Linha + 1) < *Ordem)
        {
            if(M->MAT[*Linha + 1][*Coluna].item != '#' && M->MAT[*Linha + 1][*Coluna].validacao != true && sinal == false)
            {
                sinal = true;
                *escolha = 2;
            }
        }
        if((*Coluna - 1) > -1)
        {
            if(M->MAT[*Linha][*Coluna - 1].item != '#' && M->MAT[*Linha][*Coluna - 1].validacao != true && sinal == false)
            {
                sinal = true;
                *escolha = 4;
            }
        }
        if(((*Linha + 1) < *Ordem) && ((*Coluna + 1) < *Ordem))
        {
            if(M->MAT[*Linha + 1][*Coluna + 1].item != '#' && M->MAT[*Linha + 1][*Coluna + 1].validacao != true && sinal == false)
            {
                sinal = true;
                *escolha = 3;
            }
        }
        if(((*Coluna + 1) < *Ordem))
        {
            if(M->MAT[*Linha][*Coluna + 1].item != '#' && M->MAT[*Linha][*Coluna + 1].validacao != true && sinal == false)
            {
                sinal = true;
                *escolha = 1;
            }
        }
        if((*Linha - 1) > -1)
        {
            if(M->MAT[*Linha - 1][*Coluna].item != '#'&& M->MAT[*Linha - 1][*Coluna].validacao != true && sinal == false)
            {
                sinal = true;
                *escolha = 5;
            }
        }
    //fim da tomada de decisão
    aux = false;

    if(sinal == false)
    {
        Pop(Ponteiro,Ponteiro_Item);
        *Linha = Ponteiro->top->data.Linha ;
        *Coluna = Ponteiro->top->data.Coluna;
        aux = true;
    }
    }while(aux == true);
    

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

    FPVazia(&Ponteiro);

    while(parada == true){

        M->MAT[Linha][Coluna].validacao = true;


    //se for encontrado o interrogação o loop é quebrado com o break
        if(M->MAT[Linha][Coluna].item == '?')
        {
            printf("\nA interrogação foi encontrada em (Linha,Coluna)(%d,%d)\n",Linha,Coluna);
            break;
        }
        if((Linha + 1) < *Ordem && escolha == 2)
        {
            if(M->MAT[Linha + 1][Coluna].item == '#')
            {
                Selecionando(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item);
            }
        }
        else if(escolha == 2){
            Selecionando(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item);
        }
        if((Coluna - 1) > -1 && escolha == 4)
        {
            if(M->MAT[Linha][Coluna - 1].item == '#')
            {
                Selecionando(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item);
            }
        }
        else if(escolha == 4){
            Selecionando(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item);
        }
        if(((Linha + 1) < *Ordem) && ((Coluna + 1) < *Ordem) && escolha == 3)
        {
            if(M->MAT[Linha + 1][Coluna + 1].item == '#')
            {
                Selecionando(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item);
            }
        }
        else if(escolha == 3){
            Selecionando(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item);
        }
        if(((Coluna + 1) < *Ordem) && escolha == 1)
        {
            if(M->MAT[Linha][Coluna + 1].item == '#')
            {
                Selecionando(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item);
            }
        }
        else if(escolha == 1){
            Selecionando(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item);
        }
        if((Linha - 1) > -1 && escolha == 5)
        {
            if(M->MAT[Linha - 1][Coluna].item == '#')
            {
                Selecionando(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item);
            }
        }
        else if(escolha == 5){
            Selecionando(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item);
        }

    //aqui se faz a escolha para onde andar
        if(escolha == 1)
        {
            Coluna = Coluna + 1;
        }
        else if(escolha == 2)
        {
            Linha = Linha + 1;
        }
        else if(escolha == 3)
        {
            Linha = Linha + 1, Coluna = Coluna + 1;
        }
        else if(escolha == 4)
        {
            Coluna = Coluna - 1;
        }
        else if(escolha == 5)
        {
            Linha = Linha - 1;
        }

        Ponteiro_Item.Linha = Linha;
        Ponteiro_Item.Coluna = Coluna;

        Push(&Ponteiro,Ponteiro_Item);

        /*MostrandoMatriz(M,Ordem,&Linha,&Coluna);//apenas para teste, assim que acabar deve ser apagado

        getchar();//apenas para teste, assim que acabar deve ser apagado
        getchar();//apenas para teste, assim que acabar deve ser apagado
        */    
        if(M->MAT[Linha][Coluna].item == '*')
        {
            Reset(M,Ordem,&Linha,&Coluna);
            
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