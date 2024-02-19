#include "find_it/2021/trial/anak_kadal.hpp"

void anakKadal() {
    int t;
    std::cin >> t;
    int n[t];

    for (int i = 0; i < t; ++i) {
        std::cin >> n[i];
    }

    for (int i = 0; i < t; ++i) {
        int inc = n[i] % 2 == 0 ? 1 : 2;
        std::cout << n[i] + inc << " " << n[i] + inc + 2 << " " << n[i] + inc + 4 << "\n";
    }
}
