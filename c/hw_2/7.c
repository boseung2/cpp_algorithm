#include <stdio.h>
int main(void){
    double big = 1e308 * 1e10;   // overflow -> inf
    double sml = 1e-308 / 1e10;  // underflow -> 0
    printf("big=%e\nsml=%e\n", big, sml);
}