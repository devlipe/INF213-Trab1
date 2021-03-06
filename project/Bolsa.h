#pragma once

#include <cassert>
#include "Dividendo.h"
#include "Cotacao.h"
#include "Split.h"
#include "Operacao.h"
#include "Carteira.h"
#include "Algoritmos.h"
#include "Evento.h"
class Bolsa
{
private:
    Bolsa()
    {
        nEventos = 0;
        tipoExecucao[0] = '0';
        tipoExecucao[1] = '0';
    }

    std::string tipoExecucao;

    Cotacao historicoCotacoes[500000];
    unsigned int nCotacoes;
    Dividendo historicoDividendos[500000];
    unsigned int nDividendos;
    Operacao listaOperacoes[500000];
    unsigned int nOperacoes;
    Split historicoSplits[500000];
    unsigned int nSplits;
    Evento listaEventos[2000720]; /// Colocamos o as quantidades maximas (Operacoes + Splits + Dividendos + 60 anos em meses (Espaco para Eventos de Impressao))
    unsigned int nEventos;
    Carteira carteira;

    //* Fucoes de uso privado da Classe

    void leCotacoes(const char *cotacoesPath);
    void leSplits(const char *splitsPath);
    void leDividendos(const char *dividendosPath);
    void leOperacoes(const char *operacoesPath);
    void executaComandoQ() const;
    void executaComandoM();
    void executaComandoF();
    void executaComandoD();
    void montaVetorEventos();
    void adicionaOperacoesAosEventos(unsigned int &nEventos);
    void adicionaSplitsAosEventos(unsigned int &nEventos);
    void adicionaDividendosAosEventos(unsigned int &nEventos);
    void adicionaImpressoesAosEventos(unsigned int &nEventos);
    void simula(const Evento &evento);
    void simulaDividendos(const Evento &evento);
    void simulaReinvestirDividendos();
    void adicionaDividendosParaReinvestir(const unsigned int &valorPago, const Evento &evento);
    void simulaSplits(const Evento &evento);
    void simulaOperacoes(const Evento &evento);
    void executaEventosM();
    void executaEventosF();
    void executaEventosD();
    void impressaoTipoM(Evento &evento);
    void impressaoTipoF(Evento &evento);
    void impressaoTipoD(Evento &evento);
    void impressaoTipoDTabela1(Evento &evento, unsigned int &data);
    void impressaoTipoDTabela2(Evento &evento, unsigned int &data);

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
