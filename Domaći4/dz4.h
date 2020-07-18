	typedef struct element {
	char ime[50];
	char klasa; //biznis ili ekonomska
	char op; //oznaka prioriteta(R regularan putnik, I–osoba sa posebnim potrebama, P–trudnice, F–osobe samalom decom, S–osobe starije od 65 godina)
	int brreda;
	char brsedista; // slovo od A do F
	struct element *sledeci;
} Putnik;

Putnik* ucitaj1(char ime[50], char klasa, char op, Putnik *p);
Putnik* ucitaj2(Putnik *p);
Putnik* izbaci(char ime[50], int klasa, int op, Putnik *p);
void brisi(Putnik *p);
void ispis(Putnik *p);
int ucitavanje(Putnik **glava, int n);
int duzina(Putnik *p);
void obrada(Putnik* p, int e, int b);
void sortiraj(Putnik* p);
void novaobrada(Putnik *p, int n);