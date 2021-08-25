//Classe dado, classe mais basica do projeto

#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>

class Dado
{
private:
    unsigned int date;
    std::string ticker;

public:
    //* Construtore e destrutores
    Dado(const std::string &ticker, std::string &data);
    Dado(const std::string &ticker, const unsigned int &data);
    Dado();
    ~Dado();

    //* Getters and Setters
    ///Retorna a data na forma de um intero na forma yyyymmddd
    unsigned int getDateInt() const;
    ///Retorna a data em um string na forma yyyy-mm-dd
    std::string getDateString() const;
    ///Funcao que retorna uma acao na forma yyyy-m-dd
    std::string getDateStringSallistica() const;
    ///Retorna o ticker da empresa
    std::string getTicker() const;
    ///Retorna o mes de cada tipo de dado
    unsigned int getMesInt() const;
    //* Funcoes de uso do programa

    //Faz a leitura dos dados de cada linha
    void parsingLinha(std::string &linhaFonte, std::string *dados) const;
    ///Faz o print das informacoes de um dado
    virtual void printInfo() const;
};
