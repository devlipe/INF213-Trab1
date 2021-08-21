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
    nCotacoes = cot.realizaLeitura(cotacaoCSV, this->cotacoes);
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
    nSplits = sip.realizaLeitura(splitsCSV, this->splits);
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
    nDividendos = div.realizaLeitura(dividendosCSV, this->dividendos);
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
    nOperacoes = op.realizaLeitura(operacoesCSV, this->operacoes, this->tipoExecucao);
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

void Bolsa::printDataBaseImp()
{
    std::cout << "Tipo de Execucao: " << tipoExecucao << "\n\n";

    std::cout << "SAIDA COTACOES " << nCotacoes << "\n\n";
    for (int i = 0; i < nCotacoes; i++)
    {
        cotacoes[i].printInfo();
        std::cout << "\n";
    }
    std::cout << std::setfill('=') << std::setw(30) << "\n";

    std::cout << "SAIDA DIVIDENDOS " << nDividendos << "\n\n";
    for (int i = 0; i < nDividendos; i++)
    {
        dividendos[i].printInfo();
        std::cout << "\n";
    }
    std::cout << std::setfill('=') << std::setw(30) << "\n";

    std::cout << "SAIDA OPERACOES " << nOperacoes << "\n\n";
    for (int i = 0; i < nOperacoes; i++)
    {
        operacoes[i].printInfo();
        std::cout << "\n";
    }
    std::cout << std::setfill('=') << std::setw(30) << "\n";

    std::cout << "SAIDA SPLIT " << nSplits << "\n\n";
    for (int i = 0; i < nSplits; i++)
    {
        splits[i].printInfo();
        std::cout << "\n";
    }
    std::cout << std::setfill('=') << std::setw(30) << "\n";
}

void Bolsa::printDataBase()
{
    return getInstance().printDataBaseImp();
}