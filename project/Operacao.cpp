
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