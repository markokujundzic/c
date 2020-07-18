#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dz5.h"

Elem *ucitavanje(FILE* ul, Elem* prvi)
{
	Elem *posl, *novi;
	int karakter;
	while ((karakter = fgetc(ul)) != EOF)
	{
		novi = malloc(sizeof(Elem));
		if (novi == NULL)
		{
			printf("Neuspela alokacija memorije!");
			exit(3);
		}
		novi->p = malloc(sizeof(pod));
		if (novi->p == NULL)
		{
			printf("Neuspela alokacija memorije!");
			exit(4);
		}
		novi->pret = NULL;
		novi->sled = NULL;
		novi->p->c = karakter;
		if (prvi == NULL)
			prvi = posl = novi;
		else
		{
			posl->sled = novi;
			novi->pret = posl;
			posl = posl->sled;
		}
	}
	return prvi;
}




