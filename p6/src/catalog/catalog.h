#ifndef CATALOG_H
#define CATALOG_H

#include "../persons/persons.h"
#include <vector>

class CyclistCatalog{

    private:

        std::vector<Cyclist> cyclist_;

    public:

        bool Load(const std::string &path);
        int Size() const {return cyclist_.size();}
        std::vector<Cyclist> &Data(){return cyclist_;}

        std::string GetTeam(const std::string &id);
        std::vector<Cyclist>GetByTeam(const std::string &team);
        std::vector<Cyclist>GetYoungest();

        void Add(const Cyclist &Cyclist);

        CyclistCatalog& operator<<(const Cyclist &c);
    };

class DirectorCatalog{

    private:

        std::vector<Director> director_;

    public:

        bool Load(const std::string &path);
        int Size(){return director_.size();}
        std::vector<Director> Data(){return director_;}
};


#endif