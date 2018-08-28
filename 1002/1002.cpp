#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    long long a, b;
    while(scanf("%lld%lld", &a, &b) && a && b)
    {
        printf("%lld\n", a + b);
    }
    return 0;
}