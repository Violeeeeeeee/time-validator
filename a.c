#include <stdio.h>

int main() {
    int x, y;
    printf("wpisz x:\n");
    scanf("%d", &x);
    printf("wpisz y:\n");
    scanf("%d", &y);
    if (x > y){
        printf("%d wieksza od %d\n", x, y);
    } else if(x < y) {
        printf("%d wieksza od %d\n", y, x);
    } else {
        printf("liczby sa rowne %d = %d\n", x, y);
    }
}