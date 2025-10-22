#include "catalog.h"
#include "../persons/persons.h"
#include <iostream>
#include <vector>
#include <iterator>

int main(){

    CyclistCatalog cyclist_catalog;
    DirectorCatalog director_catalog;

    if((!cyclist_catalog.Load("/home/antoniocl53/Escritorio/uni/2/1c/poo/p3/data/cyclists.csv")) || (!director_catalog.Load("/home/antoniocl53/Escritorio/uni/2/1c/poo/p3/data/directors.csv"))){

        std::cerr<<"No se cargaron los catalogos\n";

        exit(EXIT_FAILURE);

    }

    //Vector para cada catalogo

    std::vector<Cyclist> cc = cyclist_catalog.Data();
    std::vector<Director> dc = director_catalog.Data();

    std::cout<<"\nNumero de ciclistas: "<<cc.size()<<"\n";

    //Muestra ciclistas por pantalla

    for(size_t i=0; i<cc.size(); i++){
        std::cout<<cc[i].GetName()<<" "<<cc[i].GetBirthYear()<<" "<<cc[i].GetTeam()<<" "<<cc[i].GetCyclistId()<<"\n";
    }

    std::cout<<"\nNumero de directores: "<<dc.size()<<"\n";

    //Muestra directores por pantalla

    for(size_t i=0; i<dc.size(); i++){
        std::cout<<dc[i].GetName()<<" "<<dc[i].GetBirthYear()<<" "<<dc[i].GetTeam()<<" "<<dc[i].GetUciLicenseId()<<" "<<dc[i].GetDirectorSince()<<"\n";
    }

    return 0;

    //Practica 3

    std::string equipo;
    std::cout<<"\nIntroducir el nombre del equipo: "; //Obtenemos el equipo por teclado
    std::getline(std::cin, equipo);

    std::vector<Cyclist> v = cyclist_catalog.GetByTeam(equipo); //Obtenemos el vector con los ciclistas que hay en el equipo
    if(v.size()==0){
        std::cout<<"\nNo hay ciclistas en el equipo\n";
    } else{
        std::cout<<"\nCiclistas: "<<equipo<<"\n";
        for(size_t i = 0; i<v.size(); i++){
            std::cout<<v[i].GetName()<<"\n";
        }
    }

    std::vector<Cyclist> menor = cyclist_catalog.GetYoungest(); //Obtenemos el vector con los ciclistas mas jovenes
    std::cout<<"\nCiclista mas joven: "<<menor[0].GetName()<<"\n";

    std::string id; 
    std::cout<<"\nID del ciclista: ";

    std::getline(std::cin, id);
    std::string team = cyclist_catalog.GetTeam(id); //Obtenemos el equipo por el id del ciclista
    if(team == ""){
        std::cout<<"\nNo existe el ciclista con ID "<<id<<"\n";
    } else{
        std::cout<<"\nCiclista "<<id<<", Equipo "<<team<<"\n";
    }
    return 0;

}