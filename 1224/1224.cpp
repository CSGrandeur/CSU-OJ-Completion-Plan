#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define maxn 35
using namespace std;
int n,m,x1,y1,x2,y2;

bool vis[maxn][maxn];
int dir[8][2]={{-2,1},{-2,-1},{-1,2},{-1,-2},{1,2},{1,-2},{2,1},{2,-1}};
struct State // BFS 队列中的状态数据结构
{
	int x,y;
	int Step_Counter; // 搜索步数统计器
};
int ans[maxn];

bool CheckState(State next) // 约束条件检验
{
	if(next.x>=1&&next.x<=n&&next.y>=1&&next.y<=m&&!vis[next.x][next.y]) // 满足条件
	{
		return 1;
	}
	else // 约束条件冲突
		return 0;
}

void bfs(State st)
{
	int flag=0;
	queue <State> q; // BFS 队列
	State now,next; // 定义2个状态，当前和下一个
	st.Step_Counter=0; // 计数器清零
	q.push(st); // 入队
	vis[st.x][st.y]=1; // 访问标记
	while(!q.empty())
	{
		now=q.front(); // 取队首元素进行扩展
//		a[now.i].Step_Counter=++circle;
		if(now.x==x1&&now.y==y1)
		{
			flag=1;
			printf("%d\n",now.Step_Counter);
			return ;
		}

		for(int i=0;i<8;i++)
		{
			next.x=now.x+dir[i][0];
			next.y=now.y+dir[i][1];
			next.Step_Counter=now.Step_Counter+1; // 计数器加1
			if(CheckState(next)) // 如果状态满足约束条件则入队
			{
				q.push(next);
				vis[next.x][next.y]=1; //访问标记
			}
		}
		q.pop(); // 队首元素出队
	}
	printf("-1\n");
 	return;
}

int main()
{
	while(~scanf("%d%d%d%d%d%d",&n,&m,&x1,&y1,&x2,&y2))
	{
		memset(vis,0,sizeof(vis));
		State start;
		start.x=x2;
		start.y=y2;
		bfs(start);

	}
	return 0;
}
