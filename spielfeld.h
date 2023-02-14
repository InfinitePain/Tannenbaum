#ifndef SPIELFELD_H_
#define SPIELFELD_H_

#include <stdio.h>
#include <stdlib.h>

#define TYP_MINE 10
#define TYP_WIESE 20
#define TYP_GRENZE 30
#define SYMBOL_MINE '*'
#define SYMBOL_WIESE ' '
#define SYMBOL_GRENZE '#'
struct spielfeld
{
	int x_koordinate;
	int y_koordinate;
	char typ;
};
typedef struct spielfeld spielfeld;

spielfeld* neuesSpielfeld(int y_koordinate, int x_koordinate, char typ) {
	spielfeld* sf = (spielfeld*)malloc(sizeof(spielfeld));
	sf->y_koordinate = y_koordinate;
	sf->x_koordinate = x_koordinate;
	sf->typ = typ;
	return sf;
}
void ausgabeSpielfeld(spielfeld* pSpielfeld) {
	if (pSpielfeld->typ == SYMBOL_MINE || pSpielfeld->typ == SYMBOL_WIESE || pSpielfeld->typ == SYMBOL_GRENZE
		|| pSpielfeld->typ == TYP_GRENZE || pSpielfeld->typ == TYP_WIESE || pSpielfeld->typ == TYP_MINE) {
		printf("%c", pSpielfeld->typ);
	}
	else {
		printf("%i", (int)pSpielfeld->typ);
	}
}

#endif // SPIELFELD_H_