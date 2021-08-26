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
    tenhoDividendosParaReinvestir = false;
    nOperacoesReinvestir = false;
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
    dividendosTot = 0;
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
    operacoesTot = 0;
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

bool Carteira::TenhoDividendosParaReinvestir() const
{
    return tenhoDividendosParaReinvestir;
}

unsigned int Carteira::getNumDividendos() const
{
    return nOperacoesReinvestir;
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

int Carteira::procuraOperacaoReinvestir(const std::string ticker)
{
    for (int i = 0; i < nOperacoesReinvestir; i++)
    {
        if (ticker == operacoesParaReinvestir[i].getTicker())
        {
            return i;
        }
    }
    return -1;
}

void Carteira::insereOperacaoReinvestir(const Operacao &op)
{
    int posOp = procuraOperacaoReinvestir(op.getTicker());

    if (posOp < 0)
    {
        operacoesParaReinvestir[nOperacoesReinvestir] = op;
        nOperacoesReinvestir++;
        tenhoDividendosParaReinvestir = true;
        return;
    }
    unsigned int total = operacoesParaReinvestir[posOp].getQuantOpe() + op.getQuantOpe();
    operacoesParaReinvestir[posOp].setQuantidadeOperada(total);

    tenhoDividendosParaReinvestir = true;
}

unsigned int Carteira::executaDividendos(const Dividendo &div, const int &posAcao)
{
    double dividendoPago = ((acoes[posAcao].getQuantidadeAtual()) * (div.getValorDividendo() * 100)); //Teremos o valor double em centavos que a empresa pagou de dividendos
    unsigned int dividendosPagosInteiros = static_cast<int>((dividendoPago ) + 0.000001);

    acoes[posAcao].setDividendosMes(acoes[posAcao].getDividendosMes() + dividendosPagosInteiros);
    acoes[posAcao].setDividendosTotais(acoes[posAcao].getDividendosTotais() + dividendosPagosInteiros);

    return dividendosPagosInteiros;
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
    acoes[posAcao].setCustoMedio(static_cast<double>(acoes[posAcao].getCustoTotal()) / static_cast<double>(acoes[posAcao].getQuantidadeAtual()));
}

void Carteira::executaCompra(const Operacao &op, const int &posAcao, const unsigned int &preco)
{
    //Adiciona as acoes na carteira
    acoes[posAcao].setQuantidadeAtual(acoes[posAcao].getQuantidadeAtual() + op.getQuantOpe()); // Se compro eu adiciono a quntidade operada
    unsigned int custoOperacao = preco * op.getQuantOpe();
    //Corrige o preco total
    acoes[posAcao].setCustoTotal(acoes[posAcao].getCustoTotal() + custoOperacao);
    //Corrige o preco medio
    acoes[posAcao].setCustoMedio(static_cast<double>(acoes[posAcao].getCustoTotal()) / static_cast<double>(acoes[posAcao].getQuantidadeAtual()));
}

void Carteira::executaVendas(const Operacao &op, const int &posAcao, const Cotacao *listaCotacao, const unsigned int &tamVetor)
{
    unsigned int quantidadeAnterior = acoes[posAcao].getQuantidadeAtual();
    //Subtraio o numero de acoes na carteira
    acoes[posAcao].setQuantidadeAtual( quantidadeAnterior - op.getQuantOpe());

    unsigned int preco = listaCotacao[algoritmos::buscaBinariaDadoDataNome(listaCotacao, op, tamVetor)].getPrecoDoDia();
    unsigned int valorOperacao = preco * op.getQuantOpe();                          //Valor total em centavos vendidos
    unsigned int novoCustoTotal = ((acoes[posAcao].getQuantidadeAtual() * acoes[posAcao].getCustoTotal()) / quantidadeAnterior);

    unsigned int custoOperacao = acoes[posAcao].getCustoTotal() - novoCustoTotal; //Custo de compra das acoes que foram vendidas
    //Correcao do custo total
    acoes[posAcao].setCustoTotal(novoCustoTotal);
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

void Carteira::executaReinvestimentoDeDividendos(Cotacao *listaCotacao, const unsigned int &tamVetor)
{
    for (int i = 0; i < nOperacoesReinvestir; i++)
    {
        unsigned int preco = listaCotacao[algoritmos::buscaBinariaDadoDataNome(listaCotacao, operacoesParaReinvestir[i], tamVetor)].getPrecoDoDia();

        operacoesParaReinvestir[i].setQuantidadeOperada(operacoesParaReinvestir[i].getQuantOpe() / preco);

        int posAcao = procuraAcao(operacoesParaReinvestir[i].getTicker());
        executaCompra(operacoesParaReinvestir[i], posAcao, preco);
        operacoesParaReinvestir[i].setQuantidadeOperada(0);
    }
    tenhoDividendosParaReinvestir = false;
    nOperacoesReinvestir = 0;
}
