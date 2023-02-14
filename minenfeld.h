#ifndef MINENFELD_H_
#define MINENFELD_H_

#include "spielfeld.h"

#define X_GROESSE 20
#define Y_GROESSE 12
struct minenfeld
{
	struct spielfeld* gefahrengebiet[Y_GROESSE][X_GROESSE];
	int anzahlMinen;
};
typedef struct minenfeld minenfeld;

void initMinenfeld(minenfeld* pMinenfeld) {
	for (int i = 0; i < Y_GROESSE; i++) {
		for (int j = 0; j < X_GROESSE; j++) {
			
			if (i == 0 || i == Y_GROESSE - 1 || j == 0 || j == X_GROESSE - 1) {
				pMinenfeld->gefahrengebiet[i][j] = neuesSpielfeld(i, j, SYMBOL_GRENZE);
			}
			else {
				pMinenfeld->gefahrengebiet[i][j] = neuesSpielfeld(i, j, SYMBOL_WIESE);
			}
		}
	}
}
void ausgabeMinenfeld(minenfeld* pMinenfeld) {
	for (int i = 0; i < Y_GROESSE; i++) {
		for (int j = 0; j < X_GROESSE; j++) {
			ausgabeSpielfeld(pMinenfeld->gefahrengebiet[i][j]);
		}
		printf("\n");
	}
}
int myRand(int max) {
	int zfz = (rand() % (max - 3)) + 1;
	return zfz;
}
void platziereMinen(minenfeld* pMinenfeld, int anzahlMinen, int seed) {
	srand(seed);

	for (int i = 0; i < anzahlMinen; i++) {
		int posx = myRand(X_GROESSE);
		int posy = myRand(Y_GROESSE);
		pMinenfeld->gefahrengebiet[posy][posx]->typ = SYMBOL_MINE;
	}
}
void pruefeNachbarn(minenfeld* pMinenfeld, spielfeld* pSpielfeld) {
	if (pSpielfeld->typ == SYMBOL_WIESE) {
		int azm = 0;
		
		int y = pSpielfeld->y_koordinate - 1;
		for (y; y <= pSpielfeld->y_koordinate + 1; y++) {
			int x = pSpielfeld->x_koordinate - 1;
			for (x; x <= pSpielfeld->x_koordinate + 1; x++) {
				if (pMinenfeld->gefahrengebiet[y][x]->typ == SYMBOL_MINE) {
					azm++;
				}
			}
		}
		if (azm > 0) {
			pSpielfeld->typ = azm;
		}
	}

}
void berechneGefahrengebiet(minenfeld* pMinenfeld) {
	for (int i = 0; i < Y_GROESSE; i++) {
		for (int j = 0; j < X_GROESSE; j++) {
			pruefeNachbarn(pMinenfeld, pMinenfeld->gefahrengebiet[i][j]);
		}
	}
}
minenfeld* neuesMinenfeld(int anzahlMinen, int seed) {
	minenfeld* mf = (minenfeld*)malloc(sizeof(minenfeld));
	initMinenfeld(mf);
	platziereMinen(mf, anzahlMinen, seed);
	berechneGefahrengebiet(mf);
	return mf;
}

#endif // MINENFELD_H_

