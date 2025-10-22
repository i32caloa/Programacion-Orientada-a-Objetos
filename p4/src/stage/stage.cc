#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <random>
#include "stage.h"

//Constructor

Stage::Stage(int hard){

    if(hard<1){ //Si es menor de 1, 1 como predeterminado

        hard_ = 1; 

    } else if(hard>5){

        hard_ = 5; //Si es mayor de 5, 5 como predeterminado

    } else{

        hard_ = hard;
    }

    delay_.clear(); //Vaciar mapa

}

//Funcion del programa 

std::map<std::string, int> Stage::Simulate(const std::vector<Cyclist> &cyclists){

    delay_.clear(); //Vaciar mapa

    if(cyclists.empty()){
        return delay_;
    }

    int max_delay = hard_*400; //Calculo del retraso maximo segun la dureza

    //Ganador (delay 0) REVISAR

    std::random_device rd_cyclist;  //Semilla
    std::mt19937 gen_cyclist(rd_cyclist()); //Generador
    std::uniform_int_distribution<size_t> dist_cyclist(0, cyclists.size()-1); //Distribucion
    size_t winner_cyclist = dist_cyclist(gen_cyclist); //Indice del ganador
    std::string cyclist_id = const_cast<Cyclist&>(cyclists[winner_cyclist]).GetCyclistId(); //ID del ganador
    delay_[cyclist_id] = 0;

    //Numeros aleatorios REVISAR

    std::random_device rd;
    std::mt19937 generador(rd());
    std::uniform_int_distribution<int> dist(0, max_delay);

    for(size_t i=0; i<cyclists.size(); i++){

        if(i!=winner_cyclist){

            int delay = dist(generador);
            std::string id = const_cast<Cyclist&>(cyclists[i]).GetCyclistId();
            delay_[id] = delay;
        }
    }
    return delay_;
}

