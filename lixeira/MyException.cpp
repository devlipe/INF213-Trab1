#include "MyException.h"

MyException::MyException(const std::string msg) : mensagem(msg)
{
}

const std::string &MyException::what() const
{
    return mensagem;
}