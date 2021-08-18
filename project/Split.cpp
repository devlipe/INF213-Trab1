
#include <Split.h>

Split::Split(std::string ticker, std::string data, std::string indice)
    : Dado(ticker, data)
{
    try
    {
        int i = indice.find(':');
        divisor = stoi(indice.substr(i + 1));
        multiplicador = stoi(indice.substr(0, i));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

Split::~Split()
{
}
