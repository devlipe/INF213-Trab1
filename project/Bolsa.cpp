#include "Bolsa.h"

Bolsa::~Bolsa()
{
}

void Bolsa::leCotacoes(const char *cotacoesPath)
{
    ///Realiza leitura do arquivo de cotacoes
    std::ifstream cotacaoCSV(cotacoesPath);
    if (!cotacaoCSV.is_open())
    {
        std::cerr << "Arquivo precos nao aberto!\n";
        exit(1);
    }
    Cotacao cot;
    nCotacoes = cot.realizaLeitura(cotacaoCSV, this->historicoCotacoes);
    cotacaoCSV.close();
}

void Bolsa::leSplits(const char *splitsPath)
{
    std::ifstream splitsCSV(splitsPath);
    if (!splitsCSV.is_open())
    {
        std::cerr << "Arquivo split nao aberto!\n";
        exit(1);
    }
    Split sip;
    nSplits = sip.realizaLeitura(splitsCSV, this->historicoSplits);
    splitsCSV.close();
}

void Bolsa::leDividendos(const char *dividendosPath)
{
    std::ifstream dividendosCSV(dividendosPath);
    if (!dividendosCSV.is_open())
    {
        std::cerr << "Arquivo dividendos nao aberto!\n";
        exit(1);
    }
    Dividendo div;
    nDividendos = div.realizaLeitura(dividendosCSV, this->historicoDividendos);
    dividendosCSV.close();
}

void Bolsa::leOperacoes(const char *operacoesPath)
{
    std::ifstream operacoesCSV(operacoesPath);
    if (!operacoesCSV.is_open())
    {
        std::cerr << "Arquivo opreracoes nao aberto!\n";
        exit(1);
    }
    Operacao op;
    nOperacoes = op.realizaLeitura(operacoesCSV, this->listaOperacoes, this->tipoExecucao);
    operacoesCSV.close();
}

void Bolsa::leArquivosImp(const char **files)
{
    leCotacoes(files[1]);

    leSplits(files[2]);

    leDividendos(files[3]);

    leOperacoes(files[4]);
}

void Bolsa::leArquivos(const char **files)
{
    return getInstance().leArquivosImp(files);
}

void Bolsa::printDataBaseImp() const
{

    std::cout << "Tipo de Execucao: " << tipoExecucao << "\n\n";

    std::cout << "SAIDA COTACOES " << nCotacoes << "\n\n";
    for (int i = 0; i < nCotacoes; i++)
    {
        historicoCotacoes[i].printInfo();
        std::cout << "\n";
    }
    std::cout << std::setfill('=') << std::setw(30) << "\n";

    std::cout << "SAIDA DIVIDENDOS " << nDividendos << "\n\n";
    for (int i = 0; i < nDividendos; i++)
    {
        historicoDividendos[i].printInfo();
        std::cout << "\n";
    }
    std::cout << std::setfill('=') << std::setw(30) << "\n";

    std::cout << "SAIDA OPERACOES " << nOperacoes << "\n\n";
    for (int i = 0; i < nOperacoes; i++)
    {
        listaOperacoes[i].printInfo();
        std::cout << "\n";
    }
    std::cout << std::setfill('=') << std::setw(30) << "\n";

    std::cout << "SAIDA SPLIT " << nSplits << "\n\n";
    for (int i = 0; i < nSplits; i++)
    {
        historicoSplits[i].printInfo();
        std::cout << "\n";
    }
    std::cout << std::setfill('=') << std::setw(30) << "\n";

    std::cout << "SAIDA EVENTOS" << nEventos << std::endl;

    for (int i = 0; i < nEventos; i++)
    {
        listaEventos[i].printInfo();
        std::cout << std::endl;
    }
    std::cout << std::setfill('=') << std::setw(30) << "\n";

    std::cout << "SAIDA ACOES COMPRADAS " << carteira.getNumAcao() << std::endl;

    for (int i = 0; i < carteira.getNumAcao(); i++)
    {
        carteira.getAcao(i).printInfo();
        std::cout << std::endl;
    }
}

void Bolsa::printDataBase()
{
    return getInstance().printDataBaseImp();
}

