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
    Operacao();
    ~Operacao();

    // * Getters and Setters

    ///Retorna um valor ((C)ompra, (V)enda e (Q)consultas), como char
    char getTipoOp() const;
    ///Retorna a quantidade de acoes que a operacao trabalha, operacoes do tipo Q, retornam 0
    unsigned int getQuantOpe() const;

    //*Funcoes de uso do Programa

    ///Realiza a leitura das operacoes e retorna a expecificacao de execucao ((D,Q,M,F)R)
    unsigned int realizaLeitura(std::ifstream &arquivoFonte, Operacao *arrayOperacao, char tipoExecucao[]) const;
    ///Faz o print das informacoes de uma operacao (Junto com o print do dado)
    void printInfo() const override;
};
