#include <iostream>
#include <string>
#include <vector>
#include "catalog.h"
#include "../persons/persons.h"

int main(){

    CyclistCatalog catalogCyclist;
    DirectorCatalog catalogDirector;

    if((!catalogCyclist.Load("/home/antoniocl53/Escritorio/uni/2/1c/poo2/p2/build/data/cyclists.csv")) || (!catalogDirector.Load("/home/antoniocl53/Escritorio/uni/2/1c/poo2/p2/build/data/directors.csv"))){

        std::cerr<<"Error al cargar los catalogos";

        exit(EXIT_FAILURE);
    }

    std::vector<Cyclist>cc = catalogCyclist.Data();
    std::vector<Director>dc = catalogDirector.Data();

    std::cout<<"\n--------------------\nCyclist number: "<<cc.size()<<"\n--------------------\n";
    for(int i=0; i<cc.size(); i++){
        std::cout<<"\n"<<cc[i].GetName()<<", "<<cc[i].GetBirthYear()<<", "<<cc[i].GetTeam()<<", "<<cc[i].GetCyclistId();
    }

    std::cout<<std::endl;

    std::cout<<"\n--------------------\nDirector Number: "<<dc.size()<<"\n--------------------\n";
    for(int i=0; i<dc.size(); i++){
        std::cout<<"\n"<<dc[i].GetName()<<", "<<dc[i].GetBirthYear()<<", "<<dc[i].GetTeam()<<", "<<dc[i].GetUciLicenseId()<<", "<<dc[i].GetDirectorSince();        
    }

    return 0;
}