#include <stdio.h>
int main(void){
    double a=1.0000001, b=1.0000000;
    printf("%.17f\n", a-b); // 0.00000009999999998 ...
}