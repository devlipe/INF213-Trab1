
#include "Acao.h"

Acao::Acao()
{
    ticker = "";
    quantidadeAtual = 0;
    custoTotal = 0;
    custoMedio = 0;
    dividendosMes = 0;
    dividendosTotais = 0;
    lucroOperacoesMes = 0;
    lucroOperacoesTotais = 0;
}

Acao::Acao(const std::string &ticker)
{
    this->ticker = ticker;
    quantidadeAtual = 0;
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

int Acao::getLucroTotalMes() const
{
    return dividendosMes + lucroOperacoesMes;
}

int Acao::getLucroTotalGeral() const
{
    return dividendosTotais + lucroOperacoesTotais;
}

void Acao::setQuantidadeAtual(int quantidade)
{
    quantidadeAtual = quantidade;
}

void Acao::setCustoTotal(unsigned int custoTot)
{
    custoTotal = custoTot;
}

void Acao::setCustoMedio(unsigned int custoMed)
{
    custoMedio = custoMed;
}

void Acao::setDividendosMes(unsigned int dividendosM)
{
    dividendosMes = dividendosM;
}

void Acao::setDividendosTotais(unsigned int dividendosT)
{
    dividendosTotais = dividendosT;
}

void Acao::setOperacoesMes(int lucroOpM)
{
    lucroOperacoesMes = lucroOpM;
}

void Acao::setOperacoesTotais(int lucroOpT)
{
    lucroOperacoesTotais = lucroOpT;
}

void Acao::setValorAtual(int valorAtt)
{
    valorAtual = valorAtt;
}

void Acao::printInfo() const
{
    std::cout << "Ticker: " << ticker << std::endl;
    std::cout << "Qunantidade Atual: " << quantidadeAtual << std::endl;
    std::cout << "Custo Total: " << custoTotal << std::endl;
    std::cout << "Custo Medio: " << custoMedio << std::endl;
    std::cout << "Dividendos Mes: " << dividendosMes << std::endl;
    std::cout << "Dividendos Totais: " << dividendosTotais << std::endl;
    std::cout << "Lucro Operacoes Mes: " << lucroOperacoesMes << std::endl;
    std::cout << "Lucro Operacoes Totais: " << lucroOperacoesTotais << std::endl;
}