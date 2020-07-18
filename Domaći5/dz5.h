typedef struct {
	char c;
} pod;

typedef struct elem {
	pod *p;
	struct elem *sled, *pret;
}Elem;

Elem *ucitavanje(FILE *ul, Elem *prvi);
void obrada(FILE *iz, Elem *prvi);
void upis(Elem *prvi, FILE *iz);
void obrisi(Elem *prvi);
void ispis(Elem *prvi);