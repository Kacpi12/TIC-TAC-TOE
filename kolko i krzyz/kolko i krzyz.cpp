// biblioteki
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Prototypy.h"


int minimax(int Plansza[][3],int gracz);
int komputer(int Plansza[][3], int& x, int& y);

// zmienne globalne
//-----------------------------------------
int Plansza[3][3];
int minimaxY; int minimaxX;

// main
//--------------------------------------------
int main()
{
    int PION, POZIOM; bool WYGRANA = false; int wartosc = 0;
    zainicjalizuj(Plansza);
    wyswietl(Plansza);
   
    while (!wygrana(Plansza))
    {
        if (Remis(Plansza)) {
            system("cls");
            std::cout << "Remis dziekuje";
            exit(EXIT_FAILURE);
        }
        
        if (wartosc % 2 == 0) {
            PodajXY(PION, POZIOM);
            zmien(PION, POZIOM, Plansza, 1);
        } 
        if (wartosc % 2 == 1) {   
            komputer(Plansza, minimaxX, minimaxY);
            if (Plansza[minimaxX][minimaxY] == 0) {
                zmien(minimaxX, minimaxY, Plansza, 2);
            }
        }
            
        system("cls");
        wyswietl(Plansza);
        wartosc++;
    } 
    if (wartosc % 2 == 0) std::cout << std::endl <<" gracz 'o' wygral GRATULACJE";
    if (wartosc % 2 == 1) std::cout << std::endl << " gracz 'x' wygral GRATULACJE";

}

// funkcje
//------------------------------------------------------

template<typename T> void zainicjalizuj(T tab[][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tab[i][j] = 0;
        }
    }
}

template<typename T>
void wyswietl(T tab[][3]) {
    for (int i = 0; i < 3; i++) {
        std::cout << i << " ";
        for (int j = 0; j < 3; j++){
            if (tab[i][j] == 0)      std::cout << " ";
            else if (tab[i][j] == 1) std::cout << "x";
            else if (tab[i][j] == 2) std::cout << "o";

            if(j != 2) std::cout << "|";
        }
        std::cout << std::endl;
        std::cout << "  ";
        if(i!=2)  for (int k = 0; k < 5; k++) std::cout  << "-";
        std::cout << std::endl;
    }
    std::cout << "  ";
    for (int z = 0; z < 3; z++) std::cout << z << " ";
    std::cout << std::endl;
    std::cout << std::endl;
}

template<typename T>
void zmien(T x, T y, T tab[][3], T ruch) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if      (ruch == 1)    tab[x][y] = 1;
            else if (ruch == 2)    tab[x][y] = 2;
        }
    }
}



int komputer(int tab[][3], int& x,int& y) {
    int ruch = 0, i,j, m, mmx;
    mmx = -10;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (tab[i][j] == 0)    {
                tab[i][j] = 2;
                m = minimax(tab, 2);
                tab[i][j] = 0;
                if (m > mmx) {
                    mmx = m; x = i; y = j;
                }

            }
        }
    }


    return ruch;

}



int minimax(int tab[][3], int gracz) {
    // 1 = x
    // 2 = o
    int m, mmx;

    if (wygrana(tab)) return (gracz == 2) ? 1 : -1;
    if (Remis(tab)) return 0;



    gracz = (gracz == 2) ? 1 : 2;
    mmx = (gracz == 1) ? 10 : -10;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tab[i][j] == 0) {
                tab[i][j] = gracz;
                m = minimax(tab, gracz);
                tab[i][j] = 0;
                if (((gracz == 1) && (m < mmx)) || ((gracz == 2) && (m > mmx))) mmx = m;
            }    
        }
    }
    return mmx;


}

