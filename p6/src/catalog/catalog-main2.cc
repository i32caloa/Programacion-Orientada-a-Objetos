#include <iostream>
#include "catalog.h"
#include "../persons/persons.h"

int main(){

    CyclistCatalog Catalog;

    Cyclist c1{"Antonio Cañete Lopez", 2003, "Tinkoff", "d46271661p"};
    Cyclist c2{"Pablo Miguel Martin Segovia", 2005, "Tinkoff", "d46271662p"};
    Cyclist c3{"Manuel Reyes Serrano", 2005, "Tinkoff", "d46271663p"};
    Cyclist c4{"Yago Calero Roldan", 2003, "Tinkoff", "d46271664p"};

    Catalog<< c1 << c2 << c3 << c4;

    std::cout<<"\n ----- Lista de ciclistas ----- \n";
    std::vector<Cyclist> cylist = Catalog.Data();
    for(auto &c : cylist){
        std::cout<<"Name: "<<c.GetName()<<", Birth Year: "<<c.GetBirthYear()<<", Team: "<<c.GetTeam()<<", Cyclist ID: "<<c.GetCyclistId()<<"\n";
    }
    return 0;
}