#pragma once

#include "Dado.h"
#include "iostream"

class Split : public Dado
{
private:
    unsigned int multiplicador;
    unsigned int divisor;
public:
    //* Construtor e Destrutor
    Split(std::string ticker, std::string data, std::string indice);
    ~Split();

    //* Getters e Setters
    //Multiplicador do split (primeiro numero da razao)
    unsigned int getMultiplicador() const;
    //Divisor do split (segundo numero da razao)
    unsigned int getDivisor() const;
};
