#include <queue>
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include "find_it/2021/qualification/kebun.hpp"

using String = std::string;

void findit::kebun() {
    int n;
    std::cin >> n;

    std::queue<String> kebuns[n];

    for (int i = 0; i < n; ++i) {
        int t;
        std::cin >> t;

        String input;
        for (int j = 0; j < 2 * n; ++j) {
            std::cin >> input;
            kebuns[i].emplace(input);
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << "a\n";
        int lane = 1;
        String temp = kebuns[i].front();
        kebuns[i].pop();
        //String temp2;
        std::queue<String> tempQueue;
        while (true) {
            std::vector<String> tempVec;
            if (!kebuns[i].empty()) {
                while (kebuns[i].front() != temp) {
                    tempVec.emplace_back(kebuns[i].front());
                    kebuns[i].pop();
                }
            } else {
                while (tempQueue.front() != temp) {
                    tempVec.emplace_back(tempQueue.front());
                    tempQueue.pop();
                }
            }

            bool hasSolution = true;
            for (int j = 0; j < tempVec.size(); ++j) {
                bool hasCouple = false;
                for (int k = j+1; k < tempVec.size(); ++k) {
                    if (tempVec[i] == tempVec[k]) {
                        hasCouple = true;
                        break;
                    }
                }
                if (!hasCouple) {
                    hasSolution = false;
                    break;
                }
            }
            if (!hasSolution) {
                lane = -1;
                break;
            }

            if (kebuns[n-1].empty() && tempQueue.empty())
                break;

            if (tempVec.empty() && kebuns[i].empty() && tempQueue.empty())
                continue;
            else 
                lane++;

            while (!kebuns[i].empty() && !tempQueue.empty()) {
                if (!kebuns[i].empty()) {
                    tempVec.emplace_back(kebuns[i].front());
                    kebuns[i].pop();
                } else {
                    tempVec.emplace_back(tempQueue.front());
                    tempQueue.pop();
                }
            }
        }
        std::cout << "solution#" << (i+1) << "=" << lane << "\n";
    }
}
