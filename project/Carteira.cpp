#include "Carteira.h"

Carteira::Carteira()
{
    nAcoes = 0;
    valorAtual = 0;
    dataUltimaAttValorAtual = 0;
    custoTotal = 0;
    dataUltimaAttCustoTotal = 0;
    operacoesMes = 0;
    dataUltimaAttOpMes = 0;
    operacoesTot = 0;
    dataUltimaAttOpTot = 0;
    dividendosMes = 0;
    dataUltimaAttDivMes = 0;
    dividendosTot = 0;
    dataUltimaAttDivTot = 0;
}

Carteira::~Carteira()
{
}

void Carteira::atualizaValorAtual(Cotacao *listaCotacao, unsigned int &data, unsigned int &tamVetor)
{
    dataUltimaAttValorAtual = data;
    valorAtual = 0;
    for (int i = 0; i < nAcoes; i++)
    {
        Dado Dado(acoes[i].getTicker(), data);
        unsigned int preco = listaCotacao[algoritmos::buscaBinariaDadoDataNome(listaCotacao, Dado, tamVetor)].getPrecoDoDia();
        valorAtual += (acoes[i].getQuantidadeAtual() * preco);
        acoes[i].setValorAtual(acoes[i].getQuantidadeAtual() * preco);
    }
}

unsigned int Carteira::getNumAcao() const
{
    return nAcoes;
}

int Carteira::getValorAtual(Cotacao *listaCotacao, unsigned int &data, unsigned int &tamVetor)
{
    if (data == dataUltimaAttValorAtual)
    {
        return valorAtual;
    }
    else
    {
        atualizaValorAtual(listaCotacao, data, tamVetor);
        return valorAtual;
    }
}

void Carteira::atualizaCustoTotal(const unsigned int &data)
{
    dataUltimaAttCustoTotal = data;
    custoTotal = 0;
    for (int i = 0; i < nAcoes; i++)
    {
        custoTotal += acoes[i].getCustoTotal();
    }
}

unsigned int Carteira::getCustoTotal(const unsigned int &data)
{
    if (dataUltimaAttCustoTotal == data)
    {
        return custoTotal;
    }
    else
    {
        atualizaCustoTotal(data);
        return custoTotal;
    }
}

void Carteira::atualizaDividendosTotais(const unsigned int &data)
{
    dataUltimaAttDivTot = data;
    int dividendosTot = 0;
    for (int i = 0; i < nAcoes; i++)
    {
        dividendosTot += acoes[i].getDividendosTotais();
    }
}

int Carteira::getLucroDividendosTot(unsigned int &data)
{
    if (dataUltimaAttDivTot == data)
    {
        return dividendosTot;
    }
    else
    {
        atualizaDividendosTotais(data);
        return dividendosTot;
    }
}

void Carteira::atualizaDividendosMensal(const unsigned int &data)
{
    dataUltimaAttDivMes = data;
    dividendosMes = 0;
    for (int i = 0; i < nAcoes; i++)
    {
        dividendosMes += acoes[i].getDividendosMes();
        acoes[i].setDividendosMes(0);
    }
}

int Carteira::getLucroDividendosMes(unsigned int &data)
{
    if (dataUltimaAttDivMes == data)
    {
        return dividendosMes;
    }
    else
    {
        atualizaDividendosMensal(data);
        return dividendosMes;
    }
}

void Carteira::atualizaOperacoesTotais(const unsigned int &data)
{
    dataUltimaAttOpTot = data;
    int operacoesTot = 0;
    for (int i = 0; i < nAcoes; i++)
    {
        operacoesTot += acoes[i].getOperacoesTotais();
    }
}

int Carteira::getLucroOperacoesTot(const unsigned int &data)
{
    if (dataUltimaAttOpTot == data)
    {
        return operacoesTot;
    }
    else
    {
        atualizaOperacoesTotais(data);
        return operacoesTot;
    }
}

void Carteira::atualizaOperacoesMensais(const unsigned int &data)
{   
    dataUltimaAttOpMes = data;
    operacoesMes = 0;
    for (int i = 0; i < nAcoes; i++)
    {
        operacoesMes += acoes[i].getOperacoesMes();
        acoes[i].setOperacoesMes(0);
    }
}

