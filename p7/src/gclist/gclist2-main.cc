#include <iostream>
#include <vector>
#include "../gclist/gclist.h"
#include "../persons/persons.h"
#include "../catalog/catalog.h"
#include "../stage/stage.h"

int main(){

    CyclistCatalog Catalog;

    int hard;

    std::string path = "../data/cyclists.csv";
    if(!Catalog.Load(path)){
        std::cerr<<"Error al caargar catálogo cyclists.csv";
        return 1;
    }

    std::cout<<" ----- Primera Etapa -----\n";
    std::cout<<"Insertar del 1 al 5 la dureza de la etapa: ";
    std::cin>>hard;

    Stage stage1(hard);
    
    std::map<std::string, int> results1 = stage1.Simulate(Catalog.Data());

    std::cout<<"\n---- Resultados de la etapa 1 ----\n";
    for(auto &r1 : results1){
        std::cout<<"Cyclist ID: "<<r1.first<<", Delay: "<<r1.second<<"s\n";
    }

    GCList gclist(Catalog);
    gclist.ApplyStage(stage1);

    std::cout<<"\n ----- Segunda Etapa -----\n";
    std::cout<<"Insertar del 1 al 5 la dureza de la etapa: ";
    std::cin>>hard;

    Stage stage2(hard);

    std::map<std::string, int> results2 = stage2.Simulate(Catalog.Data());
    
    std::cout<<"\n---- Resultados de la etapa 2 ----\n";
    for(auto &r2 : results2){
        std::cout<<"Cyclist ID: "<<r2.first<<", Delay: "<<r2.second<<"s\n";
    }

    gclist.ApplyStage(stage2);

    std::cout<<"\n ---- Clasificación 10 primeros ----\n";
    std::string classification = gclist.GetClassification(10);

    std::cout<<classification;
    
    return 0;
}