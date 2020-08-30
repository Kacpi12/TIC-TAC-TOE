#include <iostream>
#include <fstream>
#include <cstdlib>

template<typename T>
void PodajXY(T& x, T& y) {
    std::cout << "Podaj wspolrzedne pion: ";
    while ((std::cin >> x) && (x > 2));

    std::cout << std::endl;
    std::cout << "Podaj wspolrzedne poziom: ";
    while ((std::cin >> y) && (y > 2));
}