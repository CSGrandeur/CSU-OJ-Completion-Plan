#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <set>
#include <string>
#include <cstring>
#include <stack>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define ms(x,a) memset((x),(a),sizeof(a))
#define L 32
using namespace std;
const int maxn=1e5+5;
const int maxl=2;

typedef long long ll;
typedef struct Trie
{
	int v;
	Trie* next[maxl];
}Trie;

Trie *root;
void iniTrie()
{
	root=(Trie*)malloc(sizeof(Trie));
	for(int i=0;i<maxl;i++)
		root->next[i]=NULL;
	root->v=-1;
}

void creTrie(int a)
{
	int temp[35];
	int id=L-1;
	while(a){
		temp[id--]=(a&1);
		a/=2;
	}
	rep(i,0,id+1) temp[i]=0;

	int l=L;
	Trie *p=root,*q;
	for(int i=0;i<l;i++)
	{
		int id=temp[i];
		if(p->next[id]!=NULL) {
			p=p->next[id];
		}
		else{
			q=(Trie*)malloc(sizeof(Trie));
			q->v=1;
			for(int j=0;j<maxl;j++) q->next[j]=NULL;
			p->next[id]=q;
			p=p->next[id];
		}

	}
}

int findTrie(int a)
{
	int aa=a;
	int temp[35];
	int id=L-1;
	while(a){
		temp[id--]=(a&1);
		a/=2;
	}
	rep(i,0,id+1) temp[i]=0;

	int aans=0;
	Trie *p=root;
	int l=L;
	for(int i=0;i<l;i++){
		int index=!temp[i];
		if(p->next[index]!=NULL){
			aans=(aans<<1)+index;
			p=p->next[index];
		}
		else{
			aans=(aans<<1)+temp[i];
			p=p->next[temp[i]];
		}
	}
	return aans^aa;
}

void delTrie(Trie *p)
{
    int i;
    for(i=0;i<maxl;i++)
    {
        if(p->next[i] != NULL)
            delTrie(p->next[i]);
    }
    free(p);
	p==NULL;
	return ;
}

int a[maxn],n;

int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n){
		iniTrie();
			rep(i,0,n){
			cin>>a[i];
			creTrie(a[i]);
		}
		int fans=0;
		rep(i,0,n){
			fans=max(fans,findTrie(a[i]));
		}
		cout<<fans<<endl;
		delTrie(root);
	}

}