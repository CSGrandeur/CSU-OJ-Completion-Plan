#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    double a, b;
    while(scanf("%lf%lf", &a, &b) != EOF)
    {
        printf("%.4f\n", a + b);
    }
    return 0;
}