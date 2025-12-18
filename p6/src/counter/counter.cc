#include "counter.h"
#include <iostream>

int Counter :: checkRango(int valor) const{

    if(valor > max_){return max_;}
    if(valor < min_){return min_;}

    return valor;
}

Counter :: Counter(int value, int min, int max){
    if(min > max || value < min || value > max){
        min_ = 0;
        max_ = 1000;
        value_ = 0;
    } else {
        min_ = min;
        max_ = max;
        value_ = value;
    }
}

Counter &Counter :: operator=(int value){
    value_ = checkRango(value);
    return *this;
}

Counter &Counter :: operator=(const Counter &c){
    value_ = checkRango(c.value_);
    return *this;
}

Counter &Counter :: operator++(){
    value_ = checkRango(value_ + 1);
    return *this;
}

Counter Counter :: operator++(int){
    Counter temp = *this;
    value_ = checkRango(value_ + 1);
    return temp;
}

Counter &Counter :: operator--(){
    value_ = checkRango(value_ - 1);
    return *this;
}

Counter Counter :: operator--(int){
    Counter temp = *this;
    value_ = checkRango(value_ - 1);
    return temp;
}

Counter Counter :: operator+(int value) const{
    Counter temp(value_, min_, max_);
    temp.value_ = temp.checkRango(value_ + value);
    return temp;
}

Counter operator+(int value, const Counter &c){
    return c + value;
}

Counter Counter :: operator-(int value) const{
    Counter temp(value_, min_, max_);
    temp.value_ = temp.checkRango(value_ - value);
    return temp;
}

/*ERROR 
Counter operator+(int value, const Counter &c){
    return c - value;
}*/

Counter operator-(int value, const Counter &c){
    Counter temp(c.value_, c.min_, c.max_);
    temp.value_ = temp.checkRango(value - c.value_);
    return temp;
}

std::ostream &operator<<(std::ostream &os, const Counter &c){
    os << c.value_;
    return os;
}

std::istream &operator>>(std::istream &is, Counter &c){
    int value;
    is >> value;
    c.value_ = c.checkRango(value);
    return is;
}
