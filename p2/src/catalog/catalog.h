#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include "../persons/persons.h"

class CyclistCatalog{

    private:

        std::vector<Cyclist> cyclist_;

    public:

        bool Load(const std::string &path);
        int Size(){return cyclist_.size();}
        std::vector<Cyclist>Data(){return cyclist_;}

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