#include "user.h"
#include <string>
#include <iostream>

//Constructor vacio con id

User::User(const std::string id){

    id_=id;
    surname_=" ";
    name_=" ";
    nationality_=" ";
    d_=0;
    m_=0,
    y_=0;
    complete_=false;

}

//Constructor completo

User::User(const std::string id, const std::string surname, const std::string name, const std::string nationality, int d,int m, int y){

    id_=id;
    surname_=surname;
    name_=name;
    nationality_=nationality;
    d_=d;
    m_=m;
    y_=y;
    complete_=true;

    if(id == " " || surname == " " || name == " " || nationality == " " || d<1 || d>31 || m<1 || m>12 || y<1950 || y>2025 ){
       
        complete_=false;

    }
}

//Setters

bool User::SetId(std::string id){

    if(id==" "){return false;}
    else{ 
        id_=id;
        return true;
    }
}

bool User::SetSurname(std::string surname){

    if(surname==" "){return false;}
    else {
        surname_=surname;
        return true;
    }
}

bool User::SetName(std::string name){

    if(name==" "){return false;}
    else{ 
        name_=name;
        return true;
    }
}

bool User::SetNationality(std::string nationality){

    if(nationality==" "){return false;}
    else{
        nationality_=nationality;
        return false;
    }
}

bool User::SetDay(int d){

    if(d<1 || d>31){return false;}
    else{
        d_=d;
        return true;
    }
}

bool User::SetMonth(int m){

    if(m<1 || m>12){return false;}
    else{
        m_=m;
        return true;
    }
}

bool User::SetYear(int y){

    if(y<1950 || y>2025){return false;}
    else{
        y_=y;
        return true;
    }
}

//Funciones del programa

User ReadUserFromConsole(){

    std::string id, name, surname, nationality;
    int d, m, y;

    std::cout<<"\n***** USUARIO *****\n";
    std::cout<<"\nId: ";
    std::getline(std::cin, id);
    std::cout<<"\nSurname: ";
    std::getline(std::cin, surname);
    std::cout<<"\nName: ";
    std::getline(std::cin, name);
    std::cout<<"\nNationality: ";
    std::getline(std::cin, nationality);
    std::cout<<"\nBirth Day: ";
    std::cin>>d;
    std::cout<<"\nBirth Month: ";
    std::cin>>m;
    std::cout<<"\nBirth Year: ";
    std::cin>>y;

    User Usuario(id, surname, name, nationality, d, m, y);

    return Usuario;

}

void PrintUserFromConsole(User &Usuario){

    std::cout<<"\n***** USUARIO *****\n";
    std::cout<<"\nId: "<<Usuario.GetId();
    std::cout<<"\nSurname: "<<Usuario.GetSurname();
    std::cout<<"\nName: "<<Usuario.GetName();
    std::cout<<"\nNationality: "<<Usuario.GetNationality();
    std::cout<<"\nBirth Day: "<<Usuario.GetDay();
    std::cout<<"\nBirth Month: "<<Usuario.GetMonth();
    std::cout<<"\nBirth Year: "<<Usuario.GetYear();
    std::cout<<"\n********************\n";

}

std::string User::GetFullData(){

    return GetId() + ", " + GetSurname() + ", " + GetName() + ", " + GetNationality() + ", " + std::to_string(GetDay()) + ", " + std::to_string(GetMonth()) + ", " + std::to_string(GetYear());

}
