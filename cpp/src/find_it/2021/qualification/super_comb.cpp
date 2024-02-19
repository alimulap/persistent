#include "find_it/2021/qualification/super_comb.hpp"
#include <iostream>

void findit::superComb() {
    int n;
    std::cin >> n;

    float supercomb[n];
    for (float& i : supercomb)
        std::cin >> i;

    for (int i = 0; i < n; ++i) {
        if (supercomb[i] < 1)
            std::cout << 0 << " ";
        else {
            int res = 1;
            supercomb[i] -= 1;

            int pertiga = supercomb[i] / 3;
            std::cout << "(" << pertiga << ")";
            res += pertiga*2 + ((supercomb[i] - pertiga*3) > 1.5f ? 1 : 0);

            std::cout << res << " ";
        }
    }
}

