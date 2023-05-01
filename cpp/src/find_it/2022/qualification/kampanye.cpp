#include "find_it/2022/qualification/kampanye.hpp"
#include <iostream>

void findit::kampanye() {
    int n;
    std::cin >> n;

    int politisi[3][n];
    for (int i = 0; i < n; ++i) {
        std::cin >> politisi[0][i] >> politisi[1][i] >> politisi[2][i];
    }

    int opCost = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            if (politisi[0][i] < politisi[0][j] && politisi[1][i] > politisi[1][j]
                || politisi[0][i] > politisi[0][j] && politisi[1][i] < politisi[1][j])
            {
                opCost += politisi[2][i];
                break;
            }
        }
    }
    std::cout << opCost;
}
