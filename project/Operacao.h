#pragma once

#include "Dado.h"

class Operacao : public Dado
{
private:
    char tipoOp; //Operacoes de (C)ompra, (V)enda e (Q)consultas
    unsigned int quantidadeOperada;

public:

    //* Construtor e Destrutor
    Operacao(std::string ticker, std::string date, char TipoOp, unsigned int quantidade);
    ~Operacao();

    // * Getters and Setters

    ///Retorna um valor ((C)ompra, (V)enda e (Q)consultas), como char
    char getTipoOp() const;
    ///Retorna a quantidade de acoes que a operacao trabalha, operacoes do tipo Q, retornam 0
    unsigned int getQuantOpe() const;

    //*Funcoes de uso do Programa
    ///Realiza a leitura das operacoes e retorna a expecificacao de execucao ((D,Q,M,F)R)
    char * realizaLeitura(std::ifstream &arquivoFonte, Operacao * arrayOperacao) const;

};
