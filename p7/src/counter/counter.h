#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>

class Counter{

    private:

        int value_;
        int min_;
        int max_;

        int checkRango(int value) const;

    public:

        Counter(int value = 0, int min = 0, int max = 1000);

        int Get() const { return value_;}
        int GetMin() const {return min_;}
        int GetMax() const {return max_;}

        Counter &operator = (int value);
        Counter &operator = (const Counter &c);

        //Prefijos y Sufijos

        Counter &operator++();
        Counter operator++(int);
        
        Counter &operator--();
        Counter operator--(int);

        //Operadores aritmeticos

        Counter operator+(int value)const;
        friend Counter operator+(int value, const Counter &c);

        Counter operator-(int value) const;
        friend Counter operator-(int value, const Counter &c);

        //Insertar 
        //ostream con const porq no se modifica el objeto

        friend std::ostream &operator<<(std::ostream &os, const Counter &c);

        //Extraer
        //istream sin const porq se modifica el objeto

        friend std::istream &operator>>(std::istream &is, Counter &c);
};

#endif