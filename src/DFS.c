#include"PilhaDFSeBFS.h"

void Desimpilhando(){

}

void Reset(){

}

void CaminhamentoDFS(Matriz *M,signed short int *Ordem){
    
    //variaveis de ambiente
        signed short int escolha = 1;
        int Linha = 0;
        int Coluna = 0;
        bool parada = true;
    //fim das variaveis


    while(parada == true){

    //se for encontrado o interrogação o loop é quebrado com o break
        (M->MAT[Linha][Coluna] == '?')?(break);

    //Para continuar a caminhar em profundidade
        (Linha == (*Ordem - 1) || Coluna == (*Ordem - 1) || M->MAT[Linha][Coluna] == '#')?(Desimpilhando()):((M->MAT[Linha][Coluna] == '*')?(Reset()));

    //aqui se faz a escolha para onde andar
        (escolha == 1)?(Coluna = Coluna + 1):((escolha == 2)?(Linha = Linha + 1):(Linha = Linha + 1, Coluna = Coluna + 1));
    }

    
}