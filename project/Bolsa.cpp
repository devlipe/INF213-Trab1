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
}

void Bolsa::printDataBase()
{
    return getInstance().printDataBaseImp();
}

void Bolsa::organizaDataBaseImp()
{
    algoritmos::quickSortDadoDataCres(historicoCotacoes, nCotacoes);
    algoritmos::mergeSortDadoDataCres(listaOperacoes, nOperacoes); //Precisamos ordenar para saber a data da primeira compra
    ///algoritmos::quickSortDadoDataCres(historicoDividendos, nDividendos);
    //algoritmos::quickSortDadoDataCres(historicoSplits, nSplits);
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
    adicionaDividendosAosEventos(nEventos);

    adicionaSplitsAosEventos(nEventos);

    adicionaOperacoesAosEventos(nEventos);

    adicionaImpressoesAosEventos(nEventos);

    algoritmos::mergeSortDadoDataCres(listaEventos, nEventos);
}

void Bolsa::impressaoTipoM(Evento &evento)
{
    std::cout << "Fechamento do mes (" << evento.getMesInt() << ")\n";
    std::cout << std::left << std::setw(50) << "Lucro total do mes:" << std::right << std::setw(15) << carteira.getLucroDividendosMes() / 100 << std::setw(15) << carteira.getLucroOperacoesMes() / 100 << std::endl;
}

void Bolsa::simulaDividendos(Evento &evento)
{
    int posAcao = carteira.procuraAcao(evento.getTicker());
    if (posAcao < 0)
    {
        return; /// Se nao tenho o acao do dividendo em questao, somente ignoro
    }
    ///Se eu tiver o dividendo em questao, eu executo
    //TODO: parei aqui
    carteira.executaDividendos(historicoDividendos[evento.getPosicaoVetor()], posAcao);
}

void Bolsa::simulaSplits(Evento &evento)
{
    int posAcao = carteira.procuraAcao(evento.getTicker());
    if (posAcao < 0)
    {
        return; /// Se nao tenho o split da acao em questao, somente ignoro
    }
    
}

void Bolsa::simulaOperacoes(Evento &evento)
{
    int posAcao = carteira.procuraAcao(evento.getTicker());
    if (posAcao < 0)
    {
        posAcao = carteira.insereAcaoAlfa(evento.getTicker()); /// Se nao possuo a acao, e se trata de uma compra, eu insiro no vetor de acoes
    }
}

//TODO:Parei aqui (Implementacao da funcao simula para gerar os resultados necessarios)
void Bolsa::simula(Evento &evento)
{
    if (evento.getTipoEvento() == 1) //Caso de dividendos
    {
        simulaDividendos(evento);
        return;
    }
    if (evento.getTipoEvento() == 2) //Caso de splits
    {
        simulaSplits(evento);
        return;
    }
    if (evento.getTipoEvento() == 3) //Caso de Operacoes
    {
        simulaOperacoes(evento);
        return;
    }
}

void Bolsa::executaEventosM()
{
    for (int i = 0; i < nEventos; i++)
    {
        if (listaEventos[i].getTipoEvento() == 4)
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
        /* code */
        break;
    case 'D':
        /* code */
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