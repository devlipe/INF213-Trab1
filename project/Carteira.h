#pragma once

#include "Acao.h"
#include "Cotacao.h"
#include "Dado.h"
#include "Algoritmos.h"
class Carteira
{
private:
    Acao acoes[110];
    unsigned int nAcoes;
    int valorAtual; //Patrimonio
    unsigned int dataUltimaAttDePatrimonio;

    //* Funcoes de uso privado da classe
    void atualizaValorAtual(Cotacao *listaCotacao, unsigned int &data, unsigned int &tamVetor);
    void insert(const std::string &elem, int pos);

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
    ///Funcao que retorna uma funcao do vertor
    Acao getAcao(const int pos);

    //* Funcoes de uso do Programa

    /// Funcao que procura no vetor de acoes se possuo a acao pesquisada // Se consegue encontrar, retorna a posicao da acao, caso contrario, retorna -1
    int procuraAcao(const std::string &ticker) const;
    ///Funacao que insere no vetor de acoes uma outra acao de forma alfabetica // retorna a posicao inserida
    int insereAcaoAlfa(const std::string &ticker);
    //TODO: Implementar as classes abaixo no arquivo carteira.cpp (Criei antes so para garantir a ideia)
    ///Funcao para executar os dividendos, ira pegar o valor e somar a acao que recebeu os dividendos
    unsigned int executaDividendos(const Dividendo &div, const int &posAcao);
    ///Funcao par executar os splits, ira pegar o rate dos splits e executar na acao referente
    void executaSplits(const Split &split, const int &posAcao);
    ///Funcao para executar as Operacoes, ira pegar a informacoes e decidir se se trata de uma
    void executaOperacoes(const Operacao &op, const int &posAcao);
};