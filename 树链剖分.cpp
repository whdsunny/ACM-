#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn=4e5+10;
int n,q,s,sz=0,c,x,op,k=0;
int u[maxn],v[maxn],sum[maxn],son[maxn],deep[maxn],fa[maxn],pl[maxn],dfn[maxn],top[maxn],fir[maxn];
ll w[maxn],a[maxn],tr[maxn],ans,b;

struct node{
	int r,nx;
	ll w;
}kk[maxn];

void add(int l,int r,ll w){
	k++;
	kk[k].r=r;kk[k].nx=fir[l];fir[l]=k;kk[k].w=w;
}

void dfs1(int x,int f){
	sum[x]=1;son[x]=0;
	for(int i=fir[x];i!=-1;i=kk[i].nx){
		if(f==kk[i].r) continue;
		deep[kk[i].r]=deep[x]+1;
		fa[kk[i].r]=x;
		a[kk[i].r]=kk[i].w; 
		dfs1(kk[i].r,x);
		if(sum[kk[i].r]>sum[son[x]]) son[x]=kk[i].r;
		sum[x]+=sum[kk[i].r];
	}
}

void dfs2(int x,int tp){
	pl[x]=++sz;dfn[sz]=x;top[x]=tp;
	if(son[x]) dfs2(son[x],tp);
	for(int i=fir[x];i!=-1;i=kk[i].nx){
		if(kk[i].r!=fa[x] && kk[i].r!=son[x])
			dfs2(kk[i].r,kk[i].r);
	}
}

void build(int p,int l,int r){
	if(l==r){
		tr[p]=a[dfn[l]];
		return;
	}
	int mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	tr[p]=tr[p*2]+tr[p*2+1];
}

void change(int p,int l,int r,int x,ll w){
	if(l>pl[x] || pl[x]>r){
		return;
	}
	if(l==r && l==pl[x]){
		tr[p]=w;
	//	cout<<l<<" "<<r<<" "<<tr[p]<<endl;
		return;
	}
	int mid=(l+r)/2;
	change(p*2,l,mid,x,w);
	change(p*2+1,mid+1,r,x,w);
	tr[p]=tr[p*2]+tr[p*2+1];
}

ll query(int p,int l,int r,int x,int y){
	if(r<x || y<l){
		return 0;
	}
	if(x<=l && r<=y){
		return tr[p];
	}
	int mid=(l+r)/2;
	return query(p*2,l,mid,x,y)+query(p*2+1,mid+1,r,x,y);
}

void work(int v,int u){
	int f1=top[v],f2=top[u];
	while(f1!=f2){
		if(deep[f1]<deep[f2]){
			swap(f1,f2);
			swap(u,v); 
		} 
		ans+=query(1,1,sz,pl[f1],pl[v]);
		v=fa[f1];f1=top[v];
	}
	if(pl[v]>pl[u]) swap(u,v);
	ans+=query(1,1,sz,pl[v],pl[u]);
	ans-=query(1,1,sz,pl[v],pl[v]);
} 

int main(){
	memset(fir,-1,sizeof(fir));
	scanf("%d%d%d",&n,&q,&s);
	for(int i=1;i<n;i++){
		scanf("%d%d%lld",&u[i],&v[i],&w[i]);
		add(u[i],v[i],w[i]);
		add(v[i],u[i],w[i]);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,sz);
	while(q--){
		scanf("%d",&op);
		ans=0;
		if(op==0){
			scanf("%d",&x);
			work(s,x);
			printf("%lld\n",ans);
			s=x;
		}
		if(op==1){
			scanf("%d%lld",&c,&b);
		//	c++;
			if(fa[u[c]]==v[c]) change(1,1,sz,u[c],b);
			else change(1,1,sz,v[c],b);
		}
	}
	return 0;
} 