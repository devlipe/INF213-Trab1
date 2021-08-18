
#include "Cotacao.h"

Cotacao::Cotacao(std::string ticker, std::string data, double valor)
: Dado(ticker, data)
{
    precoDoDia = static_cast<int>((valor + 0.000001) * 100); // transformando para centavos
}

Cotacao::~Cotacao()
{
}

unsigned int Cotacao::getPrecoDoDia() const
{
    return precoDoDia;
}
