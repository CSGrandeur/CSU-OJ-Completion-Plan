#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <vector>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define PI acos((double)-1)
#define E exp(double(1))
#define K 1000000+9
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define ms(x,a) memset((x),(a),sizeof(a))
const int maxn=2e5+5;
int nt[maxn];
int aa[maxn],bb[maxn];
int a[maxn],b[maxn];
int n;
//参数为模板串和next数组
//字符串均从下标0开始
void kmpGetNext(int *s,int *Next)
{
    Next[0]=0;
//    int len=strlen(s);
    for(int i=1,j=0;i<n;i++)
    {
        while(j&&s[i]!=s[j]) j=Next[j];
        if(s[i]==s[j]) j++;
        Next[i+1]=j;
    }
//    Next[len]=0;
}
int kmp(int *ss,int *s,int *Next)
{
    kmpGetNext(s,Next);
    for(int i=0,j=0;i<2*n;i++)  //倍长
    {
        while(j&&ss[i%n]!=s[j])j=Next[j];
        if(ss[i%n]==s[j]) j++;
        if(j==n){
			return 1;
		}

    }
	return 0;
}

int main(void)
{
	ios::sync_with_stdio(false);
    while(cin>>n)
    {
    	memset(a,0,sizeof(a));
    	memset(b,0,sizeof(b));
    	rep(i,0,n) cin>>aa[i];
    	rep(i,0,n) cin>>bb[i];
    	sort(aa,aa+n);
    	sort(bb,bb+n);
    	rep(i,0,n-1){
    		a[i]=aa[i+1]-aa[i];
    		b[i]=bb[i+1]-bb[i];
		}
		a[n-1]=360000+aa[0]-aa[n-1];
//		rep(i,0,n) cout<<a[i]<<" ";
//		cout<<endl;
		b[n-1]=360000+bb[0]-bb[n-1];
//		rep(i,0,n) cout<<b[i]<<" ";
//		cout<<endl;
    	if(kmp(a,b,nt))
    		cout<<"possible"<<endl;
    	else cout<<"impossible"<<endl;
    }

    return 0;
}