#include "../persons/persons.h"
#include "../catalog/catalog.h"
#include "stage.h"
#include <map>
#include <string>
#include <map>
#include <random>

Stage::Stage(int hard){

    if(hard < 1){
        hard_ = 1;
    }else if(hard > 5){
        hard_ = 5;
    } else {
        hard_= hard;
    }
}

std::map<std::string, int> Stage::Simulate(const std::vector<Cyclist> &Cyclists){

    delay_.clear();  //limpiar mapa por lo q pueda tener

    if(Cyclists.empty()){
        std::cerr<<"\nNO SE ENCONTRARON CICLISTAS\n";
        exit(EXIT_FAILURE);
    }



    int maxDelay = hard_*400;

    //Numeros aleatorios REVISAR

    std::random_device rdCyclist;  //Semilla
    std::mt19937 genCyclist(rdCyclist()); //Generador
    std::uniform_int_distribution<size_t> distCyclist(0, Cyclists.size()-1); //Distribucion

    size_t winnerCyclist = distCyclist(genCyclist); //Indice del ganador

    std::string cyclistId = const_cast<Cyclist&>(Cyclists[winnerCyclist]).GetCyclistId(); //ID del ganador
    delay_[cyclistId] = 0;

    std::random_device rd;
    std::mt19937 generate(rd());
    std::uniform_int_distribution<int> dist(0, maxDelay);

    for(int i=0; i < Cyclists.size(); i++){

        if(i != winnerCyclist){
            int delay = dist(generate);
            std::string id = const_cast<Cyclist&>(Cyclists[i]).GetCyclistId();
            delay_[id] = delay;
        }
    }
    return delay_;
}