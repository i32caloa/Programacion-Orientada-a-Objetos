#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User{

    private:

        std::string id_;
        std::string surname_;
        std::string name_;
        std::string nationality_;
        int d_;
        int m_;
        int y_;
        bool complete_;

    public:

        User(const std::string id);
        User(const std::string id, const std::string surname, const std::string name, const std::string nationality, int d, int m, int y);

        //*****************//
        //*****GETTERS*****//
        //*****************//

        std::string GetId(){return id_;}
        std::string GetSurname(){return surname_;}
        std::string GetName(){return name_;}
        std::string GetNationality(){return nationality_;}
        int GetDay(){return d_;}
        int GetMonth(){return m_;}
        int GetYear(){return y_;}
        bool GetComplete(){return complete_;}

        //*****************//
        //*****SETTERS*****//
        //*****************//

        bool SetId(std::string id);
        bool SetSurname(std::string surname);
        bool SetName(std::string name);
        bool SetNationality(std::string nationality);
        bool SetDay(int d);
        bool SetMonth(int m);
        bool SetYear(int y);

        std::string GetFullData();

};

//Declaracion de funciones en el programa

User ReadUserFromConsole();
void PrintUserFromConsole(User &Usuario);

#endif