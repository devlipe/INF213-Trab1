#include "Split.h"

Split::Split(std::string ticker, std::string data, std::string indice)
    : Dado(ticker, data)
{
    try
    {
        int i = indice.find(':');
        divisor = stoi(indice.substr(i + 1));
        multiplicador = stoi(indice.substr(0, i));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

Split::Split() : Dado()
{
    multiplicador = 0;
    divisor = 0;
}

Split::~Split()
{
}

unsigned int Split::getMultiplicador() const
{
    return multiplicador;
}

unsigned int Split::getDivisor() const
{
    return divisor;
}

unsigned int Split::realizaLeitura(std::ifstream &arquivoFonte, Split *arraySplit) const
{
    std::string linha;
    std::string dados[10] = {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"};

    int i = 0;
    while (std::getline(arquivoFonte, linha))
    {
        Dado::parsingLinha(linha, dados);
        arraySplit[i] = Split(dados[0], dados[1], dados[2]);
        i++;
    }
    return i;
}

void Split::printInfo() const
{
    Dado::printInfo();
    std::cout << "Indice: " << multiplicador << ":" << divisor << "\n";
}