int Carteira::getLucroOperacoesMes(const unsigned int &data)
{
    if (dataUltimaAttOpMes == data)
    {
        return operacoesMes;
    }
    else
    {
        atualizaOperacoesMensais(data);
        return operacoesMes;
    }
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

int Carteira::getValorizacao(Cotacao *listaCotacao, unsigned int &data, unsigned int &tamVetor)
{
    return getValorAtual(listaCotacao, data, tamVetor) - getCustoTotal(data);
}

int Carteira::getTotal(Cotacao *listaCotacao, unsigned int &data, unsigned int &tamVetor)
{
    return getValorizacao(listaCotacao, data, tamVetor) + getLucroOperacoesTot(data) + getLucroDividendosTot(data);
}

int Carteira::insereAcao(const std::string &ticker)
{
    acoes[nAcoes] = Acao(ticker);
    nAcoes++;
    return nAcoes - 1;
}

Acao Carteira::getAcao(const int pos) const
{
    return acoes[pos];
}

void Carteira::ordenaVetorAcoesMes()
{
    algoritmos::mergeSortAcoesMes(acoes, nAcoes);
}

void Carteira::ordenaVetorAcoesGeral()
{
    algoritmos::mergeSortAcoesGeral(acoes, nAcoes);
}

unsigned int Carteira::executaDividendos(const Dividendo &div, const int &posAcao)
{
    double dividendoPago = ((acoes[posAcao].getQuantidadeAtual()) * (div.getValorDividendo())); //Teremos o valor double em reais que a empresa pagou de dividendos
    unsigned int dividendosPagosCentavos = static_cast<int>((dividendoPago * 100) + 0.000001);

    acoes[posAcao].setDividendosMes(acoes[posAcao].getDividendosMes() + dividendosPagosCentavos);
    acoes[posAcao].setDividendosTotais(acoes[posAcao].getDividendosTotais() + dividendosPagosCentavos);

    return dividendosPagosCentavos;
}

void Carteira::executaSplits(const Split &split, const int &posAcao)
{
    int quantidadeEmCarteira = acoes[posAcao].getQuantidadeAtual();

    quantidadeEmCarteira = quantidadeEmCarteira * split.getMultiplicador();
    quantidadeEmCarteira = quantidadeEmCarteira / split.getDivisor();

    acoes[posAcao].setQuantidadeAtual(quantidadeEmCarteira);
    acoes[posAcao].setCustoMedio(acoes[posAcao].getCustoTotal() / quantidadeEmCarteira);
}

void Carteira::executaCompra(const Operacao &op, const int &posAcao, const Cotacao *listaCotacao, const unsigned int &tamVetor)
{
    //Adiciona as acoes na carteira
    acoes[posAcao].setQuantidadeAtual(acoes[posAcao].getQuantidadeAtual() + op.getQuantOpe()); // Se compro eu adiciono a quntidade operada
    unsigned int preco = listaCotacao[algoritmos::buscaBinariaDadoDataNome(listaCotacao, op, tamVetor)].getPrecoDoDia();
    unsigned int custoOperacao = preco * op.getQuantOpe();
    //Corrige o preco total
    acoes[posAcao].setCustoTotal(acoes[posAcao].getCustoTotal() + custoOperacao);
    //Corrige o preco medio
    acoes[posAcao].setCustoMedio(acoes[posAcao].getCustoTotal() / acoes[posAcao].getQuantidadeAtual());
}

void Carteira::executaVendas(const Operacao &op, const int &posAcao, const Cotacao *listaCotacao, const unsigned int &tamVetor)
{
    //Subtraio o numero de acoes na carteira
    acoes[posAcao].setQuantidadeAtual(acoes[posAcao].getQuantidadeAtual() - op.getQuantOpe());

    unsigned int preco = listaCotacao[algoritmos::buscaBinariaDadoDataNome(listaCotacao, op, tamVetor)].getPrecoDoDia();
    unsigned int valorOperacao = preco * op.getQuantOpe();                          //Valor total em centavos vendidos
    unsigned int custoOperacao = op.getQuantOpe() * acoes[posAcao].getCustoMedio(); //Custo de compra das acoes que foram vendidas

    //Correcao do custo total
    acoes[posAcao].setCustoTotal(acoes[posAcao].getCustoTotal() - custoOperacao);
    acoes[posAcao].setOperacoesMes(acoes[posAcao].getOperacoesMes() + (valorOperacao - custoOperacao));
    acoes[posAcao].setOperacoesTotais(acoes[posAcao].getOperacoesTotais() + (valorOperacao - custoOperacao));
}

void Carteira::executaOperacoes(const Operacao &op, const int &posAcao, const Cotacao *listaCotacao, const unsigned int &tamVetor)
{
    if (op.getTipoOp() == 'C')
    {
        executaCompra(op, posAcao, listaCotacao, tamVetor);
    }
    if (op.getTipoOp() == 'V')
    {
        executaVendas(op, posAcao, listaCotacao, tamVetor);
    }
}
