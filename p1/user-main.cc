#include <string>
#include "user.h"
#include <iostream>

namespace ns1{

    int a;
    int b;

}

namespace ns2{

    int a;
    int b;

}

int main(){
    //declaraciones de ns1 y ns2

    int a=55;
    ns1::a=0;
    ns2::a=2.3;

    std::cout<<"ns1::a = "<<ns1::a<<"\n";
    std::cout<<"ns2::a = "<<ns2::a<<"\n";
    std::cout<<"a = "<<a<<"\n";

    User Usuario("TEMP");

    Usuario = ReadFromConsole();
    PrintfFromConsole(Usuario);

    std::cout<<"\n"<<Usuario.GetFullData()<<"\n";

    return 0;
}