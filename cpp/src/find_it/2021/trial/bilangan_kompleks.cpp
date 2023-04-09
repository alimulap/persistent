#include "find_it/2021/trial/bilangan_kompleks.hpp"

void bilangan_kompleks() {
    int a1, b1, a2, b2;
    std::cin >> a1 >> b1 >> a2 >> b2;
    std::cout << (a1 * a2 - b1 * b2) << " " << (a1 * b2 + a2 * b1);
}
