#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Tannenbaum.h"
#include "Konfiguration.h"

int main(void) {
    srand(time(NULL));
    puts("Oh Tannenbaum, oh Tannenbaum!\n");

    Tannenbaum* t_ptr = Tannenbaum_erzeugen(28, 14);
    Tannenbaum_init(t_ptr);
    Tannenbaum_ausgabe(t_ptr);
    Tannenbaum_schmuecken(t_ptr, 10);
    getchar();
    Tannenbaum_ausgabe(t_ptr);
    getchar();

    return EXIT_SUCCESS;
}
