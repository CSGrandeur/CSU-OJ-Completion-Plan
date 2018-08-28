#include<stdio.h>
int main()
{
    int t, n;
    char buf[111];
    for(scanf("%d", &t); t --; )
    {
        int score = 0, tmpscore = 0;
        scanf("%d%s", &n, buf);
        for(int i = 0; i <= n; i ++)
        {
            buf[i] == '1' ? tmpscore ++ : (tmpscore = 0);
            score += 10 * ((tmpscore - 1) % 5 + 1);
        }
        int level = (score + 50) / 100;
        printf("%d\n", level > 8 ? 8 : level);
    }
    return 0;
}