#include "persons.h"
#include <iostream>

int main() {

    Cyclist c("Antonio Cañete López", 2003, "Tinkoff", "d46271661p");
    Director d("David Martínez Molina", 2005, "Tinkoff", "ud462716662p", 2020);
    Journalist j("Dario Martinez Kostyuk", 2005, "Cordópolis");

    c.SetComment("He pinchado");
    d.SetComment("Mi abuela va mas rapido que el equipo"); //Gracias por las declaraciones
    j.SetComment("001", "Mal rendimiento del equipo Tinkoff");
    j.SetComment("002", "Antonio Cañete López ha pinchado");

    std::cout << "Cyclist Role: " << c.GetRole() << "\n";
    std::cout << "Cyclist Comment: " << PrintComment(&c) << "\n";

    std::cout << "Director Role: " << d.GetRole() << "\n";
    std::cout << "Director Comment: " << PrintComment(&d) << "\n";

    std::cout << "Journalist Role: " << j.GetRole() << "\n";
    std::cout << "Journalist Comment: " << PrintComment(&j) << "\n";

    return 0;
}