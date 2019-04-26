#include <stdio.h>
#include <math.h>

double f(double x, int n)
{

double r;

r = (-1) * pow(x, 2) / ((2 * n - 1) * (2 * n - 2));

return (r);
}



int main(void)
{
	int i = 2, j = 0, k, N = 0, d;
	double R, SR, X, SX, temp;
    const double pi = 3.1415926;
	printf("Please input N (N >= 2)\n");  scanf("%d", &N);
	printf("Please input X\n");  scanf("%lf", &X);
	double plot[N];
    
    SX = X;
	/* X = (pi * X) / 180; */
    d = X / (2*pi);
    X = X - d * 2 * pi;
	R = X;
    /*printf("%lf\n", R);*/
	temp = R;
	plot[0] = R;
    
    /* The following code is going to calculate the result of sin. */
    while(i <= N){
    	R = R + f(X, i) * temp;
    	plot[i-1] = R;
    	temp = f(X, i) * temp;
    	i++;
    }
    
    SR = sin(SX);
    printf("Result by the program: %.10lf. Standard Result: %.10lf\n", R, SR);
    
    /* The following code is going to generate the values to evaluate our approximation 
    and they are going to be stored in the array plot. */
    puts("Now I am outputing the data for making the plot");
    while(j < N){
    	plot[j] = (plot[j] - sin(SX)) / sin(SX);
    	plot[j] = fabs(plot[j]);
    	k = j + 1;
    	/*printf("The %dth level result is %lf\n", k, plot[j]);*/
        printf("%lf\n", plot[j]);
    	j++;
    }

	return 0;
}