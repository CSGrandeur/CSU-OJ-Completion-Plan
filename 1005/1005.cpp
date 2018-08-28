#include<stdio.h>
struct Node
{
    int num;
    int left;
    int right;
    Node(){left = right = num = -1;}
};
Node nd[1111];
int ltp;
void Insert(int x, int now)
{
    if(nd[now].num == -1)
        nd[now].num = x;
    else if(nd[now].num > x)
    {
        if(nd[now].left == -1)
            nd[ltp] = Node(), nd[now].left = ltp ++;
        Insert(x, nd[now].left);
    }
    else
    {
        if(nd[now].right == -1)
            nd[ltp] = Node(), nd[now].right = ltp ++;
        Insert(x, nd[now].right);
    }
}
bool printed;
void PrintTree(int now, int order)
{
    if(order == 1)
        printf(printed ? " %d" : "%d", nd[now].num), printed = true;
    if(nd[now].left != -1)
        PrintTree(nd[now].left, order);
    if(order == 2)
        printf(printed ? " %d" : "%d", nd[now].num), printed = true;
    if(nd[now].right != -1)
        PrintTree(nd[now].right, order);
    if(order == 3)
        printf(printed ? " %d" : "%d", nd[now].num), printed = true;
}
int main()
{
    int t, n;
    for(scanf("%d", &t); t --; )
    {
        scanf("%d", &n);
        ltp = 0;
        nd[ltp ++] = Node();
        int x;
        while(n --)
        {
            scanf("%d", &x);
            Insert(x, 0);
        }
        printed = false; PrintTree(0, 1); printf("\n");
        printed = false; PrintTree(0, 2); printf("\n");
        printed = false; PrintTree(0, 3); printf("\n");
        printf("\n");
    }
    return 0;
}