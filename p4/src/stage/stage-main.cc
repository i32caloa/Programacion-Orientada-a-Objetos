#include <string>
#include <map>
#include <vector>
#include "stage.h"
#include "../persons/persons.h"
#include "../catalog/catalog.h"
#include <iostream> // Para entrada y salida

/*
Realiza un programa principal stage-main.cc que llame a la clase Stage y muestra en pantalla
separado por una coma el nombre de cada corredor, su id y su delay.
*/

int main(){

    int hard;

    std::cout<<"\nDureza de la etapa(1-5): ";
    std::cin>>hard;

    Stage stage(hard);
    
    std::string name, id;
    int numero_ciclistas;
   
    CyclistCatalog cyclists_catalog;

    if(!cyclists_catalog.Load("/home/antoniocl53/Escritorio/uni/2/1c/poo/p4/data/cyclists.csv")){

        std::cerr<<"No se cargo el catalogo de ciclistas\n";
        exit(EXIT_FAILURE); 
    }

    std::vector<Cyclist> cyclists=cyclists_catalog.Data();
    numero_ciclistas = cyclists_catalog.Size();

    for(int i=0; i<numero_ciclistas; i++){

        name = cyclists[i].GetName();
        id = cyclists[i].GetCyclistId();
        std::map<std::string, int> delays = stage.Simulate(cyclists);
        int delay = delays[id];

        std::cout<<name<<", "<<delay<<"s";
        if(delay==0){
            std::cout<<" (Ganador)";
        }
        std::cout<<"\n";

    }

    return 0;
}
