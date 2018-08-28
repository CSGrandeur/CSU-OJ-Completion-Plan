#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
struct cmp { ;
    bool operator()(const pii &a, const pii &b) const {
        return a.first != b.first ? a.first > b.first : a.second < b.second;
    }
};
int main()
{
    int t, n, l, h;
    char start[10];
    for(scanf("%d", &t); t --; )
    {
        priority_queue<pii, vector<pii>, cmp> H;
        int ansl = 0, ansh = 0;
        vector<pii> L;
        scanf("%d%s", &n, start);
        for(int i = 0; i < n; i ++)
        {
            scanf("%d%d", &l, &h);
            L.push_back(pii(l, h));
        }
        sort(L.begin(), L.end(), cmp());
        if(start[0] == 'L')
            ansl += L[0].first;
        for(int isH = 1, i = start[0] == 'L'; i < L.size(); isH ^= 1, i ++)
        {
            pii &now = L[i];
            if(isH)
            {
                ansh += now.second;
                H.push(pii(now.second, now.first));
            }
            else
            {
                if(!cmp()(pii(now.second, now.first), H.top()))
                    ansl += now.first;
                else
                {
                    ansl += H.top().second;
                    ansh -= H.top().first;
                    ansh += now.second;
                    H.pop();
                    H.push(pii(now.second, now.first));
                }
            }
        }
        printf("%d %d\n", ansl, ansh);
    }
    return 0;
}