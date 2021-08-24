#pragma once

#include "Acao.h"
#include "Cotacao.h"
#include "Dado.h"
#include "Algoritmos.h"
class Carteira
{
private:
    Acao acao[100];
    unsigned int nAcoes;
    int valorAtual; //Patrimonio
    unsigned int dataUltimaAttDePatrimonio;
    
    //* Funcoes de uso privado da classe
    void atualizaValorAtual(Cotacao *listaCotacao, unsigned int &data, unsigned int &tamVetor);

public:
    //* Construtor e Destrutor
    Carteira();
    ~Carteira();

    //* Getters and Setters

    ///Retorna o numero de acoes diferentes que a carteira possui
    unsigned int getNumAcao() const;
    ///Retona o Patrimonio atual da Carteira em uma determinada data
    int getValorAtual(Cotacao *listaCotacao, unsigned int &data, unsigned int &tamVetor);
    ///Funcao que retorna o custo de compra total da carteira
    unsigned int getCustoDeCompraTot();
    ///Funcao que retorna o lucro com operacoes totais 
    int getLucroOperacoesTot();
    ///Funcao que retornar o lucro com operacoes no mes, e zera a variavel que guarda os lucros com operacoes mensais
    int getLucroOperacoesMes();
    ///Funcao que retorna o lucro com dividendos totais;
    int getLucroDividendosTot();
    ///Funcao que retorna o lucro com dividendos no mes, e zera a variavel na acao que guarda os dividendos mensais
    int getLucroDividendosMes();

    //* Funcoes de uso do Programa
};