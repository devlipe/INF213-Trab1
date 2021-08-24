#include "Evento.h"

Evento::Evento() : Dado()
{
    //Criamos um evento com tipo 5, por se tratar de um tipo invalido, e maior que os demais, logo sempre ficaria no final no caso de uma ordenacao com tal parametro
    tipoEvento = 5;
    posicaoVetor = 0;
}

Evento::Evento(const Dividendo &div, const unsigned int &pVetor)
    : Dado(div.getTicker(), div.getDateInt())

{
    tipoEvento = 1;
    posicaoVetor = pVetor;
}

Evento::Evento(const Split &split, const unsigned int &pVetor)
    : Dado(split.getTicker(), split.getDateInt())

{
    tipoEvento = 2;
    posicaoVetor = pVetor;
}

Evento::Evento(const Operacao &ope, const unsigned int &pVetor)
    : Dado(ope.getTicker(), ope.getDateInt())

{
    tipoEvento = 3;
    posicaoVetor = pVetor;
}

Evento::Evento(const unsigned int &data)
    : Dado("IMPR3", data)

{
    tipoEvento = 4;
    posicaoVetor = 0;
}

Evento::~Evento()
{
}

unsigned int Evento::getTipoEvento() const
{
    return tipoEvento;
}

unsigned int Evento::getPosicaoVetor() const
{
    return posicaoVetor;
}

void Evento::printInfo() const
{
    Dado::printInfo();
    std::cout << "Tipo de evento {1:Dividendo, 2:Split, 3:Operacao, 4:Impressao}: " << tipoEvento << std::endl;
    std::cout << "Posicao no Vetor: " << posicaoVetor << std::endl;
}