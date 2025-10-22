#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../persons/persons.h"
#include "catalog.h"

bool CyclistCatalog::Load(const std::string& path) {

    Cyclist c;
    std::string name, birth_s, id, team;
    int birthyear = 0;

    cyclist_.clear(); // Elimina todos los elementos si hubiera
    std::ifstream in(path);

    if(!in){
        std::cerr << "-ERROR: No se pudo abrir " << path << "\n";
        return false;
    }

    std::string line;

    if (!std::getline(in, line)) return false; // saltar cabecera

    while (std::getline(in, line)) {

        if (line.empty()) continue;
        std::istringstream iss(line); // Define un stream de lectura a partir de line
        if (!std::getline(iss, name, ',')) continue;
        if (!std::getline(iss, birth_s, ',')) continue;
        if (!std::getline(iss, id, ',')) continue;
        if (!std::getline(iss, team)) continue;
        birthyear = std::stoi(birth_s);
        c.SetName(name);
        c.SetBirthYear(birthyear);
        c.SetCyclistId(id);
        c.SetTeam(team);
        cyclist_.push_back(c);
    }
    return !cyclist_.empty();
}

bool DirectorCatalog::Load(const std::string& path) {

    Director Directo;
    std::string name, birth_s, id, team, director_since_s;
    int birthyear = 0, director_since = 0;

    director_.clear(); 
    std::ifstream in(path);

    if(!in){
        std::cerr << "-ERROR: No se pudo abrir " << path << "\n";
        return false;
    }

    std::string line;

    if (!std::getline(in, line)) return false; // saltar cabecera

    while (std::getline(in, line)) {

        if (line.empty()) continue;
        std::istringstream iss(line); 
        
        if (!std::getline(iss, name, ',')) continue;
        if (!std::getline(iss, birth_s, ',')) continue;
        if (!std::getline(iss, id, ',')) continue;
        if (!std::getline(iss, team, ',')) continue;
        if (!std::getline(iss, director_since_s)) continue;

        birthyear = std::stoi(birth_s);
        director_since = std::stoi(director_since_s);

        Directo.SetName(name);
        Directo.SetBirthYear(birthyear);
        Directo.SetUciLicenseId(id);
        Directo.SetTeam(team);
        Directo.SetDirectorSince(director_since);
        director_.push_back(Directo); 
    }
    return !director_.empty();
}

//PRACTICA 3

//Funcion para encontrar el equipo de un ciclista segun su id

std::string CyclistCatalog::GetTeam(const std::string &id){

    for(auto &c : cyclist_){ //Puntero hacia los elementos guardados en cyclist_
        if(c.GetCyclistId() == id){ 
            return c.GetTeam(); //Devuelve el equipo segun el id del ciclista
        }
    }
    return "";  //Devuelve nada si no hay equipo
}

//Funcion para encontrar todos los ciclistas de un mismo equipo

std::vector<Cyclist> CyclistCatalog::GetByTeam(const std::string &team){

    std::vector<Cyclist> cyclist_team; //Creamo un vector para guardar todos los ciclistas del equipo
    for(auto &c : cyclist_){
        if(c.GetTeam() == team){
            cyclist_team.push_back(c); //Si coinciden equipo y ciclista, hacemos push en el vector creado
        }
    }
    return cyclist_team; //Devuelve el vector
}

//Funcion para conseguir los ciclistas mas jovenes

std::vector<Cyclist> CyclistCatalog::GetYoungest(){

    std::vector<Cyclist> youngest_cyclist;
    int x=0;

    for(auto &c : cyclist_){ //Buscamos el valor mas pequeño para la edad
        if(c.GetBirthYear()<x){
            x=c.GetBirthYear();
        }
    }

    for(auto &c : cyclist_){ //Si la edad coincide con la menor, se hace un push en el vector youngest_cyclist
        if(c.GetBirthYear() == x){
            youngest_cyclist.push_back(c);
        }
    }
    return youngest_cyclist; //Devolvemos el vector
}