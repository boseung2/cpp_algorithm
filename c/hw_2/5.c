#include <stdio.h>
int main(void){
    float s=0.0f;
    for(int i=0;i<10;i++) s += 0.1f;
    printf("%.10f\n", s); // 0.9999999404 등
}