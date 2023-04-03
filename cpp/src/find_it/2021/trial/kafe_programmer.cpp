#include "find_it/2021/trial/kafe_programmer.hpp"

bool findit::compare(Pembeli& a, Pembeli& b) {
    return a.l < b.l;
}

int findit::kafeProgrammerStruct() {
    int n;
    std::cin >> n;

    Pembeli p[n];

    for (int i = 0; i < n; ++i)
        std::cin >> p[i].t >> p[i].l;
    std::cout << "\n";

    for (Pembeli i : p)
        std::cout << i.t << " " << i.l << "\n";
    std::cout << "\n";

    std::sort(p, p+n, compare);

    for (Pembeli i : p)
        std::cout << i.t << " " << i.l << "\n";
    std::cout << "\n";

    int res = p[0].l;
    int prev = p[0].l;

    std::cout << prev << "a\n";

    for (int i = 1; i < n; ++i) {
        prev = (p[i].t < p[i-1].t + prev) ?
            p[i-1].t + prev - p[i].t + p[i].l :
            p[i].l;

        std::cout << prev << " ";

        res += prev;
    }
    std::cout << "\n";

    return res/n;
}

int findit::kafeProgrammer() {
    int n;
    std::cin >> n;

    int** p = new int*[n];
    for (int i = 0; i < n; ++i)
        p[i] = new int[2];

    for (int i = 0; i < n; ++i) {
        std::cin >> p[i][0] >> p[i][1];
    }

    bubbleSortUnq(p, n);

    int res = p[0][1];
    int prev = p[0][1];

    for (int i = 1; i < n; ++i) {
        prev = (p[i][0] < p[i-1][0] + prev) ? 
            p[i-1][0] + prev - p[i][0] + p[i][1] :
            p[i][1];

        res += prev; 
    }

    return res/n;
}

void findit::bubbleSortUnq(int** arr, int size) {
    int* temp;
    for (int i = 0; i < size; ++i) {
        for (int j = 1; j < size - i; ++j) {
            if (arr[j][1] < arr[j-1][1]) {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

