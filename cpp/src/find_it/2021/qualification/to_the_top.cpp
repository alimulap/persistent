#include "find_it/2021/qualification/to_the_top.hpp"
#include <iostream>
#include <numeric>

void findit::toTheTop() {
    int m, x, h, s;
    std::cin >> m >> x >> h >> s;

    int habis = 0;
    for (int i = m+x*(h-1); i <= m+x*(h-1)*2; i+=x)
        habis += i;
    std::cout << s - habis;
}
