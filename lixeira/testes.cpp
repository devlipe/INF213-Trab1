
#include <string>
#include <iostream>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <sstream>

// int main()
// {
//     std::string s = "2021-08-18";
//     s.erase(4, 1);
//     s.erase(6, 1);
//     //std::cout << stoi(s) << "\n";

//     int a = stoi(s);
//     std::string c = std::to_string(a);
//     c.insert(4,"-");
//     c.insert(7,"-");
//     std::cout << c;
// }

// int main(){

//     double b = 0.016381;

//     int a = (b + 0.000001) * 100000;
//     std::cout << a;
// }

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

    ///! Jeito do Salles
    std::ifstream fin;
    std::string linha;
    while (std::getline(fin, linha))
    {
        std::stringstream ss;
        ss << linha;
        for (int i = 0; i < linha.size(); i++)
            if (linha[i] == ',')
                linha[i] == ' ';
        ss << linha;
        std::string ticker;
        double p1, p2;
        ss >> ticker >> p1 >> p2;
    }
}

// void leLinha(std::string &linha, std::string *dados)
// {
//     std::stringstream line;
//     for (int i = 0; i < linha.size(); i++)
//     {
//         linha[i] == ',' ? linha[i] = ' ' : linha[i];
//     }
//     line << linha;
//     int i = 0;
//     while (line >> dados[i])
//     {
//         i++;
//     }
// }

// int main()
// {
//     std::string linha;

//     getline(std::cin, linha);
//     std::string dados[10] = {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"};

//     //leLinha(linha, dados);

//     for (int i = 0; i < 10; i++)
//     {
//         std::cout << dados[i] << std::endl;
//     }

//     // while (dados)
//     // {
//     //     std::cout << *dados;
//     //     dados + 1;
//     // }
// }

int main()
{
    int data = 20210824;
    while (true)
    {
        std::cin >> data;
        std::cout << std::left << std::setw(50) << "Lucro total do mes:" << std::right << std::setw(15) << data << std::setw(15) << data << std::endl;
    }
}
