#include <stdio.h>

int fib (int n, int a, int b) {
    if (n == 1) {
        return a;
    }
    else if (n == 2) {
        return b;
    } 
    else if (n > 2) {
        return fib(n-1, a, b) + fib(n-2, a, b);
    }
    else {
        return 0;
    }

}

int main() {
    int n, a, b, res;

    scanf("%d %d %d", &n, &a, &b);

    res = fib(n,a,b);

    printf("%d\n", res);

    return 0;
}