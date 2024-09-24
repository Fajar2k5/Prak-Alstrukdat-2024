#include <stdio.h>

int main() {
    int n, k, a, i, jumlah;
    jumlah = 0;

    scanf("%d %d", &n, &k);

    for (i=0;i<n;i++) {
        scanf("%d", &a);
        if (a%k) {
            jumlah += a;
        };
    };

    printf("%d\n", jumlah);

    return 0;
}