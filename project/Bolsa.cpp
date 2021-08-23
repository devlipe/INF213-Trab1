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

//TODO: Remover antes de entregar o trabalho (usado somente para debugger)
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
}

void Bolsa::printDataBase()
{
    return getInstance().printDataBaseImp();
}

void Bolsa::organizaDataBaseImp()
{
    algoritmos::quickSortDadoDataCres(historicoCotacoes, nCotacoes);

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
        int posicaoArray = algoritmos::buscaBinariaDado(historicoCotacoes, listaOperacoes[i], nCotacoes);
        std::cout << historicoCotacoes[posicaoArray].getPrecoDoDia() << std::endl;
    }
    
}

void Bolsa::executaTrabalhoImp()
{
    switch (tipoExecucao[0])
    {
    case 'Q':
        executaComandoQ();
        break;
    case 'F':
        /* code */
        break;
    case 'M':
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