#include <stdio.h>
#include <stddef.h>

// 순차합
static double naive_sum(const double *values, size_t count) {
    double total = 0.0;
    for (size_t i = 0; i < count; ++i) {
        total += values[i];
    }
    return total;
}

// 보상합
static double kahan_sum(const double *values, size_t count) {
    double total = 0.0;
    double compensation = 0.0;
    for (size_t i = 0; i < count; ++i) {
        double y = values[i] - compensation;
        double t = total + y;
        compensation = (t - total) - y;
        total = t;
    }
    return total;
}

int main(void) {
    double a = 1e16;
    double b = -1e16;
    double c = 1.0;

    printf("(a + b) + c = %.1f\n", (a + b) + c);
    printf("a + (b + c) = %.1f\n", a + (b + c));

    const double data[] = {
        a,
        1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 1.0,
        b
    };
    const size_t count = sizeof(data) / sizeof(data[0]);

    double plain = naive_sum(data, count);
    double compensated = kahan_sum(data, count);

    printf("naive sum      = %.1f\n", plain);
    printf("kahan sum      = %.1f\n", compensated);
    printf("difference     = %.1f\n", compensated - plain);

    return 0;
}
