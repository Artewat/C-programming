#include <stdio.h>
#include "stats.h"

int main() {
    int count = 6;
    int a = 10, b = 20, c = -5, d = 30, e = 15, f = 50;

    printf("Sum: %.2f\n", summ(count, a, b, c, d, e, f));
    printf("Average: %.2f\n", avg(count, a, b, c, d, e, f));
    printf("Maximum: %d\n", maxi(count, a, b, c, d, e, f));
    printf("Minimum: %d\n", mini(count, a, b, c, d, e, f));

    return 0;
}
