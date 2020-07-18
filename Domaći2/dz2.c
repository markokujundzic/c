#include <stdio.h>
#define BR 100

int main()
{
	while (1)
	{
		int m, n, i, j, min, k;
		char niz[BR][BR];

		printf("Unesite dimenzije ukrstenice: ");
		scanf("%d", &m);
		scanf("%d", &n);
		if (m < 1 || m > BR || n < 1 || n > BR)
		{
			printf("Uneli ste losu vrednost, pokusajte ponovo! \n");
			continue;
		}

		char p;
		scanf("%c", &p);

		printf("Unesite karaktere:\n");
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
			{
				scanf(" %c", &niz[i][j]);
				if ((niz[i][j] >= 97 && niz[i][j] <= 122) || (niz[i][j] >= 65 && niz[i][j] <= 90) || (niz[i][j] == 42))
					continue;
				else
				{
					printf("Uneli ste nedozvoljeni znak!\n");
					exit(1);
				}
			}

		printf("\n");
		printf("\n");

		printf("Ukrstenica izgleda ovako:\n");
		for (i = 0; i < m; printf("\n"), i++)
			for (j = 0; j < n; j++) printf("%c ", niz[i][j]);
		printf("\n");

		int x, y;
		int s = 0;
		for (i = 0, min = n; i < m; i++)
		{
			for (j = 0, k = 0; j < n; j++)
			{
				if (niz[i][j] != '*')
				{
					k++;
					s = 1;
				}
				else
				{
					if (k >= 1 && k < min)
					{
						min = k;
						k = 0;
					}
				}

			}
			if (k >= 1 && k < min)
			{
				min = k;
			}
			k = 0;
		}

		if (s != 0)
		{
			printf("Minimalna duzina reci je: %d \n", min);
			for (i = 0; i < m; i++, k = 0)
			{
				for (j = 0, k = 0; j < n; j++)
				{
					if (niz[i][j] != '*')
					{
						k++;
						if (k == 1)
						{
							x = i;
							y = j;
						}
						s = 1;
					}
					else
					{
						if (k == min)
						{
							printf("Koordinate pocetka minimalnih reci su: [%d][%d] \n ", x, y);
						}
						k = 0;
					}
				}
				if (k == min)
				{
					printf("Koordinate pocetka minimalnih reci su: [%d][%d] \n ", x, y);
				}
			}
		}
		else printf("Nema slova \n");
	}
}
