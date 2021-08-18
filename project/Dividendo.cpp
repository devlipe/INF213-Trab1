#include "Dividendo.h"

Dividendo::Dividendo(std::string ticker, std::string date, double valor)
    : Dado(ticker, date)
{
    valorDividendo = static_cast<int>((valor + 0.000001) * 100000);
}

Dividendo::~Dividendo()
{
}

unsigned int Dividendo::getValorDividendo() const 
{
    return valorDividendo;
}