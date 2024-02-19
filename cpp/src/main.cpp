#include "find_it/2022/qualification/menebak_angka.hpp"
#include <ctime>
#include <iostream>

int main() {
    int t;
    std::cin >> t;

    int n[t];
    for (int i = 0; i < t; ++i)
        n[i] = i + 1;

    long start = std::clock();
    findit::menebakAngka(t, n);
    std::cout << "\n\n" << std::clock() - start;
    return 0;
}
