#pragma once

#include <string>
#include <iostream>

class Acao
{
private:
    std::string ticker;
    int quantidadeAtual;
    unsigned int valorAtual;
    unsigned int custoTotal;
    double custoMedio;
    unsigned int dividendosMes;
    unsigned int dividendosTotais;
    int lucroOperacoesMes;
    int lucroOperacoesTotais;

public:
    //* Construtor e Destrutor

    Acao();
    Acao(const std::string &ticker);
    ~Acao();

    //*Getters and Setters

    std::string getTicker() const;
    int getQuantidadeAtual() const;
    unsigned int getValorAtual() const;
    unsigned int getCustoTotal() const;
    double  getCustoMedio() const;
    unsigned int getDividendosMes() const;
    unsigned int getDividendosTotais() const;
    int getOperacoesMes() const;
    int getOperacoesTotais() const;
    int getLucroTotalMes() const;
    int getLucroTotalGeral() const;
    int getValorizacao() const;

    void setQuantidadeAtual(int quantidade);
    void setCustoTotal(unsigned int custoTot);
    void setCustoMedio(double custoMed);
    void setDividendosMes(unsigned int divdendosM);
    void setDividendosTotais(unsigned int dividendosT);
    void setOperacoesMes(int lucroOpM);
    void setOperacoesTotais(int lucroOpT);
    void setValorAtual(int valorAtt);

    //*Funcoes de uso do Programa

    void printInfo() const;
};
