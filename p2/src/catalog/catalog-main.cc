#include "catalog.h"
#include "../persons/persons.h"
#include <iostream>
#include <vector>
#include <iterator>

int main(){

    CyclistCatalog cyclist_catalog;
    DirectorCatalog director_catalog;

    if((!cyclist_catalog.Load("/home/antoniocl53/Escritorio/uni/2/1c/poo/p2/data/cyclists.csv")) || (!director_catalog.Load("/home/antoniocl53/Escritorio/uni/2/1c/poo/p2/data/directors.csv"))){

        std::cerr<<"No se cargaron los catalogos\n";

        exit(EXIT_FAILURE);

    }

    std::vector<Cyclist>cc=cyclist_catalog.Data();
    std::vector<Director>dc=director_catalog.Data();

    std::cout<<"\nNumero de ciclistas: "<<cc.size()<<"\n";

    for(size_t i=0; i<cc.size(); i++){
        std::cout<<cc[i].GetName()<<" "<<cc[i].GetBirthYear()<<" "<<cc[i].GetTeam()<<" "<<cc[i].GetCyclistId()<<"\n";
    }

    std::cout<<"\nNumero de directores: "<<dc.size()<<"\n";

    for(size_t i=0; i<dc.size(); i++){
        std::cout<<dc[i].GetName()<<" "<<dc[i].GetBirthYear()<<" "<<dc[i].GetTeam()<<" "<<dc[i].GetUciLicenseId()<<" "<<dc[i].GetDirectorSince()<<"\n";
    }

    return 0;

}