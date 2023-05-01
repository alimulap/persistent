#include "find_it/2022/qualification/berburu_asteroid.hpp"

void findit::berburuAsteroid() {
    int t;
    std::cin >> t;
    std::cin.ignore();

    std::vector<int> asteroids[t];
    for (int i = 0; i < t; ++i) {
        std::string input;
        std::getline(std::cin, input);

        std::istringstream iss(input);
        std::string word;

        while (iss >> word)
            asteroids[i].emplace_back(std::stoi(word));
    }

    int shots[t];
    int temp;
    for (int i = 0; i < t; ++i) {
        shots[i] = 0;
        while (!asteroids[i].empty()) {
            temp = asteroids[i][0];
            asteroids[i].erase(asteroids->begin());
            ++shots[i];
            for (auto j = asteroids[i].begin(); j != asteroids[i].end();)
                if (temp - 1 == *j) j = asteroids[i].erase(j);
                else j++;
        }
    }

    for (int i = 0; i < t; ++i) std::cout << shots[i] << "\n";
}

