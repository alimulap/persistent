#include "find_it/2021/trial/anak_pasar_jangkrik.hpp"
#include <functional>

std::string findit::anakPasarJangkrik() {
    int x1, v1, x2, v2;
    std::cin >> x1 >> v1 >> x2 >> v2;

    if (v1 == v2) 
        return "NO";
    else if (x1 > x2 && v1 > v2)
        return "NO";
    else if (x2 > x1 && v2 > v1)
        return "NO";

    //if ((x1-x2)%(v1-v2) == 0 || (x2-x1)%(v2-v1) == 0)
    //    return "YES";
    //else
    //    return "NO";

    // for keep track salip salip an
    //
    //
    
    std::function<bool(int, int)> conditionX;

    auto condition = x1 > x2 ? 
        [](int l, int r) -> bool { return l > r; } : 
        [](int l, int r) -> bool { return r > l; };

    while (condition(x1,x2)) {
        x1 += v1;
        x2 += v2;
        if (x1 == x2) {
            return "YES";
        }
    }
    return "NO";
}
