#pragma once

#include "Dado.h"


class Cotacao : public Dado
{
private:
    // O preco da acao e guardado em centavos 
    unsigned int precoDoDia;
public:
    //* Construtor e Destrutor
    Cotacao(std::string ticker, std::string data, double valor);
    ~Cotacao();

    //* Getters and Setters
    
    ///Retorna um valor em centavos (unsigned int)
    unsigned int getPrecoDoDia() const;
    
    //*Funcoes de uso do Programa

    void realizaLeitura(std::ifstream &arquivoFonte, Cotacao * arrayCotacao) const;

};