void Bolsa::organizaDataBaseImp()
{
    algoritmos::quickSortDadoDataCres(historicoCotacoes, nCotacoes);
}

void Bolsa::organizaDataBase()
{
    return getInstance().organizaDataBaseImp();
}

void Bolsa::executaComandoQ() const
{
    for (int i = 0; i < nOperacoes; i++)
    {
        int posicaoArray = algoritmos::buscaBinariaDadoDataNome(historicoCotacoes, listaOperacoes[i], nCotacoes);
        std::cout << historicoCotacoes[posicaoArray].getPrecoDoDia() << std::endl;
    }
}

void Bolsa::adicionaOperacoesAosEventos(unsigned int &nEventos)
{
    for (int i = 0; i < nOperacoes; i++)
    {
        listaEventos[nEventos] = Evento(listaOperacoes[i], i);
        nEventos++;
    }
}

void Bolsa::adicionaSplitsAosEventos(unsigned int &nEventos)
{
    for (int i = 0; i < nSplits; i++)
    {
        listaEventos[nEventos] = Evento(historicoSplits[i], i);
        nEventos++;
    }
}

void Bolsa::adicionaDividendosAosEventos(unsigned int &nEventos)
{
    for (int i = 0; i < nDividendos; i++)
    {
        listaEventos[nEventos] = Evento(historicoDividendos[i], i);
        nEventos++;
        if (tipoExecucao[1] == 'R') /// Caso tenhamos que reinvestir os dividendos, adicionaremos os eventos de reinvestir
        {
            listaEventos[nEventos] = Evento(historicoDividendos[i]);
            nEventos++;
        }
    }
}

void Bolsa::adicionaImpressoesAosEventos(unsigned int &nEventos)
{
    for (int i = 0; i < nCotacoes - 1; i++)
    {
        if (historicoCotacoes[i].getMesInt() != historicoCotacoes[i + 1].getMesInt())
        {
            listaEventos[nEventos] = Evento(historicoCotacoes[i].getDateInt());
            nEventos++;
        }
    }
    listaEventos[nEventos] = Evento(historicoCotacoes[nCotacoes - 1].getDateInt()); ///Adiciono a ultima data no vetor de eventos
    nEventos++;
}

void Bolsa::montaVetorEventos()
{
    algoritmos::mergeSortDadoDataCres(listaOperacoes, nOperacoes); //Precisamos ordenar para saber a data da primeira compra

    adicionaDividendosAosEventos(nEventos);

    adicionaSplitsAosEventos(nEventos);

    adicionaOperacoesAosEventos(nEventos);

    adicionaImpressoesAosEventos(nEventos);

    algoritmos::mergeSortEventoTipo(listaEventos, nEventos);
}

void Bolsa::impressaoTipoM(Evento &evento)
{
    unsigned int data = evento.getDateInt();
    std::cout << "Fechamento do mes (" << evento.getDateStringSallistica() << ")\n";
    std::cout << std::left << std::setw(50) << "Lucro total do mes:" << std::right << std::setw(15) << carteira.getLucroDividendosMes(data) / 100 << std::setw(15) << carteira.getLucroOperacoesMes(data) / 100 << std::endl;
}

void Bolsa::simulaReinvestirDividendos()
{
    if (!carteira.TenhoDividendosParaReinvestir())
    {
        return;
    }
    carteira.executaReinvestimentoDeDividendos(historicoCotacoes, nCotacoes);
}

void Bolsa::adicionaDividendosParaReinvestir(const unsigned int &valorPago, const Evento &evento)
{
    Operacao opReinvestir(evento.getTicker(), evento.getDateString(), 'C', valorPago);
    carteira.insereOperacaoReinvestir(opReinvestir);
}

void Bolsa::simulaDividendos(const Evento &evento)
{
    int posAcao = carteira.procuraAcao(evento.getTicker());
    if (posAcao < 0)
    {
        return; /// Se nao tenho o acao do dividendo em questao, somente ignoro
    }
    ///Se eu tiver a acao do dividendo em questao, eu executo
    unsigned int divPagos = carteira.executaDividendos(historicoDividendos[evento.getPosicaoVetor()], posAcao);

    if (tipoExecucao[1] == 'R') /// Pergunta se e necessario reinvestir os dividendos
    {
        adicionaDividendosParaReinvestir(divPagos, evento);
    }
}

