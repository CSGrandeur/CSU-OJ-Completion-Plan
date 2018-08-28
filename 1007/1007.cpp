#include<stdio.h>
int main()
{
    int t;
    int px, py, ax, ay, bx, by;
    for(scanf("%d", &t); t --; )
    {
        scanf("%d%d%d%d%d%d", &px, &py, &ax, &ay, &bx, &by);
        if(px < ax || px > bx || py < ay || py > by)
            printf("Outside\n");
        else if(px == ax || px == bx || py == ay || py == by)
            printf("On\n");
        else
            printf("Inside\n");
    }
    return 0;
}