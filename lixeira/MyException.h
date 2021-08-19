#pragma once

#include <string>

class MyException
{
private:
    std::string mensagem;
public:
    MyException(const std::string msg);
    const std::string &what() const;
};
