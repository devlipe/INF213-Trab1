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
    unsigned int dividendosPagosNoMes;
    int lucroOperacaoNoMes;

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
    unsigned int getDividendosPagos() const;
    int getlucroOperacoes() const;

    void setQuantidadeAtual(int quantidade);
    void setPrecoDeCompra(unsigned int preco);
    void setCustoTotal(unsigned int custoTot);
    void setCustoMedio(unsigned int custoMed);
    void setDividendosPagos(unsigned int divdendos);
    void setLucroOperacao(int lucroOp);

    //*Funcoes de uso do Programa
};
