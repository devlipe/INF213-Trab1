#include "Dado.h"

Dado::Dado(const std::string &ticker, std::string &data)
{
    this->ticker = ticker;

    data.erase(4, 1); //Removendo os "-" da data para transforma-la em inteiro, e assim facilitar a ordenacao
    data.erase(6, 1);
    this->date = stoi(data);
}

Dado::Dado(const std::string &ticker, const unsigned int &data)
{
    this->ticker = ticker;
    this->date = data;
}

Dado::Dado()
{
    //Ciramos um dado com uma data que certamente ficaria no final de qualquer metodo de ordenacao
    //Isso e preciso no caso do vetor de eventos, no qual os evetos "vazios" devem sempre ficar no final
    date = 30000000;
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

unsigned int Dado::getMesInt() const
{
    int aux = date;
    unsigned int mes = (aux / 100) % 100; // a / 100 remove o dia da data, e o %100 remove ano e deixa apenas o mes

    return mes;
}

std::string Dado::getDateStringSallistica() const
{
    std::string data = std::to_string(date / 10000);       ///adiciona o ano a data
    data = data + "-" + std::to_string(getMesInt()) + "-"; ///adiciona o mes e os hifens a data
    data = data + std::to_string(date % 100);              /// Adiciona o mes a data

    return data;
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
    std::cout << "Ticker: " << this->ticker << "\n";
    std::cout << "Data: " << this->getDateString() << "\n";
}
