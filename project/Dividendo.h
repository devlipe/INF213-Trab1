#pragma once

#include "Dado.h"

class Dividendo : public Dado
{
private:
    ///Dados de dividendos sao armazenados na base 10^-5 reais (Centesimo de milesimo)
    double valorDividendo;

public:
    //* Construtor e Destrutor
    Dividendo(std::string ticker, std::string date, double valor);
    ~Dividendo();

    //* Getters and Setters

    ///Retorna o valor em centesimos de milesimos de reais que a empresa pagou em dividendos
    unsigned int getValorDividendo() const;

    //*Funcoes de uso do Programa
    ///Realiza a leitura de um arquivo de dividendos e os coloca em um vetor;
    void realizaLeitura(std::ifstream &arquivoFonte, Dividendo * arrayDividendo) const;
};
