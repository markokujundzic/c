#include <stdio.h>
#include "dz4.h"
#include <stdlib.h>
#include <string.h>
int main()
{
	Putnik *glava = NULL;
	int izbor;
	char ime[50];
	char klasa, op;
	int n, x, kraj = 1;
	int k;
	int e, b;
	while (kraj)
	{
		printf(
			"\n1. Ucitavanje elemenata na pocetak \n"
			"2. Ucitavanje elemenata na kraj \n"
			"3. Izbacivanje elementa iz liste \n"
			"4. Ispisivanje liste \n"
			"5. Obrada liste \n"
			"6. Prekid programa \n"
			"7. Brisanje liste \n"
			"8. Ucitavanje cele liste \n"
			"9. Broj elemenata liste \n"
			"10. Sortiraj listu \n"
			"11. Modifikacija \n"
			"Koji je vas izbor? \n"
		);
		scanf("%d", &izbor);

		switch (izbor)
		{
			case 1: printf("Unesite redom ime, klasu i oznaku prioriteta \n");
				scanf("%s", ime);
				getchar();
				klasa = getchar();
				getchar();
				op = getchar();
				if (((klasa == 'B') || (klasa == 'E')) && ((op == 'R') || (op == 'I') || (op == 'P') || (op == 'F') || (op == 'S')))
					glava = ucitaj1(ime, klasa, op, glava);
				else
				{
					printf("Uneli ste nedozvoljene karaktere! \n");
					exit(1);
				}
				break;
			case 2: glava = ucitaj2(glava);
				break;
			case 3: printf("Unesite redom ime, klasu i oznaku prioriteta \n");
				scanf("%s", ime);
				getchar();
				klasa = getchar();
				getchar();
				op = getchar();
				if (((klasa == 'B') || (klasa == 'E')) && ((op == 'R') || (op == 'I') || (op == 'P') || (op == 'F') || (op == 'S')))
					glava = izbaci(ime, klasa, op, glava);
				else
				{
					printf("Uneli ste nedozvoljene karaktere! \n");
					exit(1);
				}
				break;
			case 4:ispis(glava);
				break;
			case 5:
				printf("Broj mesta za ekonomsku klasu i biznis klasu?\n");
				scanf("%d", &e);
				scanf("%d", &b);
				getchar();
				obrada(glava, e, b);
				break;
			case 6:printf("Izabrali ste da izadjete iz programa \n");
				kraj = 0;
				break;
			case 7: brisi(glava);
				break;
			case 8:printf("Unesite broj elemenata \n");
				scanf("%d", &n);
				ucitavanje(&glava, n);
				break;
			case 9:x = duzina(glava);
				printf("Broj elemenata je %d \n", x);
				break;
			case 10:sortiraj(glava);
				break;
			case 11:printf("Unesite mesto na koje zelite da ubacite novi element \n");
				scanf("%d", &k);
				novaobrada(glava, k);
				break;
		}
	}
	return 0;
}