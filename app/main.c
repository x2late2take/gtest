#include <stdio.h>
#include "tribonacchi.h"

int main() {
    unsigned long long result = tribonacchi(5);
    printf("tribonacchi(%d) = %llu\n", 5, result);

    return 0;
}
