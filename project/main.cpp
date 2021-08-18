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


void codeToGetTheData()
{
    std::string entrada;

    std::getline(std::cin, entrada); // Pega a linha do arquivo

    std::stringstream line;
    line << entrada;

    while (!line.eof())
    {
        std::string dadoDaClasse;
        std::getline(line, dadoDaClasse, ',');
    }
    line.clear();
}

int main(int argc, char const *argv[])
{
    if (argc != 5)
    {
        std::cerr << "Numero de arquivos insuficiente. Necessario 4, Encontrado " << argc << std::endl;
        exit(1);
    }

    std::string precosPath = argv[1];
    std::string splitsPath = argv[2];
    std::string dividentosPath = argv[3];
    std::string operacoesPath = argv[4];

    std::ofstream precosCSV(precosPath);
    std::ofstream splitsCSV(splitsPath);
    std::ofstream dividentosCSV(dividentosPath);
    std::ofstream operacoesCSV(operacoesPath);

    return 0;
}
