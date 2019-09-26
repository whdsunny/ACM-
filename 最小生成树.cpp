#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 105
using namespace std;
int n,m,fa[N],num;
struct node{
	int l,r,d;
}a[N];
bool cmp(node a, node b){
	return a.d<b.d;		//最大生成树的话就改'<' 为  '>' 
}
int gf(int x){
	if(x==fa[x])return x;return fa[x]=gf(fa[x]);
}
bool check(int l,int r){
	l=gf(l);r=gf(r);
	if(l==r) return false;
	fa[l]=fa[r];
	return true;
}
int main(){
	scanf("%d%d",&n,&m);// n个点，m条边
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].d);
	sort(a+1,a+1+m,cmp); 
	num=0;
	for(int i=1;i<=m;i++)
	if(check(a[i].l,a[i].r)){
		num++;
		/* 
		//ans1,ans2看需求是否记录 
		ans1+=a[i].d;	//记录最小生成树的所有边的权值和 
		ans2=max(ans2,a[i].d);	//记录最小生成树的最大边的值，也就是最后加入的边的权值大小 
		*/
		if(num==n-1) break;
	}
	//最小生成树就建好了 
}