void Bolsa::simulaSplits(const Evento &evento)
{
    int posAcao = carteira.procuraAcao(evento.getTicker());
    if (posAcao < 0)
    {
        return; /// Se nao tenho a acao do split em questao, somente ignoro
    }
    ///se possuo, eu executo
    carteira.executaSplits(historicoSplits[evento.getPosicaoVetor()], posAcao);
}

void Bolsa::simulaOperacoes(const Evento &evento)
{
    int posAcao = carteira.procuraAcao(evento.getTicker());
    if (posAcao < 0)
    {
        posAcao = carteira.insereAcao(evento.getTicker()); /// Se nao possuo a acao, e se trata de uma compra, eu insiro no vetor de acoes
    }
    carteira.executaOperacoes(listaOperacoes[evento.getPosicaoVetor()], posAcao, historicoCotacoes, nCotacoes);
}

void Bolsa::simula(const Evento &evento)
{
    if (evento.getTipoEvento() == 1) //Caso de dividendos
    {
        simulaDividendos(evento);
        return;
    }
    if (evento.getTipoEvento() == 2) //Caso de splits
    {
        simulaSplits(evento);
    }
    if (evento.getTipoEvento() == 3) //Caso de Operacoes
    {
        simulaOperacoes(evento);
    }
    if (evento.getTipoEvento() == 4) ///Reinvestir dividendos
    {
        simulaReinvestirDividendos();
    }
}

void Bolsa::executaEventosM()
{
    for (int i = 0; i < nEventos; i++)
    {
        if (listaEventos[i].getTipoEvento() == 5) //Caso seja uma impressao
        {
            if ((listaOperacoes[0].getDateInt()) < (listaEventos[i].getDateInt()))
            {
                impressaoTipoM(listaEventos[i]);
            }
        }
        else
        {
            simula(listaEventos[i]);
        }
    }
}

void Bolsa::executaComandoM()
{
    montaVetorEventos();
    executaEventosM();
}

void Bolsa::executaEventosF()
{
    for (int i = 0; i < nEventos; i++)
    {
        if (listaEventos[i].getTipoEvento() < 5) /// Nao queremos eventos do tipo impressao, uma vez que o tipo F tem somente uma impressao no final
        {
            simula(listaEventos[i]);
        }
    }
}

void Bolsa::impressaoTipoF(Evento &evento)
{
    unsigned int data = evento.getDateInt();

    std::cout << std::left << std::setw(29) << "Totais no final da simulacao:" << std::right
              << std::setw(14) << carteira.getValorAtual(historicoCotacoes, data, nCotacoes) / 100
              << std::setw(15) << carteira.getCustoTotal(data) / 100
              << std::setw(15) << carteira.getValorizacao(historicoCotacoes, data, nCotacoes) / 100
              << std::setw(15) << carteira.getLucroOperacoesTot(data) / 100
              << std::setw(15) << carteira.getLucroDividendosTot(data) / 100
              << std::setw(15) << carteira.getTotal(historicoCotacoes, data, nCotacoes) / 100
              << std::endl
              << std::endl;
}

void Bolsa::executaComandoF()
{
    montaVetorEventos();
    executaEventosF();
    impressaoTipoF(listaEventos[nEventos - 1]); //O ultimo evento e obrigatoriamente uma impressao, logo consigo chama-la para atualizar os dados;
}

void Bolsa::impressaoTipoDTabela1(Evento &evento, unsigned int &data)
{
    std::cout << std::string(110, '+') << std::endl
              << std::endl;

    std::cout << "Fechamento do mes (" << evento.getDateStringSallistica() << ")" << std::endl;

    std::cout << std::string(80, '-') << std::endl;

    std::cout << "Acao      Quantidade    Valor Atual    Custo Total     Dividendos      Operacoes" << std::endl;

    for (int i = 0; i < carteira.getNumAcao(); i++)
    {
        std::cout << std::left << std::setw(6) << carteira.getAcao(i).getTicker()
                  << std::right << std::setw(14) << carteira.getAcao(i).getQuantidadeAtual()
                  << std::setw(15) << carteira.getAcao(i).getValorAtual() / 100
                  << std::setw(15) << carteira.getAcao(i).getCustoTotal() / 100
                  << std::setw(15) << carteira.getAcao(i).getDividendosMes() / 100
                  << std::setw(15) << carteira.getAcao(i).getOperacoesMes() / 100
                  << std::endl;
    }

    std::cout << std::string(80, '-') << std::endl;
    std::cout << std::left
              << std::setw(50) << "Lucro total do mes:"
              << std::right
              << std::setw(15) << carteira.getLucroDividendosMes(data) / 100
              << std::setw(15) << carteira.getLucroOperacoesMes(data) / 100
              << std::endl
              << std::endl;
}

