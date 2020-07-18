#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dz5.h"

void upis(Elem *prvi, FILE *iz)
{
	Elem *tek;
	tek = prvi;
	switch (tek->p->c)
	{
		case 'A': fputs(".- ", iz); break;
		case 'B': fputs("-... ", iz); break;
		case 'C': fputs("-.-. ", iz); break;
		case 'D': fputs("-.. ", iz); break;
		case 'E': fputs(". ", iz); break;
		case 'F': fputs("..-. ", iz); break;
		case 'G': fputs("--. ", iz); break;
		case 'H': fputs(".... ", iz); break;
		case 'I': fputs(".. ", iz); break;
		case 'J': fputs(".--- ", iz); break;
		case 'K': fputs("-.- ", iz); break;
		case 'L': fputs(".-.. ", iz); break;
		case 'M': fputs("-- ", iz); break;
		case 'N': fputs("-. ", iz); break;
		case 'O': fputs("--- ", iz); break;
		case 'P': fputs(".--. ", iz); break;
		case 'Q': fputs("--.- ", iz); break;
		case 'R': fputs(".-. ", iz); break;
		case 'S': fputs("... ", iz); break;
		case 'T': fputs("- ", iz); break;
		case 'U': fputs("..- ", iz); break;
		case 'V': fputs("...- ", iz); break;
		case 'W': fputs(".-- ", iz); break;
		case 'X': fputs("-..- ", iz); break;
		case 'Y': fputs("-.-- ", iz); break;
		case 'Z': fputs("--.. ", iz); break;
		case '0': fputs("----- ", iz); break;
		case '1': fputs(".---- ", iz); break;
		case '2': fputs("..--- ", iz); break;
		case '3': fputs("...-- ", iz); break;
		case '4': fputs("....- ", iz); break;
		case '5': fputs("..... ", iz); break;
		case '6': fputs("-.... ", iz); break;
		case '7': fputs("--... ", iz); break;
		case '8': fputs("---.. ", iz); break;
		case '9': fputs("----. ", iz); break;
		case '.': fputs(".-.-.- ", iz); break;
		case ',': fputs("--..-- ", iz); break;
		case '?': fputs("..--.. ", iz); break;
		case '!': fputs("-.-.-- ", iz); break;
		case '/': fputs("-..-. ", iz); break;
		case '(': fputs("-.--. ", iz); break;
		case ')': fputs("-.--.- ", iz); break;
		case '&': fputs("-.-... ", iz); break;
		case ':': fputs("---... ", iz); break;
		case ';': fputs("-.-.-. ", iz); break;
		case '-': fputs("-....- ", iz); break;
		case '"': fputs(".-..-. ", iz); break;
		case '=': fputs("-...- ", iz); break;
		case '+': fputs(".-.-. ", iz); break;
		case '_': fputs("..--.- ", iz); break;
		case '@': fputs(".--.-. ", iz); break;
		case '$': fputs("...-..- ", iz); break;
		case ' ': fputc(' ', iz); break;
		case '\n': fputc('\n', iz); break;
		case '\'': fputs(".----. ", iz); break;
	}
	return;
}

void obrisi(Elem *prvi)
{
	Elem *tek;
	while (prvi)
	{
		tek = prvi;
		prvi = prvi->sled;
		free(tek);
	}
	if (prvi == NULL)
		printf("Lista je obrisana! \n");
	return;
}
