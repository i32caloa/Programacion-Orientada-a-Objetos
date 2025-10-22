//**Fichero catalog.h, contiene todas las funciones y clases empleadas en la practica 2 y 3 **//

#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include "../persons/persons.h" //ruta relativa al fichero persons.h

class CyclistCatalog{

    private:

        std::vector<Cyclist> cyclist_;

    public:

        bool Load(const std::string &path);
        int Size(){return cyclist_.size();}
        std::vector<Cyclist>Data(){return cyclist_;}
        std::string GetTeam(const std::string &id);   //Obtener el equipo de un ciclista por ID
        std::vector<Cyclist>GetByTeam(const std::string &team);  //Obtener todos los ciclistas de un equipo
        std::vector<Cyclist>GetYoungest();  //Obtener los ciclistas mas jovenes


};

class DirectorCatalog{

    private:

        std::vector<Director> director_;

    public:

        bool Load(const std::string &path);
        int Size(){return director_.size();}
        std::vector<Director>Data(){return director_;}

};

#endif