#include <cmath>
#include <iostream>
#include "random/a.hpp"

void theFunc() {
    int n;
    std::cin >> n;
    
    int x = 0, y = 0, count = 0;
    while (true) {
        ++count;
        if (count == n) break;

        if (y < x)
            ++y;
        else {
            y = 0;
            ++x;
        }
    }
    std::cout << x << " " << y;
}

void theFunc2() {
int n;
    std::cin >> n;

    int a = 1; // nilai awal deret aritmatika
    int d = 1; // selisih antar bilangan
    int un = (std::sqrt(8*n + 1) - 1) / 2; // mencari suku ke-n
    int sn = un*(2*a + (un-1)*d) / 2; // mencari jumlah deret hingga suku ke-n
    int x = un - (sn - n); // posisi a dalam deret
    int y = un + 1 - x; // posisi b dalam deret

    std::cout << "a ada di posisi ke-" << x << std::endl;
    std::cout << "b ada di posisi ke-" << y << std::endl;
}

void theFunc3(int n) {
    //int n;
    //std::cin >> n;

    int x = 1, xd = 1, y = 0, yd = 1;
    for (int i = 0; i < n; ++i) {
        if (x == 1) 
            x = xd++;
        else
            --x;
        if (y == yd) { 
            y = 1;
            yd++;
        }
        else 
            ++y;
    }

    std::cout << x << " " << y;
}

void theFunc4(int n) {
    //int n;
    //std::cin >> n;

    int d = 8 * n + 1;
    int un = ((std::sqrt(d) - 1) / 2);
    int unceil = std::ceil((std::sqrt(d) - 1) / 2);
    int sn = un/2.*(1+un);
    int x = n - sn != 0 ? unceil - (n - sn) + 1
                        : 1;
    int y = n == 1  ? 1 
          : n == sn ? un 
                    : n - sn;
    std::cout << x << " " << y << "\n";
}

