
#include "Acao.h"

Acao::Acao()
{
    ticker = "";
    quantidadeAtual = 0;
    precoDeCompra = 0;
    custoTotal = 0;
    custoMedio = 0;
    dividendosMes = 0;
    dividendosTotais = 0;
    lucroOperacoesMes = 0;
    lucroOperacoesTotais = 0;
}

Acao::~Acao()
{
}

std::string Acao ::getTicker() const
{
    return ticker;
}

int Acao::getQuantidadeAtual() const
{
    if (quantidadeAtual < 0)
    {
        return 0;
    }

    return quantidadeAtual;
}

unsigned int Acao::getPrecoDeCompra() const
{
    return precoDeCompra;
}

unsigned int Acao::getCustoTotal() const
{
    return custoTotal;
}

unsigned int Acao::getCustoMedio() const
{
    return custoMedio;
}

unsigned int Acao::getDividendosMes() const
{
    return dividendosMes;
}

unsigned int Acao::getDividendosTotais() const
{
    return dividendosTotais;
}

int Acao::getOperacoesMes() const
{
    return lucroOperacoesMes;
}

int Acao::getOperacoesTotais() const
{
    return lucroOperacoesTotais;
}

void Acao::setQuantidadeAtual(int &quantidade)
{
    quantidadeAtual = quantidade;
}

void Acao::setPrecoDeCompra(unsigned int &preco)
{
    precoDeCompra = preco;
}

void Acao::setCustoTotal(unsigned int &custoTot)
{
    custoTotal = custoTot;
}

void Acao::setCustoMedio(unsigned int &custoMed)
{
    custoMedio = custoMedio;
}

void Acao::setDividendosMes(unsigned int &dividendosM)
{
    dividendosMes = dividendosM;
}

void Acao::setOperacoesMes(int &lucroOpM)
{
    lucroOperacoesMes = lucroOpM;
}

void Acao::setOperacoesTotais(int &lucroOpT)
{
    lucroOperacoesTotais = lucroOpT;
}