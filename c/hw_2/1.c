#include <stdio.h>
int main(void){
    float  xf = 0.1f;
    printf("float  : %.20f\n", xf); // 0.10000000149011611938

    // double로 정밀도 올리기
    double xd = 0.1;
    printf("double : %.20f\n", xd); // 0.10000000000000000555
}