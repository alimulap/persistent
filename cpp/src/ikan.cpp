#include<iostream>
#include"../include/ikan.hpp"

Ikan::Ikan() {
    this->something = 12;
    this->apapun = "ikan ga sih";
}

void Ikan::sout() {
    std::cout << this->apapun << " " << this->something;
}

