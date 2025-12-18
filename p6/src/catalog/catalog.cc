#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../persons/persons.h"
#include "catalog.h"

bool CyclistCatalog::Load(const std::string &path) {
    Cyclist c;
    std::string name, birth_s, id, team;
    int birthyear = 0;

    cyclist_.clear(); 
    std::ifstream in(path);

    if (!in) {
        return false;
    }

    std::string line;
    if (!std::getline(in, line)) return false;

    while (std::getline(in, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line);

        if (!std::getline(iss, name, ',')) continue;
        if (!std::getline(iss, birth_s, ',')) continue;
        if (!std::getline(iss, id, ',')) continue;
        if (!std::getline(iss, team)) continue;

        try {
            birthyear = std::stoi(birth_s);
        } catch (...) {
            continue; 
        }

        c.SetName(name);
        c.SetBirthYear(birthyear);
        c.SetCyclistId(id);
        c.SetTeam(team);
        
        cyclist_.push_back(c);
    }
    return !cyclist_.empty();
}

bool DirectorCatalog::Load(const std::string &path) {
    Director d;
    std::string name, birth_s, uci_license_id, team, d_since;
    int birthyear = 0, director_since=0;

    director_.clear();
    std::ifstream in(path);

    if(!in){
        return false;
    }

    std::string line;
    if (!std::getline(in, line)) return false;

    while (std::getline(in, line)) {
        if (line.empty()) continue;
        
        std::istringstream iss(line);
        
        if (!std::getline(iss, name, ',')) continue;
        if (!std::getline(iss, birth_s, ',')) continue;
        if (!std::getline(iss, uci_license_id, ',')) continue;
        if (!std::getline(iss, team, ',')) continue;
        if (!std::getline(iss, d_since)) continue;

        try {
            birthyear = std::stoi(birth_s);
            director_since = std::stoi(d_since);
        } catch (...) {
            continue;
        }

        d.SetName(name);
        d.SetBirthYear(birthyear);
        d.SetUciLicenseId(uci_license_id);
        d.SetTeam(team);
        d.SetDirectorSince(director_since);
        
        director_.push_back(d);
    }
    return !director_.empty();
}

std::vector<Cyclist> CyclistCatalog::GetByTeam(const std::string &team){
    std::vector<Cyclist> CyclistTeam;
    for(auto &ct : cyclist_){
        if(ct.GetTeam() == team){
            CyclistTeam.push_back(ct);
        }
    }
    return CyclistTeam;
}

std::vector<Cyclist> CyclistCatalog::GetYoungest(){
    std::vector<Cyclist> young;
    int menor = 0;

    //Año mas joven
    for(auto &y : cyclist_){
        if(y.GetBirthYear() > menor){
            menor = y.GetBirthYear();
        }
    }

    //Ciclistas mas jovesnes
    for(auto &y : cyclist_){
        if(y.GetBirthYear() == menor){
            young.push_back(y);
        }
    }
    return young;
}

std::string CyclistCatalog::GetTeam(const std::string &id){
    for(auto &t : cyclist_){
        if(t.GetCyclistId() == id){
            return t.GetTeam();
        }
    }
    return "";
}

void CyclistCatalog::Add(const Cyclist &c){ 
    cyclist_.push_back(c);
}

CyclistCatalog &CyclistCatalog :: operator<<(const Cyclist &c){
    Add(c);
    return *this;
}

