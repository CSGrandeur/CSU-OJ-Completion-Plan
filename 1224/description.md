### Problem Title
ACM小组的古怪象棋

### Time Limit(S)
1

### Memory Limit(MByte)
128

### Description
ACM小组的Samsara和Staginner对中国象棋特别感兴趣，尤其对马（可能是因为这个棋子的走法比较多吧）的使用进行深入研究。
今天他们又在 构思一个古怪的棋局:假如Samsara只有一个马了，而Staginner又只剩下一个将，两个棋子都在棋盘的一边，
马不能出这一半棋盘的范围，另外这 一半棋盘的大小很奇特($n$行$m$列)。Samsara想知道他的马最少需要跳几次才能吃掉Staginner的将(我们假定其不会移动)。
当然这个光荣的任务就落在了会编程的你的身上了。

### Input Description 
每组数据一行，分别为六个用空格分隔开的正整数，
$n,m,x1,y1,x2,y2 (1<=x1,x2<=n<=20,1<=y1,y2<=m<=20)$，这六个数分别代表棋盘的大小$n,m$，以及将的坐标和马的坐标（将和马的坐标不相同）。

### Output Description
输出对应也有若干行，请输出最少的移动步数,如果不能吃掉将则输出“-1”(不包括引号)。

### Sample Input
8 8 5 1 4 5

### Sample Output
3

### Hint


### Source
CSU Monthly 2011 Dec.

### Author

### SpecialJudge
No