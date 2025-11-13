#include <math.h>
#include <stdio.h>
int almost_equal(double x, double y, double rel, double abs){
    double d=fabs(x-y);
    if(d<=abs) return 1;
    return d<=fmax(fabs(x),fabs(y))*rel;
}
int main(void){
    double s=0.1+0.2, t=0.3;
    printf("%s\n", almost_equal(s,t,1e-12,1e-15)?"EQ":"NE");
}
