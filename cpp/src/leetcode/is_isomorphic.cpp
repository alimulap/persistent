#include"../../include/leetcode/is_isomorphic.hpp"
#include <string>

bool isIsomorphic(std::string s, std::string t) {
    short l[130] = {0};
    short r[130] = {0};

    if (s.length() != t.length()) 
        return false;

    for (short i = 0; i < s.length(); i++) {
        if (l[short(s[i])] != r[short(t[i])]) {
            return false;
        }

        l[short(s[i])] = i + 1;
        r[short(t[i])] = i + 1;
    }

    return true;
}
