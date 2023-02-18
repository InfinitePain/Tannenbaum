#ifndef CURSOR_H_
#define CURSOR_H_
#include <stdio.h>

 //Positioniere Cursor an Position x, y
void cursor_bewegen(int x, int y)
{
	printf("\33[%d;%dH", y, x);	//Kommandos	\033[<L>; <C>H oder \033[<L>; <C>f
}

//Gebe Zeichen c an Position x, y aus.
void cursor_zeichne_punkt(int x, int y, char c)
{
	cursor_bewegen(x, y);
	printf("%c", c);
}

//Setze Schriftfarbe oder Hintergrundfarbe
void cursor_setze_farbe(const char* farbe)
{
	printf("%s", farbe);
}

#endif /* CURSOR_H_ */ 
