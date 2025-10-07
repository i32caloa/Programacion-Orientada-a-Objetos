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
        cyclist_.push_back(c); // se hace una copia al final del vector
    }
    return !cyclist_.empty();
}

bool DirectorCatalog::Load(const std::string& path) {

    Director Directo;
    std::string name, birth_s, id, team;
    int birthyear = 0, director_since;

    director_.clear(); // Elimina todos los elementos si hubiera
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
        Directo.SetName(name);
        Directo.SetBirthYear(birthyear);
        Directo.SetUciLicenseId(id);
        Directo.SetTeam(team);
        Directo.SetDirectorSince(director_since);
        director_.push_back(Directo); // se hace una copia al final del vector
    }
    return !director_.empty();
}

std::string GetTeam(int team){

    for(const auto &cyclist : cyclist_){
        if(Cyclist.GetCyclistId() == id){
            return cyclist.GetTeam();
        }
    }
    return " ";
}

std::vector<Cyclist> GetByTeam(const std::string &team){

    std::vector<Cyclist> Equipo;
    for(const auto &cyclist : cyclist_){
        if(Cyclist.GetTeam() == team){
            result.push_back(cyclist);
        }
    }
    return result;
}

std::vector<Cyclist> GetYoungest(){

    std::vector<Cyclist> Youngest;
    if(cyclist_.empty()) return Youngest;

    int young_age = cyclist[].GetBirthYear();

    for(const auto &cyclist : cyclist_){
        if(cyclist.GetBirthYear()<young_age){
            young_age=cyclist.GetBirthYear();
        }
    }

    for(const auto &cyclist : cyclist_){
        if(cyclist.GetBirthYear()==young_age){
            result.pushback(cyclist);
        }
    }
    return result;
}