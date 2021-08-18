#include <iostream>
#include <string>

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

int main(){
    std::string indice = "10:11";
    int i = indice.find(":");
    unsigned int divisor = stoi(indice.substr(i+1));
    unsigned int multiplicador = stoi(indice.substr(0,i));
    
    std:: cout << multiplicador << " " << divisor << "\n";
}