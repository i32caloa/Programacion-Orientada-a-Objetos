#include "user.h"
#include <iostream>
#include <string>

User::User(std::string id){

    id_ = id;
    surname_ = " ";
    name_ = " ";
    nationality_ = " ";
    d_ = 0;
    m_ = 0;
    y_ = 0;
    complete_ = false;
}

User::User(std::string id, std::string surname, std::string name, std::string nationality, int d, int m, int y){

    id_ = id;
    surname_ = surname;
    name_ = name;
    nationality_ = nationality;
    d_ = d;
    m_ = m;
    y_ = y;
    complete_ = true;

    if (id == " " || surname == " " || name == " " || nationality == " " || d < 1 || d > 31 || m < 1 || m > 31 || y < 1925 || y > 2025){
        complete_ = false;
    }
}

bool User::SetId(std::string id){

    if(id == " "){return false;}
    else{
        id_ = id;
        return true;
    }
}

bool User::SetSurname(std::string surname){

    if(surname == " "){return false;}
    else{
        surname_ = surname;
        return true;
    }
}

bool User::SetName(std::string name){

    if(name == " "){return false;}
    else{
        name_ = name;
        return true;
    }
}

bool User::SetNationality(std::string nationality){

    if(nationality == " "){return false;}
    else{
        nationality_ = nationality;
        return true;
    }
}

bool User::SetD(int d){

    if(d < 1 || d > 31){return false;}
    else{
        d_ = d;
        return true;
    }
}

bool User::SetM(int m){

    if(m < 1 || m > 12){return false;}
    else{
        m_ = m;
        return true;
    }
}

bool User::SetY(int y){

    if(y < 1925 || y > 2025){return false;}
    else{
        y_ = y;
        return true;
    }
}
User ReadFromConsole(){

    std::string id, name, surname, nationality;
    int d = 0, m = 0, y = 0;

    std::cout<<"\n-----Nuevo Usuario-----\n";

    std::cout<<"\nID: ";
    std::getline(std::cin, id);

    std::cout<<"Surname: ";
    std::getline(std::cin, surname);

    std::cout<<"Name: ";
    std::getline(std::cin, name);

    std::cout<<"Nationality: ";
    std::getline(std::cin, nationality);

    std::cout<<"Day: ";
    std::cin>>d;

    std::cout<<"Month: ";
    std::cin>>m;

    std::cout<<"Year: ";
    std::cin>>y;

    User Usuario(id, surname, name, nationality, d, m, y);

    return Usuario;
}

void PrintfFromConsole(User &Usuario){

    std::cout<<"\n-----Usuario-----\n";
    std::cout<<"\nID: "<<Usuario.GetId();
    std::cout<<"\nSurname: "<<Usuario.GetSurname();
    std::cout<<"\nName: "<<Usuario.GetName();
    std::cout<<"\nNationality: "<<Usuario.GetNationality();
    std::cout<<"\nDate: "<<Usuario.GetD()<<" / "<<Usuario.GetM()<<" / "<<Usuario.GetY();

}

std::string User::GetFullData(){

    return "\nId: " + GetId() + ",  Surname: " + GetSurname() + ", Name: " + GetName() + ", Nationality: " + GetNationality() + ", Date: " + std::to_string(GetD()) + " / " + std::to_string(GetM()) + " / " + std::to_string(GetY());

}





