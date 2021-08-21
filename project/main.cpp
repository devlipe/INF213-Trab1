/*
    Trabalho de INF 213 (17-08-2021)
    Trabalho com o intuito de promover a criacao de um sistema que verifica a rentabilidade de uma carteira de acoes
    Trabalho feito por Felipe Pereira Ferreira
*/

#include <string>
#include <iostream>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Bolsa.h"




int main(int argc, char const *argv[])
{
    if (argc != 5)
    {
        std::cerr << "Numero de arquivos insuficiente. Necessario 4, Encontrado " << argc << std::endl;
        exit(1);
    }

    Bolsa::leArquivos(argv);
    Bolsa::organizaCotacoes();
    Bolsa::printDataBase();

    return 0;
}
