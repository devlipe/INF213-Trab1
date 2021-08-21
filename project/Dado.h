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
    Dado(const std::string ticker, std::string data);
    Dado();
    ~Dado();

    //* Getters and Setters
    ///Retorna a data na forma de um intero na forma yyyymmddd
    unsigned int getDateInt() const;
    ///Retorna a data em um string na forma yyyy-mm-dd
    std::string getDateString() const;
    ///Retorna o ticker da empresa
    std::string getTicker() const;

    //* Funcoes de uso do programa

    //Faz a leitura dos dados de cada linha
    void parsingLinha( std::string &linhaFonte, std::string * dados) const;

    //!Testar
    //TODO: Criar um metodo print para as classes que herdam de Dado (Verificar se esta pegando os dados certos). Acredito que possa haver um override na funcao (recebe um argumento do tipo dado??) 
    //!Testar
    ///Faz o print das informacoes de um dado
    virtual void printInfo() const;
};
