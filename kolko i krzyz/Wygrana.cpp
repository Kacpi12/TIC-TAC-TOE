#include <iostream>
#include <fstream>
#include <cstdlib>

template<typename T>
auto wygrana(T tab[][3]) ->bool {
    bool win = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((tab[0][0] == 1) && (tab[0][1] == 1) && (tab[0][2] == 1) ||
                (tab[1][0] == 1) && (tab[1][1] == 1) && (tab[1][2] == 1) ||
                (tab[2][0] == 1) && (tab[2][1] == 1) && (tab[2][2] == 1) ||
                (tab[0][0] == 1) && (tab[1][0] == 1) && (tab[2][0] == 1) ||
                (tab[0][2] == 1) && (tab[1][1] == 1) && (tab[2][0] == 1) ||
                (tab[0][0] == 1) && (tab[1][1] == 1) && (tab[2][2] == 1) ||
                (tab[0][2] == 1) && (tab[1][2] == 1) && (tab[2][2] == 1) ||
                (tab[0][1] == 1) && (tab[1][1] == 1) && (tab[2][1] == 1))  win = true;

            else if ((tab[0][0] == 2) && (tab[0][1] == 2) && (tab[0][2] == 2) ||
                (tab[1][0] == 2) && (tab[1][1] == 2) && (tab[1][2] == 2) ||
                (tab[2][0] == 2) && (tab[2][1] == 2) && (tab[2][2] == 2) ||
                (tab[0][0] == 2) && (tab[1][0] == 2) && (tab[2][0] == 2) ||
                (tab[0][2] == 2) && (tab[1][1] == 2) && (tab[2][0] == 2) ||
                (tab[0][0] == 2) && (tab[1][1] == 2) && (tab[2][2] == 2) ||
                (tab[0][2] == 2) && (tab[1][2] == 2) && (tab[2][2] == 2) ||
                (tab[0][1] == 2) && (tab[1][1] == 2) && (tab[2][1] == 2))  win = true;
        }
    }
    return win;
}
