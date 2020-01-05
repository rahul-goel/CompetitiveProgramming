#include <stdio.h>
#include <math.h>
const double pr = 0.00000001;
const double pi = 3.141592653589;
int main()
{
    double a, h, x;
    scanf("%lf %lf %lf", &a, &h, &x);
    if(x<pr)
        printf("%0.10lf\n", 180.0);
    else if((double)x - (double)a*a*h/2 > -pr)
    {
        double value = (double)(2*h*a*a - 2*x)/(a*a*a);
        double start = 0, end = 90, guess;
        while(fabs(value - (double)tan(guess*pi/180))>pr)
        {
            guess = (start+end)/2;
            if(value-(double)tan(guess*pi/180)>=pr)
                start = guess;
            else
                end = guess;
        }
        printf("%0.10lf\n", guess);
    }
    else
    {
        double value = (double)(h*h*a)/(2*x);
        double start = 0, end = 90, guess;
        while(fabs(value - tan(guess*pi/180))>pr)
        {
            guess = (start+end)/2;
            if(value-tan(guess*pi/180)>=pr)
                start = guess;
            else
                end = guess;
        }
        printf("%0.10lf\n", guess);
    }
    return 0;
}