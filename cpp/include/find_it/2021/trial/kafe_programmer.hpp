#include <iostream>
#include <algorithm>

namespace findit {
    struct Pembeli {
        int t;
        int l;
    };

    bool compare(Pembeli& a, Pembeli& b);

    int kafeProgrammer();

    void bubbleSortUnq(int** arr, int size);

    int kafeProgrammerStruct();
}
