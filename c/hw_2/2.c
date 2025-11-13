#include <stdio.h>
#include <math.h>
#include <float.h>

// 두 실수가 거의 같은지 비교하는 함수
// fma를 사용하여 오차를 줄임
static int nearly_equal(double lhs, double rhs) {
    double diff = fabs(fma(-1.0, rhs, lhs));
    double scale = DBL_EPSILON * fmax(fabs(lhs), fabs(rhs));
    return diff <= scale;
}

int main(void) {
    double a = 0.1;
    double b = 0.2;
    double sum = a + b;

    printf("a        = %.17f\n", a);
    printf("b        = %.17f\n", b);
    printf("a + b    = %.17f\n", sum);
    printf("0.3      = %.17f\n", 0.3);
    printf("sum == 0.3 -> %s\n", (sum == 0.3) ? "true" : "false");

    if (nearly_equal(sum, 0.3)) {
        printf("Equal within tolerance when checked via fma-based difference.\n");
    } else {
        printf("Still unequal even after fma-based comparison.\n");
    }

    return 0;
}
