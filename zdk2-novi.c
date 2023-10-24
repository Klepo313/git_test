#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Osoba {
    char ime[100];
    char prezime[100];
    int god_rod;
    struct Osoba *sljedeci;
};

struct Osoba* dodajNaPocetak(struct Osoba *prva_osoba, char ime[], char prezime[], int god_rod) {
    struct Osoba *novaOsoba = (struct Osoba *)malloc(sizeof(struct Osoba));
    if (novaOsoba == NULL) {
        printf("GREŠKA pri alociranju memorije.\n");
        return prva_osoba;
    }
    
    strcpy(novaOsoba->ime, ime);
    strcpy(novaOsoba->prezime, prezime);
    novaOsoba->god_rod = god_rod;
    novaOsoba->sljedeci = prva_osoba;
    
    return novaOsoba;
}

struct Osoba* dodajNaKraj(struct Osoba *prva_osoba, char ime[], char prezime[], int god_rod) {
    struct Osoba *novaOsoba = (struct Osoba *)malloc(sizeof(struct Osoba));
    if (novaOsoba == NULL) {
        printf("GREŠKA pri alociranju memorije.\n");
        return prva_osoba;
    }
    
    strcpy(novaOsoba->ime, ime);
    strcpy(novaOsoba->prezime, prezime);
    novaOsoba->god_rod = god_rod;
    novaOsoba->sljedeci = NULL;
    
    if (prva_osoba == NULL) {
        return novaOsoba;
    }
    
    struct Osoba *trenutna_osoba = prva_osoba;
    while (trenutna_osoba->sljedeci != NULL) {
        trenutna_osoba = trenutna_osoba->sljedeci;
    }
    
    trenutna_osoba->sljedeci = novaOsoba;
    
    return prva_osoba;
}

void ispisiListu(struct Osoba *prva_osoba) {
    struct Osoba *trenutna_osoba = prva_osoba;
    while (trenutna_osoba != NULL) {
        printf("%s %s, %d\n", trenutna_osoba->ime, trenutna_osoba->prezime, trenutna_osoba->god_rod);
        trenutna_osoba = trenutna_osoba->sljedeci;
    }
}


int main() {
    struct Osoba *prva_osoba = NULL;

    prva_osoba = dodajNaPocetak(prva_osoba, "Ante", "Ivić", 1990);
    prva_osoba = dodajNaPocetak(prva_osoba, "Ana", "Ivandić", 1985);

    printf("Lista:\n");
    ispisiListu(prva_osoba);

    prva_osoba = dodajNaKraj(prva_osoba, "Petar", "Perić", 2000);

    printf("\nLista nakon dodavanja na kraj:\n");
    ispisiListu(prva_osoba);
}