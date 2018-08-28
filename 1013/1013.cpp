#include<stdio.h>
#include<string.h>
const unsigned LEFT_1357  = 0x01010101;
const unsigned RIGHT_2468 = 0x80808080;
const unsigned LINE_1357  = 0x0F0F0F0F;
const unsigned LINE_2468  = 0xF0F0F0F0;
const unsigned TOP_LINE   = 0x0000000F;
const int maxn = 2013761;
const int hashSize = 1000007;
const int pace[4] = {3, 4, 4, 3};
struct HashNode
{
    unsigned dogs, fox;
    int status, m, next;
    HashNode(){}
    HashNode(unsigned d, unsigned f, int m_, int s, int n)
    :dogs(d), fox(f), m(m_), status(s), next(n){}
    bool Vis(unsigned dogs_, unsigned fox_, int m_)
    {
        return dogs == dogs_ && fox == fox_ && m == m_;
    }
};
HashNode hashBuf[maxn];
int hashPointer[hashSize];
int htp = 0;
inline int GetHash(unsigned dogs, unsigned fox, int m)
{
    int hashNum = ((dogs | fox) % hashSize << 1 | m) % hashSize;
    for(int i = hashPointer[hashNum]; i != -1; i = hashBuf[i].next)
    {
        if(hashBuf[i].Vis(dogs, fox, m))
            return i;
    }
    hashBuf[htp] = HashNode(dogs, fox, m, -1, hashPointer[hashNum]);
    return hashPointer[hashNum] = htp ++;
}
int DPS(unsigned dogs, unsigned fox, int m)
{
    //status == 1表示Dog win， 0表示Fox win，2表示已入栈
    int &status = hashBuf[GetHash(dogs, fox, m)].status;
    if(status != -1)
        return status;
    status = 2;
    if(m == 1)
    {
        bool moveFlag = false;
        unsigned tmpdogs = dogs;
        while(tmpdogs > 0)
        {
            unsigned dog = tmpdogs & -tmpdogs;
            for(int mov = 0; mov < 2; mov ++)
            {
                if(dog & RIGHT_2468 && mov == 1 || dog & LEFT_1357 && mov == 0)
                    continue;
                unsigned nex = dog << pace[mov] + !(dog & LINE_1357);
                if (nex == 0 || dogs & nex || fox & nex)
                    continue;
                moveFlag = true;
                if(DPS(dogs ^ dog ^ nex, fox, !m) == 1)
                    return status = 1;
            }
            tmpdogs &= (tmpdogs - 1);
        }
        if(!moveFlag)
            return status = DPS(dogs, fox, !m);
        else
            return status = 0;
    }
    else
    {
        if(fox & TOP_LINE)
            return status = 0;
        for(int mov = 3; mov >= 0; mov --)
        {
            if(fox & RIGHT_2468 && mov & 1 || fox & LEFT_1357 && ~mov & 1)
                continue;
            unsigned nex;
            if(mov < 2) nex = fox << pace[mov] + !(fox & LINE_1357);
            else nex = fox >> pace[mov] + !(fox & LINE_2468);
            if (nex == 0 || dogs & nex)
                continue;
            if (DPS(dogs, nex, !m) == 0)
                return status = 0;
        }
        return status = 1;
    }
}
int main()
{
    int t, m, x, y;
    unsigned dogs, fox;
    memset(hashPointer, -1, sizeof(hashPointer));
    for(scanf("%d", &t); t --; )
    {
        scanf("%d", &m);
        scanf("%d%d", &x, &y);
        fox = 1u << ((x - 1) << 2 | (y - 1) >> 1);
        dogs = 0;
        for(int i = 0; i < 4; i ++)
        {
            scanf("%d%d", &x, &y);
            dogs |= 1u << ((x - 1) << 2 | (y - 1) >> 1);
        }
        printf("%s\n", DPS(dogs, fox, m) ? "Dog win" : "Fox win");
    }
    return 0;
}