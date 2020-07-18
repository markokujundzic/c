#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dz5.h"

void obrada(FILE *iz, Elem *prvi) {
	Elem *tek;
	for (tek = prvi; tek; tek = tek->sled) {
		upis(tek, iz);
	}
	return;
}

void ispis(Elem *prvi) {
	if (prvi == NULL)
		printf("Prazna lista \n");
	while (prvi) {
		putchar(prvi->p->c);
		printf("\n");
		prvi = prvi->sled;
	}
	return;
}