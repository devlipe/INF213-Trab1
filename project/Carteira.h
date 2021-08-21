// TODO: Implementar a classe carteira (Tera um vetor de acao)
//TODO: Separar o que fica com a classe carteira e o que fica com a classe acao

#pragma once 

#include "Acao.h"
class Carteira
{
private:
    Acao acao[100];
    unsigned int nAcao;
public:

    //* Construtor e Destrutor
    Carteira();
    ~Carteira();
};