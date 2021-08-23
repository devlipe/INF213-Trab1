// TODO: Implementar a classe carteira (Tera um vetor de acao)
//TODO: Separar o que fica com a classe carteira e o que fica com a classe acao

#pragma once 

#include "Acao.h"
class Carteira
{
private:
    Acao acao[100];
    unsigned int nAcao;
    int valorAtual; //Patrimonio
    unsigned int custoDeCompraT;
    int valorizacao; // ValorAtual - CustoDeCompra;
    int lucroOperacoes;
    int lucroDividendos;
    int rentabilidadeTotal; /// Valorizacao + lucroOperacoes + lucroDividendos

public:

    //* Construtor e Destrutor
    Carteira();
    ~Carteira();
};