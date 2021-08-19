
#include "Operacao.h"

Operacao::Operacao(std::string ticker, std::string date, char tipoOp, unsigned int quantidade)
    : Dado(ticker, date)
{
    this->tipoOp = tipoOp;
    quantidadeOperada = quantidade;
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

char *Operacao::realizaLeitura(std::ifstream &arquivoFonte, Operacao *arrayOperacao) const
{
    char tipoExecucao[2];
    arquivoFonte >> tipoExecucao;
    std::string linha;
    std::string dados[10] = {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"};

    int i = 0;
    while (std::getline(arquivoFonte, linha))
    {
        Dado::parsingLinha(linha, dados);
        arrayOperacao[i] = Operacao(dados[2], dados[0], dados[1][1], std::stoul(dados[3]));
        i++;
    }

    return tipoExecucao;
}