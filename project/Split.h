#pragma once

#include "Dado.h"

class Split : public Dado
{
private:
    unsigned int multiplicador;
    unsigned int divisor;

public:
    //* Construtor e Destrutor
    Split(std::string ticker, std::string data, std::string indice);
    Split();
    ~Split();

    //* Getters e Setters
    //Multiplicador do split (primeiro numero da razao)
    unsigned int getMultiplicador() const;
    //Divisor do split (segundo numero da razao)
    unsigned int getDivisor() const;

    //*Funcoes de uso do Programa

    ///Realiza a leitura do arquvio CSV
    unsigned int realizaLeitura(std::ifstream &arquivoFonte, Split *arraySplit) const;
    ///Faz o print das informacoes de um split (Junto com o print do dado)
    void printInfo() const override;
};
