#include<stdio.h>
#include<algorithm>
double p[11][111];
int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) && n && m)
    {
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                scanf("%lf", &p[j][i]);
        for(int j = 0; j < m; j ++)
            std::sort(p[j], p[j] + n);
        double ret = 0, tmp;
        for(int i = 0; i < n; i ++)
        {
            tmp = 1;
            for(int j = 0; j < m; j ++)
                tmp *= p[j][i];
            ret += tmp;
        }
        printf("%.4f\n", ret);
    }
    return 0;
}