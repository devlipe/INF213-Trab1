//Classe dado, classe mais basica do projeto

#pragma once

#include <string>

class Dado
{
private:
    unsigned int date;
    std::string ticker;

public:
    //* Construtore e destrutores
    Dado(const std::string ticker, std::string data);
    ~Dado();

    //* Getters and Setters
    ///Retorna a data na forma de um intero na forma yyyymmddd
    unsigned int getDateInt() const;
    ///Retorna a data em um string na forma yyyy-mm-dd
    std::string getDateString() const;
    ///Retorna o ticker da empresa
    std::string getTicker() const;
};