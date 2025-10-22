#ifndef STAGE_H
#define STAGE_H

#include <string>
#include <map>
#include <vector>
#include "../persons/persons.h"

//Clase Stage

class Stage{

    private:
        
        std::map<std::string, int> delay_; //Mapa para asociar id con su retraso
        int hard_; //Dificultad de la etapa

    public:

        //Constructor
        Stage(int hard);

        //Getters

        std::map<std::string, int> GetDelays() const{return delay_;};
        int GetHard() const{return hard_;};

        //Funciones del programa

        std::map<std::string, int> Simulate(const std::vector<Cyclist> &cyclists);

};

#endif