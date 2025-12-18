#include <iostream>
#include <vector>
#include "../gclist/gclist.h"
#include "../persons/persons.h"
#include "../catalog/catalog.h"
#include "../stage/stage.h"

int main(){

    CyclistCatalog Catalog;

    int hard;

    Cyclist c1{"Thomas Pidcock", 1999, "Q36.5 Pro Cycling Team", "d1a1b001"};
    Cyclist c2{"Xabier Mikel Azparren", 1999, "Q36.5 Pro Cycling Team", "d1a1b002"};
    Cyclist c3{"Enekoitz Azparren", 2002, "Q36.5 Pro Cycling Team", "d1a1b003"};
    Cyclist c4{"Marcel Camprubí", 2001, "Q36.5 Pro Cycling Team", "d1a1b004"};
    Cyclist c5{"Damien Howson", 1992, "Q36.5 Pro Cycling Team", "d1a1b005"};
    Cyclist c6{"Antonio Cañete Lopez", 2003, "Tinkoff", "d46271661p"};
    Cyclist c7{"Pablo Miguel Martin Segovia", 2005, "Tinkoff", "d46271662p"};

    Catalog.Add(c1);
    Catalog.Add(c2);
    Catalog.Add(c3);
    Catalog.Add(c4);
    Catalog.Add(c5);
    Catalog.Add(c6);
    Catalog.Add(c7);

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

    gclist.NormalizeDelays();

    std::cout<<"\n ---- Clasificación 10 primeros ----\n";
    std::string classification = gclist.GetClassification(10);

    std::cout<<classification;

    return 0;
}