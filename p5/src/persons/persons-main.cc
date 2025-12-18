#include "persons.h"
#include <iostream>
#include <string>

int main(){


    Person Persona("Temp", -1);
    Cyclist Ciclista("Temp", -1, "Temp", "Temp");
    Director Directo("Temp", -1, "Temp", "Temp", -1);
    int x;

    do{

        std::cout<<"\n********Menu********\n";
        std::cout<<"\n1. Person";
        std::cout<<"\n2. Cyclists";
        std::cout<<"\n3. Director";
        std::cout<<"\n********************\n";

        std::cout<<"\nSeleccione una opcion: ";
        std::cin>>x;

        switch(x){
        case 1:
            
            Persona = ReadPersonFromConsole();
            PrintPersonFromConsole(Persona);

            break;
        
        case 2:

            Ciclista = ReadCyclistsFromConsole();
            PrintCyclistsFromConsole(Ciclista);
            break;

        case 3:

            Directo = ReadDirectorsFromConsole();
            PrintDirectorsFromConsole(Directo);
            break;

        default: 

            std::cout<<"Saliendo............\n";
            break;
        }
    } while(x>0 && x<4);

    return 0;
}