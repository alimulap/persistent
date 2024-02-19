#include "find_it/2022/qualification/menebak_angka.hpp"

void findit::menebakAngka(int t, int n[]) {
    unsigned long pembagi[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    unsigned long output[t];
    unsigned long temp = 1;
    for (int i = 0; i < t; ++i) {
        output[i] = 1;
        for (unsigned long j = 2; j <= n[i]; ++j) {
            temp = 0;
            for (unsigned long k : pembagi) 
                if (j % k == 0) {
                    ++temp;
                }
            output[i] = (output[i] * temp) % 1000000007;
        }
    }

    for (unsigned long i : output) 
        std::cout << i << "\n";
}

