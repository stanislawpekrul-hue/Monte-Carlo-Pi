#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct { // definiujemy strukture punktu
    double x;
    double y;
} Punkt;
Punkt losowy_punkt(void){ // definiujemy funkcje, ktora losuje punkt, ktorego wspolrzedne sa z przedzialu [0,1]
    Punkt p;
    p.x = (double) rand()/ RAND_MAX;
    p.y = (double) rand()/ RAND_MAX;
    return p;
}

double kwadrat_odleglosci(Punkt p){ // definiujemy funckje, ktora podaje kwadrat odleglosci punktu od poczatku ukladu wspolrzednych
    return (p.x) * (p.x) + (p.y) * (p.y);
}

int main(void){
    int n;
    scanf("%d", &n); // wczytujemy liczbe losowan
    srand((unsigned int)time(NULL)); // inicjalizujemy generator liczb pseudolosowych
    int punkty_w_kole = 0;
    for (int i = 0; i < n; i++){ // n razy losujemy punkt i sprawdzamy, czy lezy w kole o srodku w (0,0) i promieniu 1
            if (kwadrat_odleglosci(losowy_punkt()) <= 1) punkty_w_kole++;
    }
    double przyblizenie = (double)punkty_w_kole / n * 4;
    printf("%f\n", przyblizenie);
    return 0;
}

