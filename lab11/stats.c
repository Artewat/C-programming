#include <stdarg.h>
#include <limits.h>

double summ(int count, ...) {
    va_list args;
    va_start(args, count);
    double total = 0;

    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }

    va_end(args);
    return total;
}

double avg(int count, ...) {
    va_list args;
    va_start(args, count);
    double total = 0;

    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }

    va_end(args);
    return (count == 0) ? 0 : total / count;
}

int maxi(int count, ...) {
    va_list args;
    va_start(args, count);
    int max = INT_MIN;

    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int);
        if (num > max) max = num;
    }

    va_end(args);
    return max;
}

int mini(int count, ...) {
    va_list args;
    va_start(args, count);
    int min = INT_MAX;

    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int);
        if (num < min) min = num;
    }

    va_end(args);
    return min;
}
