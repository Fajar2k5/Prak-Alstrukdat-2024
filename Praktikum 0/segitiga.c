#include <stdio.h>

int main() {
    int n;
    int i;
    int j;
    int k;

    i = 0;

    scanf("%d", &n);

    for (;n>0;n--) {
        for (j=0;j<i;j++) {
            printf(" ");
        };
        for (k=2*n-1;k>0;k--) {
            printf("*");
        };

        i++;
        printf("\n");
    };

    return 0;
}