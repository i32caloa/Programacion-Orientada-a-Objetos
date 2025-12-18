#include "../persons/persons.h"
#include "../catalog/catalog.h"
#include "stage.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>

int main(){

    int hard;

    std::cout<<"\nIntroduce la dureza de la etapa del 1 al 5, siendo 5 la mas dura: ";
    std::cin>>hard;

    Stage Stage(hard);

    std::string name, cyclistId;
    int numeroCyclist;
    CyclistCatalog catalogCyclist;

    if(!catalogCyclist.Load("../data/cyclists.csv")){
        std::cerr<<"ERROR AL ABRIR EL CATALOGO";
        exit(EXIT_FAILURE);
    }

    std::vector<Cyclist> vectorCyclist = catalogCyclist.Data();
    int numberCyclist = catalogCyclist.Size();

    for(int i=0; i<numberCyclist; i++){

        name = vectorCyclist[i].GetName();
        cyclistId = vectorCyclist[i].GetCyclistId();
        std::map<std::string, int> delays = Stage.Simulate(vectorCyclist);
        int delay = delays[cyclistId];

        std::cout<<name<<", "<<delay<<"s";
        if(delay==0){
            std::cout<<" (Ganador)";
        }
        std::cout<<"\n";

    }

    return 0;
}