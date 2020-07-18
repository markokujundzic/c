#include "dz4.h"
#include<stdlib.h>
#include <string.h>

Putnik *ucitaj1(char ime[50], char klasa, char op, Putnik *p) {
	
		Putnik *novi = malloc(sizeof(Putnik));
		if (novi == NULL) {
			printf("\n Neuspesna alokacija!\n");
			exit(-1);
		}
		strcpy(novi->ime, ime);
		novi->klasa = klasa;
		novi->op = op;
		novi->sledeci = p;
		p = novi;
		return p;
	}

Putnik *ucitaj2(Putnik *p) {

		Putnik *novi = malloc(sizeof(Putnik));
		printf("Unesite redom ime, klasu i oznaku prioriteta \n");
		scanf("%s", novi->ime);
		scanf(" %c", &novi->klasa);
		scanf(" %c", &novi->op);
		
		if (((novi->klasa == 'B') || (novi->klasa == 'E')) && ((novi->op == 'R') || (novi->op == 'I') || (novi->op == 'P') || (novi->op == 'F') || (novi->op == 'S')))
		{
			novi->sledeci = NULL;
			if (!p) return novi;
			else
			{
				Putnik *tek = p;
				while (tek->sledeci)
					tek = tek->sledeci;
				tek->sledeci = novi;
				return p;
			}
		}
		else {
			printf("Uneli ste nedozvoljene karaktere! \n");
			exit(1);
		}	
}

int ucitavanje(Putnik **glava, int n) {
	int i;
	Putnik *novi, *x;
	for (i = 0; i < n; i++) {
		novi = malloc(sizeof(Putnik));
		printf("Unesite redom ime, klasu i oznaku prioriteta \n");
		scanf("%s", novi->ime);
		scanf(" %c", &novi->klasa);
		scanf(" %c", &novi->op);
		if (((novi->klasa == 'B') || (novi->klasa == 'E')) && ((novi->op == 'R') || (novi->op == 'I') || (novi->op == 'P') || (novi->op == 'F') || (novi->op == 'S')))
		{

			novi->sledeci = NULL;
			if (*glava != NULL) {
				x->sledeci = novi;
			}
			if (*glava == NULL) {
				*glava = novi;
				novi = (*glava)->sledeci;
				x = *glava;
			}
			else
			{
				x = novi;
				novi = novi->sledeci;
			}
		}

		else {
			printf("Uneli ste nedozvoljene karaktere! \n");
			exit(1);
		}
	}
}
int duzina(Putnik *p) {
	int n = 0;
	while (p){
		n++;
		p = p->sledeci;
	}
	return n;
}


