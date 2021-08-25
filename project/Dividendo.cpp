#include "Dividendo.h"

Dividendo::Dividendo(std::string ticker, std::string date, double valor)
    : Dado(ticker, date)
{
    valorDividendo = valor;
}

Dividendo::Dividendo() : Dado()
{
    valorDividendo = 0;
}

Dividendo::~Dividendo()
{
}

double Dividendo::getValorDividendo() const
{
    return valorDividendo;
}

unsigned int Dividendo::realizaLeitura(std::ifstream &arquivoFonte, Dividendo *arrayDividendo) const
{
    std::string linha;
    std::string dados[10] = {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"};

    int i = 0;
    while (std::getline(arquivoFonte, linha))
    {
        Dado::parsingLinha(linha, dados);
        arrayDividendo[i] = Dividendo(dados[0], dados[1], stod(dados[2]));
        i++;
    }
    return i;
}

void Dividendo::printInfo() const
{
    Dado::printInfo();
    std::cout << "Valor do Dividendo: " << valorDividendo << "\n";
}