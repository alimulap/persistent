#include "find_it/trial_2021/eternal_labyrinth.hpp"

int eternalLabyrinth() {
    int r, c;
    std::cin >> r >> c;

    int labyrinth[r][c];

    for (int i = 0; i < r * c; ++i)
        std::cin >> labyrinth[i/c][i%c];

    int res = 0;

    std::vector<Point> p;
    p.emplace_back(Point{ 0,0 });

    bool moved;
    while (!p.empty()) {
        for (int i = 0; i < p.size(); ++i) {
            moved = false;
            if (p[i].x + 1 < c && labyrinth[p[i].y][p[i].x + 1] != -1) {
                p[i].x++;
                moved = true;
            }
            if (p[i].y + 1 < r && labyrinth[p[i].y + 1][p[i].x - moved] != -1) {
                if (moved) 
                    p.emplace_back(Point { (short)(p[i].x - 1), (short)(p[i].y + 1) });
                else {
                    p[i].y++;
                    moved = true;
                }
            }

            if ((p[i].x == c - 1 && p[i].y == r - 1) || !moved) {
                p.erase(p.begin() + i);
                res++;
            }
        }
    }

    return res;
}

