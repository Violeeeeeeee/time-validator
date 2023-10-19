#include <stdio.h>

int main() {
    printf("Dzielenie x na y\n\nwpisz x\n");
    float x, y, ANSWER;
    scanf("%f", &x) ;
    printf("wpisz y\n");
    scanf("%f", &y);

    if (y == 0) {
        printf("Dzielenie przez zero jest niedozwolone.\n");
    } else {
        ANSWER = x / y;
        printf("Wynik dzielenia: %f\n", ANSWER);
    }

    return 0;
}

