#include <iostream>
#include "counter.h"

int main(){

    Counter c(250, 0, 1000); //constructor siempre con value, min y max 

    std::cout<<" --- Inicio ---\n";
    std::cout<<"value: " << c.Get() << ", min: " << c.GetMin() << ", max: " << c.GetMax() <<"\n";

    //Operadores ++

    std::cout<<"\n ---- Operador ++ prefijo ---- \n";
    std::cout<<"\n c: "<< c << "\n";
    std::cout<<"Valor ++c: " << ++c << "\n";

    std::cout<<"\n ---- Operador ++ sufijo ---- \n";
    std::cout<<"\n c: "<< c << "\n";
    std::cout<<"Valor de c++: " << c++ << "\n";

    //Operadores --

    std::cout<<"\n ---- Operador -- prefijo ---- \n";
    std::cout<<"\n c: "<< c << "\n";
    std::cout<<"Valor --c: " << --c << "\n";

    std::cout<<"\n ---- Operador -- sufijo ---- \n";
    std::cout<<"\n c: "<< c << "\n";
    std::cout<<"Valor de c--: " << c-- << "\n";

    //Operador +

    std::cout<<"\n ---- Operador + ---- \n";
    std::cout<<"\n c: "<< c << "\n";
    std::cout<<"Valor de c + 100: " << c + 100 << "\n";
    std::cout<<"Valor de 100 + c: " << 100 + c << "\n";
    std::cout<<"Valor de c + 800: " << c + 800 << "\n";
    std::cout<<"Valor de c + 1000: " << c + 1000 << "\n";

    //Operador -

    std::cout<<"\n ---- Operador - ---- \n";
    std::cout<<"\n c: "<< c << "\n";
    std::cout<<"Valor de c - 100: " << c - 100 << "\n";
    std::cout<<"Valor de 100 - c: " << 100 - c << "\n";
    std::cout<<"Valor de c - 300: " << c - 300 << "\n";
    std::cout<<"Valor de c - 1000: " << c - 1000 << "\n";

    //Operador >>

    std::cout<<"\n ---- Operador >> ---- \n";
    std::cout<<"\n c: "<< c << "\n";
    std::cout<<"Introduzca un valor para el contador: ";
    std::cin>>c;
    std::cout<<"Valor introducido: " << c << "\n";

    //Operador <<

    std::cout<<"\n ---- Operador << ---- \n";
    std::cout<<"Valor del contador: " << c << "\n";

    //Operador =
    
    std::cout<<"\n ---- Operador = ---- \n";
    c = 500;
    std::cout<<"Valor despues de c = 500: " << c << "\n";

    Counter c2(200, 0, 300);

    std::cout<<"\nCounter 2: value:  " << c2 << ", min: " << c2.GetMin() << ", max: " << c2.GetMax() <<"\n";
    c = c2;
    std::cout<<"\nValor despues de c = c2, c: " << c << "\n";

    return 0;
}