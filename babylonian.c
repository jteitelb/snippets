#include <math.h>
#include <stdio.h>

double babSqrt(double x)
{
    double guess = x;
    for(int i = 0; i < 100; i++)
        guess = (guess + x/guess)/2;
    return guess;
}

int main(void)
{
    double x;
    printf("Please enter a number:\n");
    scanf("%lf", &x);
    printf("babylonian: %.15lf\n",babSqrt(x));
    printf("C built-in: %.15lf\n",sqrt(x));
    return 0;
}

