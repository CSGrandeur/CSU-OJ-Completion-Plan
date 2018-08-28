#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
const int TURN_NUM[4][4] =
        {
                {0, 2, 1, 1},
                {2, 0, 1, 1},
                {1, 1, 0, 2},
                {1, 1, 2, 0}
        };
//方向压缩到 0:x正，1:x负，2:y正，3:y负
inline int Dir(int s, int e, int is_y){return (e > s) + (is_y << 1);}
inline int ArrowDir(int * a){return a[0] != a[2] ? Dir(a[0], a[2], 0) : Dir(a[1], a[3], 1);}
void OneStep(int s, int e, int is_y, int &turn, int &dir)
{
    if(s == e) return;
    int nex_dir = Dir(s, e, is_y);
    turn += TURN_NUM[dir][nex_dir];
    dir = nex_dir;
}
int TryOneDir(int is_y, int dir, int *now, int *nex)
{
    int turn = 0;
    OneStep(now[is_y + 2 ], nex[is_y], is_y, turn, dir);
    OneStep(now[!is_y + 2 ], nex[!is_y], !is_y, turn, dir);
    OneStep(nex[0], nex[2], 0, turn, dir);
    OneStep(nex[1], nex[3], 1, turn, dir);
    return turn;
}
int main()
{
    int t, n, aw[2][4];
    for(scanf("%d", &t); t --; )
    {
        scanf("%d", &n);
        for(int i = 0; i < 4; i ++) scanf("%d", &aw[0][i]);
        int now_dir = ArrowDir(aw[0]), totalTurn = 0, totalDis = abs(aw[0][0] - aw[0][2]) + abs(aw[0][1] - aw[0][3]);
        for(int i = 0; -- n; i ^= 1)
        {
            for(int j = 0; j < 4; j ++) scanf("%d", &aw[!i][j]);
            totalTurn += std::min(TryOneDir(0, now_dir, aw[i], aw[!i]),
                                  TryOneDir(1, now_dir, aw[i], aw[!i]));
            now_dir = ArrowDir(aw[!i]);
            totalDis += abs(aw[i][2] - aw[!i][0]) + abs(aw[i][3] - aw[!i][1]) +
                    abs(aw[!i][0] - aw[!i][2]) + abs(aw[!i][1] - aw[!i][3]);
        }
        printf("%d %d\n", totalDis, totalTurn);
    }
    return 0;
}