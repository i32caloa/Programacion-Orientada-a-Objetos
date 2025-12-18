#include <iostream>
#include <string>
#include <vector>
#include "catalog.h"
#include "../persons/persons.h"

int main(){

    CyclistCatalog catalogCyclist;
    DirectorCatalog catalogDirector;

    std::string team;
    std::string id;

    if((!catalogCyclist.Load("../data/cyclists.csv")) || (!catalogDirector.Load("../data/directors.csv"))){

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

//Práctica 3, hacer GetTeam(), GetByTeam(), GetYoungest()

    std::cout<<"\n------------------------------------\nIntroduce el nombre del equipo: ";
    std::getline(std::cin, team);
    std::cout<<"\n------------------------------------\n";

    std::vector<Cyclist>vCyclist = catalogCyclist.GetByTeam(team);
    if(vCyclist.size()==0){
        std::cout<<"\nNo hay cislistas en este equipo\n";
        exit(EXIT_FAILURE);
    } else {
        std::cout<<"\nCyclist "<<team<<"\n";
        for(int i=0; i<vCyclist.size(); i++){
            std::cout<<"\n"<<vCyclist[i].GetName();
        }
    }

    std::cout<<"\n\nCiclista/s mas jovenes: ";

    std::vector<Cyclist> youngest = catalogCyclist.GetYoungest();
    for(int i=0; i<youngest.size(); i++){
        std::cout<<youngest[i].GetName()<<", "<<youngest[i].GetBirthYear()<<", "<<youngest[i].GetTeam()<<", "<<youngest[i].GetCyclistId()<<"\n";
    }



    std::cout<<"\n-------------------------------------------------\nIntroduce el Id del ciclista para ver el equipo: ";
    std::getline(std::cin, id);
    std::cout<<"\n-------------------------------------------------\n";

    std::string searchTeam = catalogCyclist.GetTeam(id);
    if(searchTeam.empty()){
        std::cout<<"\nNo se ha encontrado equipo para esta id\n";
        exit(EXIT_FAILURE);
    } else {
        std::cout<<"\nCiclista con Id: "<<id<<" es del equipo: "<<searchTeam<<"\n";
    }

    return 0;
}