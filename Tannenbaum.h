#ifndef TANNENBAUM_H_
#define TANNENBAUM_H_

#include <string.h>
#include <stdlib.h>
#include "Konfiguration.h"
#include "Cursor.h"

struct Tannenbaum
{
    char bild[MAX_AUSDEHNUNG][MAX_AUSDEHNUNG];
    int breite;
    int hoehe;
};

typedef struct Tannenbaum Tannenbaum;

Tannenbaum* Tannenbaum_erzeugen(int breite, int hoehe)
{
    Tannenbaum* pTannenbaum = (Tannenbaum*)malloc(sizeof(Tannenbaum));
    if (pTannenbaum == NULL) {
        return NULL;
    }
    if (breite <= MAX_AUSDEHNUNG - 1) {
        pTannenbaum->breite = breite;
    }
    if (hoehe <= MAX_AUSDEHNUNG - 1) {
        pTannenbaum->hoehe = hoehe;
    }
    return pTannenbaum;
}

void Tannenbaum_init(Tannenbaum* t_ptr)
{
    //complet mit nadel f�llen
    for (int breite = 0; breite <= t_ptr->breite; breite++) {
        for (int hoehe = 0; hoehe <= t_ptr->hoehe; hoehe++) {
            t_ptr->bild[breite][hoehe] = SYMBOL_NADEL;
        }
    }
    //unten f�r stamm leeren
    for (int breite = 0; breite <= t_ptr->breite; breite++) {
        for (int hoehe = t_ptr->hoehe - 1; hoehe <= t_ptr->hoehe; hoehe++) {
            t_ptr->bild[breite][hoehe] = ' ';
        }
    }
    //stamm einsetzen
    for (int breite = 0; breite <= t_ptr->breite; breite++) {
        for (int hoehe = t_ptr->hoehe - 1; hoehe <= t_ptr->hoehe; hoehe++) {
            if (breite >= t_ptr->breite / 2 - 1 && breite <= t_ptr->breite / 2 + 1) {
                t_ptr->bild[breite][hoehe] = SYMBOL_STAMM;
            }
        }
    }
    //linkste teil leeren
    for (int breite = 0; breite < t_ptr->breite/2; breite++) {
        for (int hoehe = 0; hoehe < t_ptr->hoehe-1; hoehe++) {
            if (breite <= t_ptr->hoehe-hoehe) {
                t_ptr->bild[breite][hoehe] = ' ';
            }
        }
    }
    //rechste teil leeren
    for (int breite = t_ptr->breite / 2 ; breite <= t_ptr->breite; breite++) {
        for (int hoehe = 0; hoehe < t_ptr->hoehe - 1; hoehe++) {
            if (breite - (t_ptr->breite / 2) >= hoehe) {
                t_ptr->bild[breite][hoehe] = ' ';
            }
        }
    }
}

void Tannenbaum_schmuecken(Tannenbaum* t_ptr, int prozent)
{
    for (int breite = 0; breite <= t_ptr->breite; breite++) {
        for (int hoehe = 0; hoehe <= t_ptr->hoehe; hoehe++) {
            char c = t_ptr->bild[breite][hoehe];
            if (c == SYMBOL_NADEL) {
                int bool = rand() % 5;
                if (bool == 0) {
                    t_ptr->bild[breite][hoehe] = SYMBOL_KUGEL;
                }
            }
           
        }
    }
}

void Tannenbaum_ausgabe(Tannenbaum* t_ptr)
{
    for (int breite = 0; breite <= t_ptr->breite; breite++) {
        for (int hoehe = 0; hoehe <= t_ptr->hoehe; hoehe++) {
            char c = t_ptr->bild[breite][hoehe];
            if (c == SYMBOL_NADEL) {
                cursor_setze_farbe(farben[GRUEN]);
                cursor_zeichne_punkt(breite + OFFSET, hoehe + OFFSET, c);
            } else if (c == SYMBOL_STAMM) {
                cursor_setze_farbe(farben[BRAUN]);
                cursor_zeichne_punkt(breite + OFFSET, hoehe + OFFSET, c);
            } else if (c == SYMBOL_KUGEL) {
                cursor_setze_farbe(farben[ZUFALL]);
                cursor_zeichne_punkt(breite + OFFSET, hoehe + OFFSET, c);
            }
        }
    }
}

#endif