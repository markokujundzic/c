#include "dz4.h"
#include<stdlib.h>
#include <string.h>
void ispis(Putnik *p)
{
	if (p == NULL)
		printf("Lista je prazna \n");

	while (p)
	{
		puts(p->ime);
		putchar(p->klasa);
		printf("\n");
		putchar(p->op);
		printf("\n");
		if (p->brreda == -1)
			putchar('X');
		else
			printf("%d", p->brreda);
		printf("\n");
		putchar(p->brsedista);
		printf("\n");
		p = p->sledeci;
	}

}