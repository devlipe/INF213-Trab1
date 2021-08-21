
#include "Acao.h"

Acao::Acao()
{
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

unsigned int Acao::getDividendosPagos() const
{
    return dividendosPagosNoMes;
}

int Acao::getlucroOperacoes() const
{
    return lucroOperacaoNoMes;
}

void Acao::setQuantidadeAtual(int quantidade)
{
    quantidadeAtual = quantidade;
}

void Acao::setPrecoDeCompra(unsigned int preco)
{
    precoDeCompra = preco;
}

void Acao::setCustoTotal(unsigned int custoTot)
{
    custoTotal = custoTot;
}

void Acao::setCustoMedio(unsigned int custoMed)
{
    custoMedio = custoMedio;
}

void Acao::setDividendosPagos(unsigned int dividendos)
{
    dividendosPagosNoMes = dividendos;
}

void Acao::setLucroOperacao(int lucroOp)
{
    lucroOperacaoNoMes = lucroOp;
}