/*
Fichero Person.cc

Contiene funciones necesarias para el funcionamiento del programa

*/
#include "persons.h"
#include <iostream>
#include <string>

//CONSTRUCTORES VACÍOS

Person::Person(){

    name_ = "UNKNOWN";
    birth_year_ = -1;

}

Cyclist::Cyclist(){

    team_ = "UNKNOWN";
    cyclist_id_ = "UNKNOWN";

}

Director::Director(){

    team_ = "UNKNOWN";
    uci_license_id_ = "UNKNOWN";
    director_since_ = -1;

}

//CONSTRUCTORES

Person::Person(const std::string name, int birth_year){ 

    name_ = name;
    birth_year_ = birth_year;

}

Cyclist::Cyclist(const std::string name, int birth_year, const std::string team, const std::string cyclist_id):Person(name, birth_year){

    team_ = team;
    cyclist_id_ = cyclist_id;

}

Director::Director(const std::string name, int birth_year, const std::string team, const std::string uci_license_id, int director_since):Person(name, birth_year){

    team_ = team;
    uci_license_id_ = uci_license_id;
    director_since_ = director_since;

}

//SETTERS

bool Person::SetName(std::string name){

    if(name.empty()){
        return false;
    } else {
        name_=name;
        return true;
    }
}

bool Person::SetBirthYear(int birth_year){

    if(birth_year<1950 || birth_year>2007){
        return false;
    } else {
        birth_year_=birth_year;
        return true;
    }
}

bool Cyclist::SetTeam(std::string team){

    if(team.empty()){
        return false;
    } else {
        team_=team;
        return true;
    }
}

bool Cyclist::SetCyclistId(std::string cyclist_id){

    if(cyclist_id.empty()){
        return false;
    } else {
        cyclist_id_=cyclist_id;
        return true;
    }
}

bool Director::SetTeam(std::string team){

    if(team.empty()){
        return false;
    } else {
        team_=team;
        return true;
    }
}

bool Director::SetUciLicenseId(std::string uci_license_id){

    if(uci_license_id.empty()){
        return false;
    } else {
        uci_license_id_=uci_license_id;
        return true;
    }
}

bool Director::SetDirectorSince(int director_since){

    if(director_since<0){
        return false;
    } else {
        director_since_=director_since;
        return true;
    }
}

//Funciones del programa

Person ReadPersonFromConsole(){

    std::string name;
    int birth_year;

    std::cout<<"\n********Person********\n";
    std::cout<<"\nName: ";
    std::cin>>name;
    std::cout<<"\nBirth Year: ";
    std::cin>>birth_year;
    std::cout<<"\n***********************\n";

    Person Personas(name, birth_year);

    return Personas;

}

void PrintPersonFromConsole(Person &Persona){

    std::cout<<"\n********Persona*********\n";
    std::cout<<"\nName: "<<Persona.GetName();
    std::cout<<"\nBirth Year: "<<Persona.GetBirthYear();
    std::cout<<"\n************************\n";

}

Cyclist ReadCyclistsFromConsole(){

    std::string name, cyclist_id, team;
    int birth_year;

    std::cout<<"\n********Person********\n";
    std::cout<<"\nName: ";
    std::cin>>name;
    std::cout<<"\nBirth Year: ";
    std::cin>>birth_year;
    std::cout<<"Team: ";
    std::cin>>team;
    std::cout<<"Cyclist Id: ";
    std::cin>>cyclist_id;
    std::cout<<"\n***********************\n";

    Cyclist Ciclista(name, birth_year, team, cyclist_id);

    return Ciclista;

}

void PrintCyclistsFromConsole(Cyclist &Ciclista){

    std::cout<<"\n********Ciclista*********\n";
    std::cout<<"\nName: "<<Ciclista.GetName();
    std::cout<<"\nBirth Year: "<<Ciclista.GetBirthYear();
    std::cout<<"\nTeam: "<<Ciclista.GetTeam();
    std::cout<<"\nCyclist Id: "<<Ciclista.GetCyclistId();
    std::cout<<"\n************************\n";

}

Director ReadDirectorsFromConsole(){

    std::string name, uci_license_id, team;
    int birth_year, director_since;

    std::cout<<"\n********Director********\n";
    std::cout<<"\nName: ";
    std::cin>>name;
    std::cout<<"\nBirth Year: ";
    std::cin>>birth_year;
    std::cout<<"Team: ";
    std::cin>>team;
    std::cout<<"Uci License Id: ";
    std::cin>>uci_license_id;
    std::cout<<"\nDirector Since: ";
    std::cin>>director_since;
    std::cout<<"\n************************\n";

    Director Directo(name, birth_year, team, uci_license_id, director_since);

    return Directo;

}

void PrintDirectorsFromConsole(Director &Directo){

    std::cout<<"\n********Director*********\n";
    std::cout<<"\nName: "<<Directo.GetName();
    std::cout<<"\nBirth Year: "<<Directo.GetBirthYear();
    std::cout<<"\nTeam: "<<Directo.GetTeam();
    std::cout<<"\nCyclist Id: "<<Directo.GetUciLicenseId();
    std::cout<<"\nDirector Since: "<<Directo.GetDirectorSince();
    std::cout<<"\n************************\n";

}