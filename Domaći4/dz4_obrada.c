#include "dz4.h"
#include<stdlib.h>
#include <string.h>

void sortiraj(Putnik* p)
{
	Putnik *tek1;
	Putnik *tek2;
	char ime[50], op, klasa;

	for (tek1 = p; tek1->sledeci; tek1 = tek1->sledeci)
	{
		for (tek2 = tek1->sledeci; tek2; tek2 = tek2->sledeci)
		{
			if (tek1->klasa == tek2->klasa)
			{
				if (tek1->op == 'R' && tek2->op != 'R')
				{
					strcpy(ime, tek1->ime);
					strcpy(tek1->ime, tek2->ime);
					strcpy(tek2->ime, ime);
					op = tek1->op;
					tek1->op = tek2->op;
					tek2->op = op;
					klasa = tek1->klasa;
					tek1->klasa = tek2->klasa;
					tek2->klasa = klasa;
				}
			}
			else
			{
				if (tek2->klasa == 'B')
				{
					strcpy(ime, tek1->ime);
					strcpy(tek1->ime, tek2->ime);
					strcpy(tek2->ime, ime);
					op = tek1->op;
					tek1->op = tek2->op;
					tek2->op = op;
					klasa = tek1->klasa;
					tek1->klasa = tek2->klasa;
					tek2->klasa = klasa;
				}
			}
		}
	}
}

void brisi(Putnik *p)
{
	while (p)
	{
		Putnik *stari = p;
		p = p->sledeci;
		free(stari);
	}
}

Putnik *izbaci(char ime[50], char klasa, char op, Putnik *p)
{
	Putnik *tek = p, *pre = NULL;
	while (tek)
		if ((strcmp(tek->ime, ime) == 0) && (tek->klasa == klasa) && (tek->op == op))
		{
			Putnik *stari = tek;
			tek = tek->sledeci;
			if (!pre) p = tek;
			else
				pre->sledeci = tek;
			free(stari);
		}
		else
		{
			pre = tek;
			tek = tek->sledeci;
		}
	return p;
}

void obrada(Putnik* p, int e, int b)
{
	Putnik *tek = p;
	int red_b = 1;
	char sed_b = 'A';
	int red_e = 1;
	char sed_e = 'A';
	sortiraj(tek);
	while (tek)
	{
		if ((tek->klasa == 'B') && (b > 0))
		{//ukrcavanje u biznis
			tek->brreda = red_b;
			tek->brsedista = sed_b;
			if (tek->brsedista == 'F')
			{
				red_b++;
				sed_b = 'A';
			}
			else sed_b++;
			b--;
			tek = tek->sledeci;
		}
		if (tek == NULL)
			break;
		if ((b <= 0) && (tek->klasa == 'B') && e > 0)
		{//ukrcavanje ljudi iz biznis u ekonomsku ako u biznis nema mesta
			tek->klasa == 'E';
			tek->brreda = red_e;
			tek->brsedista = sed_e;
			if (tek->brsedista == 'F')
			{
				red_e++;
				sed_e = 'A';
			}
			e--;
			tek = tek->sledeci;
		}
		if (tek == NULL)
			break;
		if ((tek->klasa == 'E') && (e > 0))
		{//ukrcavanje ljudi u ekonomsku klasu
			tek->brreda = red_e;
			tek->brsedista = sed_e;
			if (tek->brsedista == 'F')
			{
				red_e++;
				sed_e = 'A';
			}
			else sed_e++;
			e--;
			tek = tek->sledeci;
		}
		if (tek == NULL)
			break;
		if ((tek->klasa == 'E') && (e <= 0) && (b > 0))
		{//ako nema vise mesta u ekonomskoj klasi a ostalo je mesta u biznis klasi, ukrcaj ljude iz ekonomske u biznis
			tek->klasa == 'B';
			tek->brreda = red_b;
			tek->brsedista = sed_b;
			if (tek->brsedista == 'F')
			{
				red_b++;
				sed_b = 'A';
			}
			else sed_b++;
			b--;
			tek = tek->sledeci;
		}
		if (tek == NULL)
			break;
		if (e <= 0 && b <= 0)
		{//ako uopste nema vise mesta u avionu dodeljujemo XX ostalim putnicima
			tek->brreda = -1;
			tek->brsedista = 'X';
			tek = tek->sledeci;
			if (tek == NULL)
				break;
		}
	}
	return;
}

void novaobrada(Putnik *p, int n)
{
	Putnik *tek = p;
	Putnik *novi = malloc(sizeof(Putnik));
	printf("Unesite redom ime, klasu i oznaku prioriteta za novi element \n");
	scanf("%s", novi->ime);
	scanf(" %c", &novi->klasa);
	scanf(" %c", &novi->op);
	int i = 0;
	if (novi == NULL)
	{
		printf("\n Neuspesna alokacija!\n");
		exit(-1);
	}
	for (i = 0; i <= (n - 2); i++)
	{
		tek = tek->sledeci;
		if (tek == NULL)
			return;
	}

	novi->sledeci = tek->sledeci;
	tek->sledeci = novi;


	return;
}