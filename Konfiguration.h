#ifndef KONFIGURATION_H_
#define KONFIGURATION_H_

#define MAX_AUSDEHNUNG  60

#define OFFSET			5

#define SYMBOL_NADEL 	'#'
#define SYMBOL_STAMM 	'|'
#define SYMBOL_KUGEL	'O'
#define SYMBOL_LEER		' '

 //FARBEN
#define ROT 		0
#define BLAU		1
#define HELL_GRUEN 	2
#define MAGENTA		3
#define GELB		4
#define GRUEN 		5
#define BRAUN		6
#define ZUFALL		rand()%5

const char* farben[7] = { "\033[1;31m", "\033[1;34m", "\033[1;32m", "\033[1;35m", "\033[1;33m", "\033[0;32m", "\033[0;33m" };

#endif /* KONFIGURATION_H_ */
