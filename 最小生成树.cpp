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
	return a.d<b.d;		//����������Ļ��͸�'<' Ϊ  '>' 
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
	scanf("%d%d",&n,&m);// n���㣬m����
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].d);
	sort(a+1,a+1+m,cmp); 
	num=0;
	for(int i=1;i<=m;i++)
	if(check(a[i].l,a[i].r)){
		num++;
		/* 
		//ans1,ans2�������Ƿ��¼ 
		ans1+=a[i].d;	//��¼��С�����������бߵ�Ȩֵ�� 
		ans2=max(ans2,a[i].d);	//��¼��С�����������ߵ�ֵ��Ҳ����������ıߵ�Ȩֵ��С 
		*/
		if(num==n-1) break;
	}
	//��С�������ͽ����� 
}
