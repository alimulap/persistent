#include "find_it/2021/qualification/berhitung.hpp"

namespace findit {
    int berhitung() {
        int n;
        std::cin >> n;

        std::vector<int> bebeks(n);
        std::iota(bebeks.begin(), bebeks.end(), 1);

        int i = 0;
        int counter = 0;
        while (bebeks.size() > 1) {
            i = i % bebeks.size();
            bebeks.erase(bebeks.begin() + i);
            i += ++counter;
        }

        return bebeks[0];
    }

    
    int berhitungWithInput(int n) {
        std::vector<int> bebeks(n);
        std::iota(bebeks.begin(), bebeks.end(), 1);

        int i = 0;
        int counter = 0;
        while (bebeks.size() > 1) {
            i = i % bebeks.size();
            bebeks.erase(bebeks.begin() + i);
            i += ++counter;
        }

        return bebeks[0];
    }
    
    void berhitungMultiple() {
        for (int i = 2; i < 100; ++i)
            std::cout << berhitungWithInput(i) << " ";
    }
}
