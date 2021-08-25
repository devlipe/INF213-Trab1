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
    unsigned int dataUltimaAttValorAtual;
    int custoTotal;
    unsigned int dataUltimaAttCustoTotal;
    int operacoesMes;
    unsigned int dataUltimaAttOpMes;
    int operacoesTot;
    unsigned int dataUltimaAttOpTot;
    unsigned int dividendosMes;
    unsigned int dataUltimaAttDivMes;
    unsigned int dividendosTot;
    unsigned int dataUltimaAttDivTot;

    //* Funcoes de uso privado da classe
    void executaCompra(const Operacao &op, const int &posAcao, const Cotacao *listaCotacao, const unsigned int &tamVetor);
    void executaVendas(const Operacao &op, const int &posAcao, const Cotacao *listaCotacao, const unsigned int &tamVetor);
    void atualizaCustoTotal(const unsigned int &data);
    void atualizaDividendosTotais(const unsigned int &data);
    void atualizaDividendosMensal(const unsigned int &data);
    void atualizaOperacoesTotais(const unsigned int &data);
    void atualizaOperacoesMensais(const unsigned int &data);

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
    unsigned int getCustoTotal(const unsigned int &data);
    ///Funcao que retorna o lucro com operacoes totais
    int getLucroOperacoesTot(const unsigned int &data);
    ///Funcao que retornar o lucro com operacoes no mes, e zera a variavel que guarda os lucros com operacoes mensais
    int getLucroOperacoesMes(const unsigned int &data);
    ///Funcao que retorna o lucro com dividendos totais;
    int getLucroDividendosTot(unsigned int &data);
    ///Funcao que retorna o lucro com dividendos no mes, e zera a variavel na acao que guarda os dividendos mensais
    int getLucroDividendosMes(unsigned int &data);
    ///Funcao que retorna uma funcao do vertor
    Acao getAcao(const int pos) const;
    ///Funcao que retorna a valorizacao da carteira em uma determinada Data
    int getValorizacao(Cotacao *listaCotacao, unsigned int &data, unsigned int &tamVetor);
    ///Funcao que retorna o total da carteira em um determinado momento
    int getTotal(Cotacao *listaCotacao, unsigned int &data, unsigned int &tamVetor);

    //* Funcoes de uso do Programa

    /// Funcao que procura no vetor de acoes se possuo a acao pesquisada // Se consegue encontrar, retorna a posicao da acao, caso contrario, retorna -1
    int procuraAcao(const std::string &ticker) const;
    ///Funacao que insere no vetor de acoes uma outra acao // retorna a posicao inserida
    int insereAcao(const std::string &ticker);
    ///Funcao para executar os dividendos, ira pegar o valor e somar a acao que recebeu os dividendos
    unsigned int executaDividendos(const Dividendo &div, const int &posAcao);
    ///Funcao par executar os splits, ira pegar o rate dos splits e executar na acao referente
    void executaSplits(const Split &split, const int &posAcao);
    ///Funcao para executar as Operacoes, ira pegar a informacoes e decidir se se trata de uma
    void executaOperacoes(const Operacao &op, const int &posAcao, const Cotacao *listaCotacao, const unsigned int &tamVetor);
    ///Funcao para ordenar o vetor de acoes por mes para saida do metodo D
    void ordenaVetorAcoesMes();
    ///Funcao para ordenar o vetor de acoes por mes para saida do metodo D
    void ordenaVetorAcoesGeral();
    ///Metodo para atualizar os valores das acoes
    void atualizaValorAtual(Cotacao *listaCotacao, unsigned int &data, unsigned int &tamVetor);
};