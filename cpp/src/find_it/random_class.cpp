#include "find_it/random_class.hpp"
#include <iostream>

RandomClass::RandomClass(int i) {
    this->ikan = i;
}

void RandomClass::sout() {
    std::cout << "Ikaaaaan " << this->ikan << "!!!\n";
}
