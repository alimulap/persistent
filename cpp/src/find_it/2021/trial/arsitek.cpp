#include "find_it/2021/trial/arsitek.hpp"

void arsitek() {
    int n = 0;
    std::cin >> n;
    char l = n % 2 == 0 ? '*' : ' ';
    char r = n % 2 == 0 ? '#' : '&';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; ++j)
            std::cout << l;
        for (int j = 0; j < i * 2 + 1; ++j) 
            std::cout << r;
        std::cout << "\n";
    }
}
