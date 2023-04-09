#include "find_it/2021/qualification/jaga_jarak.hpp"

namespace findit {
    int jagaJarak() {
        int n, d;
        std::cin >> n >> d;

        int a[n];
        for (int& i : a)
            std::cin >> i;

        int x;

        if ((a[1] - a[0]) > (a[n-1] - a[n-2])) {
            int req = a[1] - d;
            x = abs(req - a[0]);
            a[0] = req;
            for (int i = 1; i < n; ++i) {
                req = a[i-1] + d;
                x += abs(req-a[i]);
                a[i] = req;
            }
        } else {
            int req = a[n-2] + d;
            x = abs(req - a[0]);
            a[n-1] = req;
            for (int i = n-2; i > 0; --i) {
                req = a[i+1] - d;
                x += abs(req-a[i]);
                a[i] = req;
            }
        }

        //int dis = a[n-1] - a[0];
        //int req = d * (n-1) - dis;

        //int x;
        //a[n-1] += req;
        //x = req;
        //for (int i = n-2; i >= 0; --i) {
        //    req = a[i+1] - d;
        //    x += abs(req - a[i]);
        //    a[i] = req;
        //}

        for (int& i : a)
            std::cout << i << " ";
        std::cout << "\n";

        return x;
    }
}
