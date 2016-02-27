#include <stdio.h>

void getVar(double * var, char * prompt);

int main()
{
    double xi; // initial position
    double vi; // initial speed
    double t; // time
    double a; // acceleration
    double xf; // final position
    double vf; // final speed

    getVar(&xi, "Enter initial position:");
    getVar(&vi, "Enter initial speed:");
    getVar(&t, "Enter time:");
    getVar(&a, "Enter acceleration:");

    xf = xi + vi*t + 0.5*a*t*t;
    vf = vi + a*t;

    printf("\n\nFinal position:%.2lfm\n", xf);
    printf("\n\nFinal speed:%.2lfm/s\n", vf);

    return 0;
}

void getVar(double * var, char * prompt)
{
    printf("%s\n", prompt);
    scanf("%lf", var);
    while(getchar() != '\n'){}
}


