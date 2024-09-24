#include <stdio.h>

int main () {
    int a, b;

    scanf("%d %d", &a, &b);
    
    if ((a >= 1) && (b <= 1000)) {
        while (a <= b) {
            printf("%d", a);
            if (a % 2 == 0) {
                a *= 2;
            } else {
                a++;
            };
            if (a < b) {
                printf(" ");
            } else {
                printf("\n");
            };
        };
    } else {
        printf("\n");
    };
    return 0;
}