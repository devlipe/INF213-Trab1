
#include "Operacao.h"

Operacao::Operacao(std::string ticker, std::string date, char tipoOp, unsigned int quantidade)
    : Dado(ticker, date)
{
    this->tipoOp = tipoOp;
    quantidadeOperada = quantidade;
}

Operacao::Operacao() : Dado()
{
    tipoOp = '0';
    quantidadeOperada = 0;
}

Operacao::~Operacao()
{
}

char Operacao::getTipoOp() const
{
    return tipoOp;
}

unsigned int Operacao::getQuantOpe() const
{
    return quantidadeOperada;
}

unsigned int Operacao::realizaLeitura(std::ifstream &arquivoFonte, Operacao *arrayOperacao, char tipoExecucao[]) const
{
    arquivoFonte.getline(tipoExecucao, 2);
    std::string linha;
    std::string dados[10] = {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"};

    int i = 0;
    while (std::getline(arquivoFonte, linha))
    {
        Dado::parsingLinha(linha, dados);
        arrayOperacao[i] = Operacao(dados[2], dados[0], dados[1][0], std::stoul(dados[3]));
        i++;
    }
    return i;
}

void Operacao::printInfo() const
{
    Dado::printInfo();
    std::cout << "Tipo de Operacao: " << tipoOp << "\n";
    std::cout << "Quantidade Operada: " << quantidadeOperada << "\n";
}