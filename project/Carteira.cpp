#include "Carteira.h"

Carteira::Carteira()
{
    nAcoes = 0;
    valorAtual = 0;
    dataUltimaAttDePatrimonio = 0;
}

Carteira::~Carteira()
{
}

void Carteira::atualizaValorAtual(Cotacao *listaCotacao, unsigned int &data, unsigned int &tamVetor)
{
    valorAtual = 0;
    for (int i = 0; i < nAcoes; i++)
    {
        Dado Dado(acao[i].getTicker(), data);
        unsigned int preco = listaCotacao[algoritmos::buscaBinariaDadoDataNome(listaCotacao, Dado, tamVetor)].getPrecoDoDia();
        valorAtual += (acao[i].getQuantidadeAtual() * preco);
    }
}

unsigned int Carteira::getNumAcao() const
{
    return nAcoes;
}

int Carteira::getValorAtual(Cotacao *listaCotacao, unsigned int &data, unsigned int &tamVetor)
{
    if (data == dataUltimaAttDePatrimonio)
    {
        return valorAtual;
    }
    else
    {
        atualizaValorAtual(listaCotacao, data, tamVetor);
        dataUltimaAttDePatrimonio = data;
        return valorAtual;
    }
}

unsigned int Carteira::getCustoDeCompraTot()
{
    unsigned int custoDeCompraTot = 0;
    for (int i = 0; i < nAcoes; i++)
    {
        custoDeCompraTot += acao[i].getCustoTotal();
    }
    return custoDeCompraTot;
}

int Carteira::getLucroDividendosTot()
{
    int lucroDividendosTot = 0;
    for (int i = 0; i < nAcoes; i++)
    {
        lucroDividendosTot += acao[i].getDividendosTotais();
    }
    return lucroDividendosTot;

}

int Carteira::getLucroDividendosMes()
{
    int lucroDividendoMes = 0;
    for (int i = 0; i < nAcoes; i++)
    {
        lucroDividendoMes += acao[i].getDividendosMes();
        acao[i].setDividendosMes(0);
    }
    return lucroDividendoMes;
}

int Carteira::getLucroOperacoesTot()
{
    int lucroOperacoesTot = 0;
    for ( int  i = 0; i < nAcoes; i++)
    {
        lucroOperacoesTot += acao[i].getOperacoesTotais();
    }
    
    return lucroOperacoesTot;
}

int Carteira::getLucroOperacoesMes()
{
    int lucroOperacoesMes = 0;
    for (int i = 0; i < nAcoes; i++)
    {
        lucroOperacoesMes += acao[i].getOperacoesMes();
        acao[i].setOperacoesMes(0);
    }
    return lucroOperacoesMes;
}