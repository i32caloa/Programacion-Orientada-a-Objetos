#ifndef USER_H
#define USER_H

#include <string>

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

    //CONSTRUCTORES

        User(std::string id);
        User(std::string id, std::string surname, std::string name, std::string nationality, int d, int m, int y);

    //GETTERS

        std::string GetId(){return id_;}
        std::string GetSurname(){return surname_;}
        std::string GetName(){return name_;}
        std::string GetNationality(){return nationality_;}
        int GetD(){return d_;}
        int GetM(){return m_;}
        int GetY(){return y_;}
        bool GetComplete(){return complete_;}

    //SETTERS

        bool SetId(std::string id);
        bool SetSurname(std::string surname);
        bool SetName(std::string name);
        bool SetNationality(std::string nationality);
        bool SetD(int d);
        bool SetM(int m);
        bool SetY(int y);
        
        std::string GetFullData();
};

User ReadFromConsole();
void PrintfFromConsole(User &Usuario);

#endif