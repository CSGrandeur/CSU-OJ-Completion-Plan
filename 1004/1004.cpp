#include<stdio.h>
int p[111];
int fa(int x)
{
    return x == p[x] ? x : (p[x] = fa(p[x]));
}
int main()
{
    int t, n, m, start, end;
    for(scanf("%d", &t); t --; )
    {
        scanf("%d%d", &start, &end);
        scanf("%d", &n);
        for(int i = 0; i <= 100; i ++)
            p[i] = i;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &m);
            int first = -1, connected;
            while(m --)
            {
                scanf("%d", &connected);
                if(first == -1)
                    first = connected;
                else
                    p[fa(connected)] = fa(first);
            }
        }
        printf("%s\n", fa(start) == fa(end) ? "Yes" : "No");
    }
    return 0;
}