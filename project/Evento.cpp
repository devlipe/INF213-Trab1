#include "Evento.h"

Evento::Evento() : Dado()
{
    //Criamos um evento com tipo 6, por se tratar de um tipo invalido, e maior que os demais, logo sempre ficaria no final no caso de uma ordenacao com tal parametro
    tipoEvento = 6;
    posicaoVetor = 0;
}

Evento::Evento(const Dividendo &div, const unsigned int &pVetor)
    : Dado(div.getTicker(), div.getDateInt())

{
    tipoEvento = 1;
    posicaoVetor = pVetor;
}

Evento::Evento(const Dividendo &div)
    : Dado(div.getTicker(), div.getDateInt())

{
    tipoEvento = 4;
    posicaoVetor = 0;
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
    tipoEvento = 5;
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
    std::string tipo = (tipoEvento == 1) ? "Dividendo 1" : (tipoEvento == 2) ? "Split 2"
                                                       : (tipoEvento == 3)   ? "Operacao 3"
                                                       : (tipoEvento == 4)   ? "Reinvestir 4"
                                                       : (tipoEvento == 5)   ? "Impressao 5"
                                                                             : "evento sem tipo";
    std::cout << "Tipo de evento: " << tipo << std::endl;
    std::cout << "Posicao no Vetor: " << posicaoVetor << std::endl;
}