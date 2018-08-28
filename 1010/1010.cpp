#include<stdio.h>
int p[100011];
int dis[100011];
bool s[100011];
int fa(int x)
{
    if(x == p[x]) return x;
    fa(p[x]);
    dis[x] += dis[p[x]];
    p[x] = fa(p[x]);
    return p[x];
}
int main()
{
    int n, a, b;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i <= n; i ++)
            p[i] = i, dis[i] = 0, s[i] = false;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d%d", &a, &b);
            s[a] = true;
            p[b] = a;
            dis[b] = 1;
            fa(b);
        }
        int ans = -1;
        for(int i = 1; i <= n; i ++)
        {
            fa(i);
            if (!s[i] && (ans == -1 || dis[i] < dis[ans]))
                ans = i;
        }
        printf("%d\n", ans);
    }
    return 0;
}