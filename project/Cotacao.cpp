
#include "Cotacao.h"

Cotacao::Cotacao(std::string ticker, std::string data, double valor)
    : Dado(ticker, data)
{
    precoDoDia = static_cast<int>((valor * 100)+ 0.000001); // transformando para centavos
}

Cotacao::~Cotacao()
{
}

unsigned int Cotacao::getPrecoDoDia() const
{
    return precoDoDia;
}

void Cotacao::realizaLeitura(std::ifstream &arquivoFonte, Cotacao *arrayCotacao) const
{
    std::string linha;
    std::string dados[10] = {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"};

    int i = 0;
    while (std::getline(arquivoFonte, linha))
    {
        Dado::parsingLinha(linha, dados);
        arrayCotacao[i] = Cotacao(dados[0], dados[1], stod(dados[5]));
        i++;
    }
    return;
}
