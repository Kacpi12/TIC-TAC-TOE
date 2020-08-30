#pragma once
#ifndef _PROTOTYPY_
#define _PROTOTYPY_


// prototypy funkcje
//------------------------------------

template<typename T>
void zainicjalizuj(T tab[][3]);

template<typename T>
void wyswietl(T tab[][3]);

template<typename T>
void PodajXY(T& x, T& y);

template<typename T>
void zmien(T x, T y, T tab[][3], T);

template<typename T>
auto wygrana(T tab[][3]) ->bool;

template<typename T>
auto Remis(T tab[][3]) ->bool;


#include"PodajPole.cpp"
#include"Wygrana.cpp"
#include"Remis.cpp"

#endif
