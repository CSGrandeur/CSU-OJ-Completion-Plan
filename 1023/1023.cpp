#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=1e5+5;
int t,n,m;
int road[maxn];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(road,0,sizeof(road));
		scanf("%d%d",&m,&n);
		int high=0,low=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d",&road[i]);
			high+=road[i];
			low=max(road[i],low);
		}
		while(low<high)
		{

			int mid=(high+low)>>1;
			int tot=n-1,sum=road[0];
			for(int i=1;i<m;i++)
			{
				if(sum+road[i]>mid)
				{
					tot--;
					sum=road[i];
				}
				else sum+=road[i];
				if(tot<0) break;
			}
			if(tot<0) low=mid+1;
			else high=mid;
		}
		printf("%d\n",low);

	}
 }