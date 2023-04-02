#include <iostream>
#include "something.hpp"

Ap::Something::Something(int ikan) {
    this->ikan = ikan + 12;
}

void Ap::Something::sout() {
    std::cout << "Ikan is: " << this-> ikan << " \n";
    std::cout << "Good luck!\n";
}
