#include<stdio.h>
#include<math.h>
int main()
{
    long long x, y, r;
    while(scanf("%lld%lld%lld", &x, &y, &r) && (x || y || r))
    {
        long long ans = 0;
        for(long long i = 0; i < r; i ++)
        {
            ans += (long long)(ceil(sqrt(r * r - i * i)) + 1e-8);
        }
        printf("%lld\n", ans * 4);
    }
    return 0;
}