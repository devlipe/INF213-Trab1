#pragma once

#include "Dado.h"
#include "Dividendo.h"
#include "Split.h"
#include "Operacao.h"

class Evento : public Dado
{
private:
    //Recebe o tipo de cada Evento sendo {1:Dividendo, 2:Split, 3:Operacao, 4:Impressao}
    unsigned int tipoEvento;
    //Indica a posicao no vetor de origem de cada evento, ira agilizar o acesso as informacoes
    //Por exemplo, uma cotacao estara em historicoCotacoes[posicaoVetor]
    unsigned int posicaoVetor;
    ///Caso o evento guarde uma operacao, ira mostra C- compra ou V - venda, se estiver vazio, guardara 0;
    char tipoOperacao;

public:

    //* Construtores e Destrutores

    ///Construtor Default, coloca tipo de evento e posicao de vetor como 0;
    Evento();
    ///Construtor que cria um evento com base em um dividendo
    Evento(const Dividendo &div, const unsigned int &pVetor);
    ///Construtor que cria um eventeo com base em um split
    Evento(const Split &split, const unsigned int &pVetor);
    ///Construtor que cria um eventeo com base em uma operacao
    Evento(const Operacao &ope, const unsigned int &pVetor);
    ///Construtor para colocar um metodo de impressao do vetor eventos 
    Evento(const unsigned int &data);
    ~Evento();

    //* Getters and Setters

    unsigned int getTipoEvento() const;
    unsigned int getPosicaoVetor() const;
    char getTipoOperacao() const;

    //* Funcoes de uso do programa
    void printInfo() const override;
};
