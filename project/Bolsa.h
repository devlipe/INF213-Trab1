#pragma once

#include <cassert>
#include "Dividendo.h"
#include "Cotacao.h"
#include "Split.h"
#include "Operacao.h"
#include "Carteira.h"
#include "Algoritmos.h"
class Bolsa
{
private:
    //TODO: Na funcao de printDetalhado, ela deve zerar os atributos Dividendos e lucroOperacao, toda as vezes que for chamada (Todo Mes);
    Bolsa() {}

    char tipoExecucao[2];

    Cotacao historicoCotacoes[500000];
    unsigned int nCotacoes;
    Dividendo historicoDividendos[500000];
    unsigned int nDividendos;
    Operacao listaOperacoes[500000];
    unsigned int nOperacoes;
    Split historicoSplits[500000];
    unsigned int nSplits;
    Carteira carteira;

    //* Fucoes de uso privado da Classe

    void leCotacoes(const char *cotacoesPath);
    void leSplits(const char *splitsPath);
    void leDividendos(const char *dividendosPath);
    void leOperacoes(const char *operacoesPath);
    void executaComandoQ() const;

    //* Funcoes de uso do Programa
    void leArquivosImp(const char **files);
    void printDataBaseImp() const;
    void organizaDataBaseImp();
    void executaTrabalhoImp();


public:
    //* Construtor e destrutor do Singleton
    ///Retorna a instancia do singleton criada no inicio do programa
    static Bolsa &getInstance()
    {
        static Bolsa instance;
        return instance;
    }
    ~Bolsa();

    //* Metodos para impedir que a classe seja copiada ou dublicada
    Bolsa(Bolsa const &) = delete;
    void operator=(Bolsa const &) = delete;

    //* Funcoes para facilitar o uso das funcoes do programa
    ///Funcao que a partir dos argumentos passados para a main realiza a leitura dos dados
    static void leArquivos(const char **files);
    ///Funcao para imprimir todas as informacoes do banco de dados e verificar se os arquivos foram corretamente lidos
    static void printDataBase();
    ///Funacao para organizar as cotacoes em ordem crescente de data
    static void organizaDataBase();
    ///Funcao para executar o trabalho, independente do tipo de execucao
    static void executaTrabalho();
};
