#include <stdio.h>
#include <math.h>

double fact(int n) {
    if(n == 0) 
        return 1;
    else 
        return n * fact( n - 1);
}

double myPow(double a, double b) {

    int i;
    double p = 1;

    for(i = 1; i <= b; ++i) 
        p *= a;

    return p;
}

double mySin(double x) {
    int i = 2;
    double EPS = 0.001;
    double term1 = x, term2 = x - (float) myPow(x, 3) / fact(3.0);

    while( fabs(term1-term2) >= EPS ) {
        term1 = term2;
        term2 += (double) pow(-1, i) * (double) myPow(x, (2*i+1)) / fact(2*i+1);
        i++;
    }        

    return term2;  
}

int main() {

    double x;

    printf("x=");
    scanf("%lf", &x);

    //printf with %lf for double as well
    printf("sin(%.3lf) = %.9lf\n", x , sin( x ));
 return 0;
}