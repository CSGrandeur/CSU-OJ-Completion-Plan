#include<stdio.h>
#include<string.h>
#include<algorithm>
const int maxn = 111;
const int maxm = 30011;
const int MAXNUM = 0x3f3f3f3f;
int L, N, M, S, T, B;
int hz[maxn][maxn];
int bus[maxn];
int fst[maxn], nex[maxm], v[maxm], w[maxm], cost[maxm];
int ntp;
int dp[105][maxn];
inline void AddEdge(int s, int t, int len, int c)
{
    nex[ntp] = fst[s];
    v[ntp] = t;
    w[ntp] = len;
    cost[ntp] = c;
    fst[s] = ntp ++;
}
void Floyd()
{
    for(int i = 1; i <= N; i ++)
        for(int j = 1; j <= N; j ++)
            for(int k = 1; k <= N; k ++)
                hz[i][j] = std::min(hz[i][k] + hz[k][j], hz[i][j]);
}
int DPS(int costNow, int siteNow)
{
    if(costNow > L) return MAXNUM;
    int &ans = dp[costNow][siteNow];
    if(ans != -1) return ans;
    if(siteNow == T) return ans = 0;
    ans = MAXNUM;
    for(int i = fst[siteNow]; i != -1; i = nex[i])
    {
        ans = std::min(ans, DPS(costNow + cost[i], v[i]) + w[i]);
    }
    return ans;
}
int main()
{
    int t, s, e, len, ans;
    int K;
    for(scanf("%d", &t); t --; )
    {
        memset(fst, -1, sizeof(fst));
        memset(hz, 0x3f, sizeof(hz));
        memset(dp, -1, sizeof(dp));
        ntp = 0;
        scanf("%d%d%d%d%d%d", &L, &N, &M, &S, &T, &B);
        for(int i = 0; i < M; i ++)
        {
            scanf("%d%d%d", &s, &e, &len);
            hz[s][e] = hz[e][s] = len;
        }
        for(int i = 1; i <= B; i ++)
        {
            scanf("%d", &K);
            for(int j = 0; j < K; j ++)
            {
                scanf("%d", &bus[j]);
                int last = j, tmpLen = 0;
                for(int k = j - 1; k >= 0; last = k --)
                {
                    tmpLen += hz[bus[last]][bus[k]];
                    AddEdge(bus[k], bus[j], tmpLen * 250, 6);
                }
            }
        }
        Floyd();
        for(int i = 1; i <= N; i ++)
            for(int j = 1; j <= N; j ++)
            {
                if(hz[i][j] != MAXNUM)
                {
                    AddEdge(i, j, hz[i][j] * 1000, hz[i][j] * 3);
                    AddEdge(i, j, hz[i][j] * 125, 10 + (hz[i][j] > 3 ? (hz[i][j] - 3) * 2 : 0));
                }
            }
        ans = DPS(0, S);
        if(ans == MAXNUM)
            printf("no\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}