
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

// void codeToGetTheData()
// {
//     std::string entrada;

//     std::getline(std::cin, entrada); // Pega a linha do arquivo

//     std::stringstream line;
//     line << entrada;

//     while (!line.eof())
//     {
//         std::string dadoDaClasse;
//         std::getline(line, dadoDaClasse, ',');
//     }
//     line.clear();

//     ///! Jeito do Salles
//     std::ifstream fin;
//     std::string linha;
//     while (std::getline(fin, linha))
//     {
//         std::stringstream ss;
//         ss << linha;
//         for (int i = 0; i < linha.size(); i++)
//             if (linha[i] == ',')
//                 linha[i] == ' ';
//         ss << linha;
//         std::string ticker;
//         double p1, p2;
//         ss >> ticker >> p1 >> p2;
//     }
//}

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
//    std::cout << acoes[posAcao].getCustoTotal() << " Custo Total COMPRA " << acoes[posAcao].getTicker() << std::endl;
// void Carteira::insert(const std::string &elem, const int pos)
// {
//     if (pos > 110 || pos < 0) //Limites do array de acoes
//     {
//         throw("Tentativa de inserir acao em posicao indevida");
//     }

//     for (int i = nAcoes; i > pos; i--)
//     {
//         acoes[i] = acoes[i - 1];
//     }
//     acoes[pos] = Acao(elem);
//     nAcoes++;
// }

// //  if (nAcoes > 0)
// //     {
// //         for (int i = 0; i < nAcoes; i++)
// //         {
// //             if (ticker <= acoes[i].getTicker())
// //             {
// //                 insert(ticker, i);
// //                 return i;
// //             }
// //         }
// //     }
// //     else
// //     {
// //         insert(ticker, 0);
// //         return 0;
// //     }
// //     insert(ticker, nAcoes);
// //     return nAcoes - 1;

int nAcoes = 0;
int acoes[110];
void insert(const int &elem, const int pos)
{
    if (pos > 110 || pos < 0) //Limites do array de acoes
    {
        throw("Tentativa de inserir acao em posicao indevida");
    }

    for (int i = nAcoes; i > pos; i--)
    {
        acoes[i] = acoes[i - 1];
    }
    acoes[pos] = elem;
    nAcoes++;
}

int insereAcaoAlfa(const int &elem)
{
    if (nAcoes > 0)
    {
        for (int i = 0; i < nAcoes; i++)
        {
            if (elem <= acoes[i])
            {
                insert(elem, i);
                std::cout << "Numero de acoes:" << nAcoes << std::endl;
                return i;
            }
        }
    }
    else
    {
        insert(elem, 0);
        std::cout << "Numero de acoes:" << nAcoes << std::endl;
        return 0;
    }
    insert(elem, nAcoes);
    std::cout << "Numero de acoes:" << nAcoes << std::endl;
    return nAcoes - 1;
}
int main()
{
    // int data = 20210824;
    // // while (true)
    // // {
    // //     std::cin >> data;
    // //     std::cout << insereAcao(data) << " inserido nessa pos\n";
    // //     for (int i = 0; i < 200; i++)
    // //     {
    // //         std::cout << acoes[i] << " ";
    // //     }
    // //     std::cout << "\n";
    // // }
    // std::string v[10];

    // for (int i = 0; i < 150; i++)
    // {
    //     std::cout << v[i] << std::endl;
    // }


    char palavra[2];
    palavra[0] = '0';
    palavra[1] = '0';

    std::cin>> palavra;

   if (palavra[0] == 'D')
   {
       std::cout << "METODO D";
   }
   
   if (palavra[1] == 'R')
   {
       std::cout << "REINVISTA!!";
   }
   
    
}
