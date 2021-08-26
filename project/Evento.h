#pragma once

#include "Dado.h"
#include "Dividendo.h"
#include "Split.h"
#include "Operacao.h"

class Evento : public Dado
{
private:
    //Recebe o tipo de cada Evento sendo {1:Dividendo, 2:Split, 3:Operacao, 4:Reinvestir, 5:Impressao}
    unsigned int tipoEvento;
    //Indica a posicao no vetor de origem de cada evento, ira agilizar o acesso as informacoes
    //Por exemplo, uma cotacao estara em historicoCotacoes[posicaoVetor]
    //A classe foi criada desse jeito para diminiuir o uso de memora, uma vez que um vetor de eventos sera excessivamente grande (lim. 1.500)    unsigned int posicaoVetor;
    unsigned int posicaoVetor;

public:
    //* Construtores e Destrutores

    ///Construtor Default, coloca tipo de evento e posicao de vetor como 0;
    Evento();
    ///Construtor que cria um evento com base em um dividendo
    Evento(const Dividendo &div, const unsigned int &pVetor);
    ///Construtor que cria um evento para reinvestir os dividendos caso seja necessario
    Evento(const Dividendo &div);
    ///Construtor que cria um eventeo com base em um split
    Evento(const Split &split, const unsigned int &pVetor);
    ///Construtor que cria um eventeo com base em uma operacao
    Evento(const Operacao &ope, const unsigned int &pVetor);
    ///Construtor para colocar um metodo de impressao do vetor eventos
    Evento(const unsigned int &data);
    ~Evento();

    //* Getters and Setters

    ///Retona o tipo de cada evento como unsigned int sendo {1:Dividendo, 2:Split, 3:Operacao, 4:Reinvestir, 5:Impressao}
    unsigned int getTipoEvento() const;
    ///Retorna a posicao no vetor original de cada evento  //Por exemplo, uma cotacao estara em historicoCotacoes[posicaoVetor]
    unsigned int getPosicaoVetor() const;

    //* Funcoes de uso do programa
    ///Chama o printDefault da classe dado alem de imprimir as infomacoes da propria classe
    void printInfo() const override;
};
