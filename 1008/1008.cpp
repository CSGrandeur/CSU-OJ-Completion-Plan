#include<stdio.h>
#include<stack>
int main()
{
    int n, horcrux, nowcolor;
    std::stack<int> s;
    while(scanf("%d", &n) != EOF)
    {
        nowcolor = -1;
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &horcrux);
            if(s.empty() || horcrux != nowcolor && (i & 1))
            {
                s.push(i);
                nowcolor = horcrux;
            }
            else if(horcrux != nowcolor)
            {
                nowcolor = horcrux;
                if(s.size() > 1) s.pop();
            }
        }
        int ans = 0, right = n + 1;
        while(!s.empty())
        {
            ans += (!nowcolor) * (right - s.top());
            nowcolor = !nowcolor;
            right = s.top();
            s.pop();
        }
        printf("%d\n", ans);
    }
    return 0;
}