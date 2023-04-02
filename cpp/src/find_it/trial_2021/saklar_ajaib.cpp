#include "find_it/trial_2021/saklar_ajaib.hpp"

int saklarAjaib() {
    int n;
    std::cin >> n;

    int lampu[n];

    for (int i = 0; i < n; ++i) 
        std::cin >> lampu[i];

    bool end = false;
    int langkah = 0;
    while (!end) {
        end = true;
        //for (int i : lampu)
        //    std::cout << i;
        //std::cout << "\n";
        for (int i = 0; i < n; ++i) {
            if (lampu[i] == 1) {
                //std::cout << "a";
                end = false;
                
                for (int j = i; j < n && i != n-1; ++j) {
                    if (lampu[j] == 1)
                        lampu[j] = 0;
                    else
                        lampu[j] = 1;
                }

                if (i == n-1)
                    lampu[i] = 0;

                langkah++;
            }
        }
    }

    return langkah;
}

int saklarAjaibAlt() {
    int n;
    std::cin >> n;

    int lampu[n];
    for (int i = 0; i < n; ++i)
        std::cin >> lampu[i];

    int langkah = (lampu[0] == 1) ? 1 : 0;
    int prev = lampu[0];

    for (int i = 1; i < n; ++i)
        if (lampu[i] != prev) {
            langkah++;
            prev = lampu[i];
        }

    return langkah;
}

