#include <iostream>
#include <fstream>
#include <cstdlib>

template<typename T>
auto Remis(T tab[][3])->bool {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tab[i][j] == 0)	return false;
		}
	}

	return true;
}