void Bolsa::impressaoTipoDTabela2(Evento &evento, unsigned int &data)
{
    std::cout << "Totais ate hoje:\n";
    std::cout << std::string(110, '-') << std::endl;
    std::cout << "Acao      Quantidade    Valor Atual    Custo Total    Valorizacao      Operacoes     Dividendos          Total" << std::endl;
    for (int i = 0; i < carteira.getNumAcao(); i++)
    {
        std::cout << std::left << std::setw(6) << carteira.getAcao(i).getTicker()
                  << std::right << std::setw(14) << carteira.getAcao(i).getQuantidadeAtual()
                  << std::setw(15) << carteira.getAcao(i).getValorAtual() / 100
                  << std::setw(15) << carteira.getAcao(i).getCustoTotal() / 100
                  << std::setw(15) << carteira.getAcao(i).getValorizacao() / 100
                  << std::setw(15) << carteira.getAcao(i).getOperacoesTotais() / 100
                  << std::setw(15) << carteira.getAcao(i).getDividendosTotais() / 100
                  << std::setw(15) << carteira.getAcao(i).getLucroTotalGeral() / 100
                  << std::endl;
    }
    std::cout << std::string(110, '-') << std::endl;
    std::cout << std::left
              << std::setw(21) << "Totais ate o momento:"
              << std::right
              << std::setw(14) << carteira.getValorAtual(historicoCotacoes, data, nCotacoes) / 100
              << std::setw(15) << carteira.getCustoTotal(data) / 100
              << std::setw(15) << carteira.getValorizacao(historicoCotacoes, data, nCotacoes) / 100
              << std::setw(15) << carteira.getLucroOperacoesTot(data) / 100
              << std::setw(15) << carteira.getLucroDividendosTot(data) / 100
              << std::setw(15) << carteira.getTotal(historicoCotacoes, data, nCotacoes) / 100
              << std::endl
              << std::endl;
}

void Bolsa::impressaoTipoD(Evento &evento)
{
    /// Funcoes que devem ser chamadas para a correta saida do metodo D
    unsigned int data = evento.getDateInt();
    carteira.atualizaValorAtual(historicoCotacoes, data, nCotacoes);
    //Ordeno para saida da primeira tabela
    carteira.ordenaVetorAcoesMes();
    impressaoTipoDTabela1(evento, data);

    //Ordeno para saida da segunda tabela
    carteira.ordenaVetorAcoesGeral();
    impressaoTipoDTabela2(evento, data);
}

void Bolsa::executaEventosD()
{
    for (int i = 0; i < nEventos; i++)
    {
        if (listaEventos[i].getTipoEvento() == 5) //Caso seja uma impressao
        {
            if ((listaOperacoes[0].getDateInt()) < (listaEventos[i].getDateInt())) // So iremos comecar a imprimir a partir da primeira data de compra
            {
                impressaoTipoD(listaEventos[i]);
            }
        }
        else
        {
            simula(listaEventos[i]);
        }
    }
}

void Bolsa::executaComandoD()
{
    montaVetorEventos();
    executaEventosD();
}

void Bolsa::executaTrabalhoImp()
{
    switch (tipoExecucao[0])
    {
    case 'Q':
        executaComandoQ();
        break;
    case 'M':
        executaComandoM();
        break;
    case 'F':
        executaComandoF();
        break;
    case 'D':
        executaComandoD();
        break;
    default:
        std::cerr << "Tipo de Execucao nao econtrado" << std::endl;
        break;
    }
}

void Bolsa::executaTrabalho()
{
    return getInstance().executaTrabalhoImp();
}