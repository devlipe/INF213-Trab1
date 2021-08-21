//TODO:  Acabar de Implementar a classe acao para guardar as informacoes dentro da classe carteira

#pragma once

#include <string>

class Acao
{
private:
    std::string ticker;
    int quantidadeAtual;
    unsigned int precoDeCompra;
    unsigned int custoTotal;
    unsigned int custoMedio;
    unsigned int dividendosMes;
    unsigned int dividendosTotais;
    int lucroOperacoesMes;
    int lucroOperacoesTotais;

public:
    //* Construtor e Destrutor

    Acao();
    ~Acao();

    //*Getters and Setters

    std::string getTicker() const;
    int getQuantidadeAtual() const;
    unsigned int getPrecoDeCompra() const;
    unsigned int getCustoTotal() const;
    unsigned int getCustoMedio() const;
    unsigned int getDividendosMes() const;
    unsigned int getDividendosTotais() const;
    int getOperacoesMes() const;
    int getOperacoesTotais() const;


    void setQuantidadeAtual(int &quantidade);
    void setPrecoDeCompra(unsigned int &preco);
    void setCustoTotal(unsigned int &custoTot);
    void setCustoMedio(unsigned int &custoMed);
    void setDividendosMes(unsigned int &divdendosM);
    void setDividendosTotais(unsigned int &dividendosT);
    void setOperacoesMes(int &lucroOpM);
    void setOperacoesTotais(int &lucroOpT);

    //*Funcoes de uso do Programa
};
