#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Osoba;
typedef struct Osoba *_osoba;

struct Osoba{
    char ime[50], prezime[50];
    int god_rod;
    _osoba *sljedeci;
};

Osoba *dodajNaPocetak(Osoba *prva_osoba, char ime[50], char prezime[50], int gr){
    Osoba *nova_osoba = (Osoba *)malloc(sizeof(Osoba));
    
    if (nova_osoba == NULL) {
        printf("Neuspjelo alociranje memorije.\n");
        return prva_osoba;
    }

    strcpy(nova_osoba->ime, ime);
    strcpy(nova_osoba->prezime, prezime);
    nova_osoba->god_rod= gr;
    nova_osoba->sljedeci = prva_osoba;

    return nova_osoba;
}

_osoba *dodajNaKraj(_osoba *prva_osoba, char ime[50], char prezime[50], int gr){
    _osoba *nova_osoba = (_osoba *)malloc(sizeof(_osoba));
    
    if (nova_osoba == NULL) {
        printf("Neuspjelo alociranje memorije.\n");
        return prva_osoba;
    }

    strcpy(nova_osoba->ime, ime);
    strcpy(nova_osoba->prezime, prezime);
    nova_osoba->god_rod = gr;
    nova_osoba->sljedeci = NULL;

    if(prva_osoba == NULL)
        return nova_osoba;

    _osoba *trenutna = prva_osoba;
    while (trenutna->sljedeci != NULL) {
        trenutna = trenutna->sljedeci;
    }
    
    trenutna->sljedeci = nova_osoba;
    
    return prva_osoba;

}

void ispisiListu(struct Osoba *prva_osoba) {
    struct Osoba *trenutna = prva_osoba;
    while (trenutna != NULL) {
        printf("%s %s (%d)\n", trenutna->ime, trenutna->prezime, trenutna->god_rod);
        trenutna = trenutna->sljedeci;
    }
}

int main(){
    _osoba *prva_osoba = NULL;

    prva_osoba = dodajNaPocetak(prva_osoba, "Ante", "Antic", 1984);
    prva_osoba = dodajNaPocetak(prva_osoba, "Ivana", "Ivanic", 2001);

    printf("Lista:\n");
    ispisiListu(prva_osoba);

    prva_osoba = dodajNaKraj(prva_osoba, "Josko", "Jokic", 1956);

    printf("\nLista nakon dodavanja na kraj:\n");
    ispisiListu(prva_osoba);

    return 0;
}