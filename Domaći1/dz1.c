#include <stdio.h>
#include <math.h>
#define MAX_BR_EL 100

void main() {

	int a[MAX_BR_EL];
	int i, n, q;
	int j = 0;
	int c = 0;
	int b = 0;
	int d = 0;
	int x;

	while (1) {

		printf("Unesite broj elemenata u nizu: \n");
		scanf("%d", &n);
		if (n < 0 || n > MAX_BR_EL) {

			printf("Uneli ste pogresnu vrednost! \n");
			break;
		}


		printf("Unesite elemente niza koje zelite: \n");
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);

		

		printf("Unesite brojnu osnovu q: \n");
		scanf("%d", &q);

		if (q > 9 || q < 0) {

			printf("Uneli ste nedozvoljenu vrednost za brojni sistem! \n");
			break;
		}

		for (i = 0; i < n; i++)
		{
			j = 0;
			d = 0;
			while (a[i] != 0) {

				b = a[i] % 10;
				c = pow(q, j) * b;
				a[i] = a[i] / 10;
				d = d + c;
				j++;
			}

			a[i] = d;

		}

		printf("Izgled niza u dekadnom sistemu pre uklanjanja neparnih brojeva :\n");
		for (i = 0; i < n; i++) {
			printf("%d ", a[i]);
			printf("\n");

		}

		for (i = 0; i < n; i++)
		{
			if (a[i] % 2 == 1)
			{
				for (x = i; x < n; x++)
				{
					a[x] = a[x + 1];
				}
				n--;
				i--;
			}

		}

		if (n == 0)
			printf("Niz je prazan: \n");

		printf("Izgled konacnog niza je: \n");
		for (i = 0; i < n; i++) {
			printf("%d ", a[i]);
			printf("\n");



		}

	}

}