#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dz5.h"

void main(int argc, const char *argv[]) {
	char ulaz[50], izlaz[50];
	Elem *glava = NULL;
#ifdef CMD_LINE
	strcpy(ulaz, argv[1]);
	strcpy(izlaz, argv[2]);
#else
	printf("Unesite imena datoteka: \n");
	scanf("%s", ulaz);
	getchar();
	scanf("%s", izlaz);
	getchar();
#endif

	int x;
	int y = 1;
	FILE *ul, *iz;
	ul = fopen(ulaz, "r");
	if (ul == NULL) {
		printf("Greska \n");
		exit(1);
	}
	iz = fopen(izlaz, "w");
	if (iz == NULL) {
		printf("Greska \n");
		exit(2);
	}
	while (y) {
		printf("Koju stvar zelite da uradite? \n"
			"1. Ucitaj datoteku u listu \n"
			"2. Obradi listu i ispisi je u datoteku \n"
			"3. Obrisi listu \n"
			"4. Ispisi listu \n"
			"5. Napusti program \n"
			"Koji je vas izbor? \n"
		);
		scanf("%d", &x);
		switch (x) {
		case 1:glava = ucitavanje(ul, glava);
			break;
		case 2:obrada(iz, glava);
			break;
		case 3:obrisi(glava);
			break;
		case 4:ispis(glava);
			break;
		case 5:printf("Dovidjenja! \n");
			y = 0;
			break;
		}
	}
	fclose(ul);
	fclose(iz);
	return 0;
}