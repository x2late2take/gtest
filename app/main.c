#include <stdio.h>
#include "tribonacchi.h"

int main() {
    int n;
    printf("Введите число n: ");
    scanf("%d", &n);

    unsigned long long result = tribonacchi(n);
    printf("Tribonacchi(%d) = %llu\n", n, result);

    return 0;
}
