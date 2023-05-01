#include "find_it/2022/qualification/buka_puasa_bersama.hpp"
#include <iostream>

void findit::bukaPuasaBersama() {
    int t;
    std::cin >> t;

    int testCase[t];
    for (int& i : testCase)
        std::cin >> i;

    for (int& i : testCase) {
        int mod = i % 12;
        int res = (i - mod)*2 + 10;
        if (mod > 0) {
            if (i % 10 == 0)
                res += 20;
            else 
                res += 16;
        }
        std::cout << res << " ";
    }
}

