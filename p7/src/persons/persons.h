#ifndef PERSONS_H
#define PERSONS_H

#include <string>
#include <iostream>
#include <map>

class IROLE{ //Interfaz

    public:

        virtual std::string GetRole() = 0;
        virtual std::string GetComment() = 0;
        virtual ~IROLE(){}; //~ esta en ALT GR + 4 
};

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

class Cyclist : public Person, public IROLE{

    private:

        std::string team_;
        std::string cyclist_id_;
        std::string self_report_;

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
        bool SetComment(std::string comment);

    //IROLE

        std::string GetRole() override;
        std::string GetComment() override;
};

//CLASE DIRECTOR HEREDA DE PERSON

class Director : public Person, public IROLE{

    private:

        std::string team_;
        std::string uci_license_id_;
        int director_since_;
        std::string team_report_;

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
        bool SetComment(std::string comment);

    //IROLE

        std::string GetRole() override;
        std::string GetComment() override;
};

//DECLARACION DE FUNCIONES

Person ReadPersonFromConsole();
void PrintPersonFromConsole(Person &Persona);

Cyclist ReadCyclistsFromConsole();
void PrintCyclistsFromConsole(Cyclist &Cyclista);

Director ReadDirectorsFromConsole();
void PrintDirectorsFromConsole(Director &Directo);

//Práctica 7

class Journalist : public Person, public IROLE{

    private:

        std::string media_;
        std::map<std::string, std::string> comments_;

    public:

    //CONSTRUCTORES

        Journalist();
        Journalist(const std::string name, int birth_year, const std::string media);

    //GETTERS

        std::string GetMedia(){return media_;}

    //SETTERS

        bool SetMedia(std::string media_);
        bool SetComment(std::string id, std::string comment);

    //IROLE

        std::string GetRole() override;
        std::string GetComment() override;
};

std::string PrintComment(IROLE *role);

#endif