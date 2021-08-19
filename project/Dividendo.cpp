#include "Dividendo.h"

Dividendo::Dividendo(std::string ticker, std::string date, double valor)
    : Dado(ticker, date)
{
    valorDividendo = valor;
}

Dividendo::~Dividendo()
{
}

unsigned int Dividendo::getValorDividendo() const 
{
    return valorDividendo;
}

void Dividendo::realizaLeitura(std::ifstream &arquivoFonte, Dividendo * arrayDividendo) const
{
    std::string linha;
    std::string dados[10] = {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"};

    int i = 0;
    while (std::getline(arquivoFonte, linha))
    {
        Dado::parsingLinha(linha, dados);
        arrayDividendo[i] = Dividendo(dados[0], dados[1], stod(dados[3]));
        i++;
    }
    return;
}