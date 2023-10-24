#include <stdio.h>
#include <cstdlib>
#include <math.h>

typedef struct {
    char ime[100];
    char prezime[100];
    int bodovi;
}_studenti;

int main(){

    int br;
    char ch;
    FILE *f;
    f = fopen("studenti.txt", "r");

    while(!feof(f)){
        ch = fgetc(f);
        if(ch == '\n') 
            br++;
    }
    	
    rewind(f);

   _studenti *s = (_studenti*)malloc(br * sizeof(_studenti));

    for(int i = 0; i < br; i++){
        fscanf(f, "%s %s %d", s[i].ime, s[i].prezime, &s[i].bodovi);
    }

    printf("STUDENTI:\n");
    printf("IME\tPREZIME\t\tBODOVI\t\tPOSTOTAK\n");
    for(int i = 0; i < br; i++){
        printf("%s\t%s\t\t%d/20\t\t%.0f%%\n", 
            s[i].ime, s[i].prezime, s[i].bodovi, (float)(s[i].bodovi*100)/20);
    }

}