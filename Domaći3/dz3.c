#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *unesi()
{
	char *string, slovo;
	int broj = 0;
	string = calloc(1, sizeof(char));
	if (string == NULL)
	{
		printf("Nije uspela dodela memorije!\n");
		exit(3);
	}
	string[0] = '\0';
	broj = 0;

	for (slovo = getchar(); slovo != '\n'; slovo = getchar())
	{
		char *pom;
		pom = realloc(string, sizeof(char) * (broj + 1 + 1));
		if (pom == NULL)
		{
			printf("Nije uspela dodela memorije!\n");
			exit(3);
		}
		string = pom;
		string[broj + 1] = '\0';
		string[broj] = slovo;
		broj++;
	}

	return string;
}

char *ubaciDveTacke(char *str)
{
	char *pom = str;
	int i;

	while (*pom && *pom != '=') pom++;
	if (*pom == '\0') return str;
	for (i = strlen(str); i >= pom - str; i--) str[i + 1] = str[i];

	*pom = ':';
	return str;
}

char *obradiString(char *string)
{
	char *kopija = NULL;
	char *izraz = NULL;
	char *uslov = NULL;
	char *postIzraz = NULL;
	char *poc, *kraj;
	char *p, *k;

	poc = string;
	while (*poc && *poc != '(') poc++;
	poc++;

	while (*poc && *poc == ' ') poc++;
	kraj = poc;

	while (*kraj != ' ' && *kraj != ';') kraj++;

	izraz = calloc((kraj - poc + 1 + 1), sizeof(char));
	if (izraz == NULL)
	{
		printf("Nije uspela dodela memorije!\n");
		exit(3);
	}
	strncpy(izraz, poc, kraj - poc);

	while (*kraj != ';') kraj++;
	poc = kraj + 1;

	while (*poc && *poc == ' ') poc++;
	kraj = poc;

	while (*kraj != ' ' && *kraj != ';') kraj++;

	uslov = calloc((kraj - poc + 1), sizeof(char));
	if (uslov == NULL)
	{
		printf("Nije uspela dodela memorije!\n");
		exit(3);
	}
	strncpy(uslov, poc, kraj - poc);

	while (*kraj != ';') kraj++;
	poc = kraj + 1;

	while (*poc && *poc == ' ') poc++;
	kraj = poc;

	while (*kraj != ' ' && *kraj != ')') kraj++;

	postIzraz = calloc((kraj - poc + 1), sizeof(char));
	if (postIzraz == NULL)
	{
		printf("Nije uspela dodela memorije!\n");
		exit(3);
	}
	strncpy(postIzraz, poc, kraj - poc);

	p = postIzraz;
	k = p;
	while (*k != '+' && *k != '-') k++;

	while (*kraj != '{') kraj++;
	poc = kraj + 1;
	kraj = poc + 1;

	while (*kraj != '}') kraj++;

	izraz = ubaciDveTacke(izraz);

	printf("%s %s %s\n", izraz, uslov, postIzraz);

	kopija = calloc(strlen(izraz) + 8 + strlen(uslov) + 10 + (kraj - poc) + 1 + (2 * (k - p) + 4) + 6 + 1, sizeof(char));
	//izraz + "; while " + uslov + " do begin " + telo + " " + postIzraz + "; end;" + '\0'
	if (kopija == NULL)
	{
		printf("Nije uspela dodela memorije!\n");
		exit(3);
	}
	strcpy(kopija, izraz);
	strcat(kopija, "; while ");
	strcat(kopija, uslov);
	strcat(kopija, " do begin ");
	strncat(kopija, poc, kraj - poc);
	strcat(kopija, " ");
	strncat(kopija, p, k - p);
	strcat(kopija, ":=");
	strncat(kopija, p, k - p);
	if (*k == '+') strcat(kopija, "+1"); else strcat(kopija, "-1");
	strcat(kopija, "; end;");

	free(izraz);
	free(uslov);
	free(postIzraz);

	return kopija;
}

int main()
{
	char *string, *kopija;
	char krajString[] = "dosta Brus Li";

	for (string = unesi(); strcmp(string, krajString); string = unesi())
	{
		printf("Uneli ste : %s\n", string);
		kopija = obradiString(string);

		printf("Nakon obrade: %s\n", kopija);

		free(string);
		free(kopija);
	}
	free(string);

	return 0;
}