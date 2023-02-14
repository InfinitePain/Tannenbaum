#include "spielfeld.h"
#include "minenfeld.h"

int main(void)
{
	minenfeld* pMF = neuesMinenfeld(10, 5);
	ausgabeMinenfeld(pMF);
	getchar();
	return EXIT_SUCCESS;
}