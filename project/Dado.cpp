#include "Dado.h"

Dado::Dado(const std::string ticker, std::string data)
{
    this->ticker = ticker;

    data.erase(4, 1); //Removendo os "-" da data para transforma-la em inteiro, e assim facilitar a ordenacao
    data.erase(6, 1);
    this->date = stoi(data);
}

Dado::Dado()
{
    date = 0;
    ticker = "";
}

Dado::~Dado()
{
}

unsigned int Dado::getDateInt() const { return date; }

std::string Dado::getDateString() const
{
    std::string dateString = std::to_string(date);

    dateString.insert(4, "-"); // Adicionando os "-" na data para facilitar a leitura
    dateString.insert(7, "-");

    return dateString;
}

std::string Dado::getTicker() const
{
    return ticker;
}
void Dado::parsingLinha(std::string &linhaFonte, std::string *dados) const
{
    std::stringstream line;
    for (int i = 0; i < linhaFonte.size(); i++)
    {
        linhaFonte[i] == ',' ? linhaFonte[i] = ' ' : linhaFonte[i];
    }
    line << linhaFonte;
    int i = 0;
    while (line >> dados[i])
    {
        i++;
    }
    return;
}

void Dado::printInfo() const 
{
    std::cout<< "Ticker: " << this->ticker << "\n";
    std::cout<< "Data: " << this->getDateString() << "\n";
}
