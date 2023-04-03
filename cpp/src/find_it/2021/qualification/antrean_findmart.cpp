#include "find_it/2021/qualification/antrean_findmart.hpp"
#include <iostream>
#include <vector>
#include <numeric>

void antreanFindmart() {
    int t;
    std::cin >> t;

    int n[t], m[t];
    std::vector<int> antran[t];
    for (int i = 0; i < t; ++i) {
        std::cin >> n[i] >> m[i];
        for (int j = 0; j < m[t]; ++j)
            std::cin >> antran[i][j];
    }

    for (int i = 0; i < t; ++i) {
        if ((std::accumulate(antran[i].begin(), antran[i].end(), 0) + m[i] - 1) > n[i]) {
            std::cout << "OI\n";
            continue;
        }


    }
}
