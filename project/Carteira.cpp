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
        Dado Dado(acoes[i].getTicker(), data);
        unsigned int preco = listaCotacao[algoritmos::buscaBinariaDadoDataNome(listaCotacao, Dado, tamVetor)].getPrecoDoDia();
        valorAtual += (acoes[i].getQuantidadeAtual() * preco);
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
        custoDeCompraTot += acoes[i].getCustoTotal();
    }
    return custoDeCompraTot;
}

int Carteira::getLucroDividendosTot()
{
    int lucroDividendosTot = 0;
    for (int i = 0; i < nAcoes; i++)
    {
        lucroDividendosTot += acoes[i].getDividendosTotais();
    }
    return lucroDividendosTot;
}

int Carteira::getLucroDividendosMes()
{
    int lucroDividendoMes = 0;
    for (int i = 0; i < nAcoes; i++)
    {
        lucroDividendoMes += acoes[i].getDividendosMes();
        acoes[i].setDividendosMes(0);
    }
    return lucroDividendoMes;
}

int Carteira::getLucroOperacoesTot()
{
    int lucroOperacoesTot = 0;
    for (int i = 0; i < nAcoes; i++)
    {
        lucroOperacoesTot += acoes[i].getOperacoesTotais();
    }

    return lucroOperacoesTot;
}

int Carteira::getLucroOperacoesMes()
{
    int lucroOperacoesMes = 0;
    for (int i = 0; i < nAcoes; i++)
    {
        lucroOperacoesMes += acoes[i].getOperacoesMes();
        acoes[i].setOperacoesMes(0);
    }
    return lucroOperacoesMes;
}

int Carteira::procuraAcao(const std::string &ticker) const
{
    for (int i = 0; i < nAcoes; i++)
    {
        if (ticker == acoes[i].getTicker())
        {
            return i;
        }
    }
    return -1;
}

void Carteira::insert(const std::string &elem, const int pos)
{
    if (pos > 110 || pos < 0) //Limites do array de acoes
    {
        throw("Tentativa de inserir acao em posicao indevida");
    }

    
    for (int i = nAcoes; i > pos; i--)
    {
        acoes[i] = acoes[i - 1];
    }
    acoes[pos] = Acao(elem);
    nAcoes++;

}

int Carteira::insereAcaoAlfa(const std::string &ticker)
{
    if (nAcoes > 0)
    {
        for (int i = 0; i < nAcoes; i++)
        {
            if (ticker <= acoes[i].getTicker())
            {
                insert(ticker, i);
                return i;
            }
        }
    }
    else
    {
        insert(ticker, 0);
        return 0;
    }
    insert(ticker, nAcoes);
    return nAcoes - 1;
}

Acao Carteira::getAcao(const int pos)
{
    return acoes[pos];
}

//TODO: Fazer a funcao retornar a quantidade total paga para bolsa, e dps de la, reinvestir os dividendos
unsigned int Carteira::executaDividendos(const Dividendo &div, const int &posAcao)
{
    double dividendoPago = ((acoes[posAcao].getQuantidadeAtual()) * (div.getValorDividendo())); //Teremos o valor double em reais que a empresa pagou de dividendos
    unsigned int dividendosPagosCentavos = static_cast<int>((dividendoPago*100)+0.000001);
    acoes[posAcao].setDividendosMes(acoes[posAcao].getDividendosMes()+dividendosPagosCentavos);
    acoes[posAcao].setDividendosTotais(acoes[posAcao].getDividendosTotais()+dividendosPagosCentavos);
    return dividendosPagosCentavos;
}