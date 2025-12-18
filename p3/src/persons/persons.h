#ifndef PERSONS_H
#define PERSONS_H

#include <string>
#include <iostream>

class Person{

    private:

        std::string name_;
        int birth_year_;

    public:

    //CONSTRUCTORES

        Person();
        Person(const std::string name, int birth_year);

    //GETTERS

        std::string GetName(){return name_;}
        int GetBirthYear(){return birth_year_;}

    //SETTERS

        bool SetName(std::string name);
        bool SetBirthYear(int birth_year);

};

//CLASE CYCLIST HEREDA DE OERSON

class Cyclist : public Person{

    private:

        std::string team_;
        std::string cyclist_id_;

    public:

    //CONSTRUCTORES

        Cyclist();
        Cyclist(const std::string name, int birth_year, const std::string team, const std::string cyclist_id);

    //GETTERS

        std::string GetTeam(){return team_;}
        std::string GetCyclistId(){return cyclist_id_;}

    //SETTERS

        bool SetTeam(std::string team);
        bool SetCyclistId(std::string cyclist_id);

};

//CLASE DIRECTOR HEREDA DE PERSON

class Director : public Person{

    private:

        std::string team_;
        std::string uci_license_id_;
        int director_since_;

    public:

    //CONSTRUCTORES

        Director();
        Director(const std::string name, int birth_year, const std::string team, const std::string uci_license_id, int director_since);

    //GETTERS

        std::string GetTeam(){return team_;}
        std::string GetUciLicenseId(){return uci_license_id_;}
        int GetDirectorSince(){return director_since_;}

    //SETTERS

        bool SetTeam(std::string team);
        bool SetUciLicenseId(std::string uci_license_id);
        bool SetDirectorSince(int director_since);

};

//DECLARACION DE FUNCIONES

Person ReadPersonFromConsole();
void PrintPersonFromConsole(Person &Persona);

Cyclist ReadCyclistsFromConsole();
void PrintCyclistsFromConsole(Cyclist &Cyclista);

Director ReadDirectorsFromConsole();
void PrintDirectorsFromConsole(Director &Directo);

#endif