/*查询历史版本*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cctype>
#define ll long long
#define gc getchar
#define maxn 1000005
using namespace std;

inline ll read(){
    ll a=0;int f=0;char p=gc();
    while(!isdigit(p)){f|=p=='-';p=gc();}
    while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48);p=gc();}
    return f?-a:a;
}int n,m,a[maxn];

struct ahaha{
    int v,ch[2];
}t[maxn*20];int cnt,num,rt[maxn];
#define lc t[i].ch[0]
#define rc t[i].ch[1]
#define Lc t[j].ch[0]
#define Rc t[j].ch[1]
void build(int &i,int l,int r){
    i=++num;
    if(l==r){t[i].v=a[l];return;}
    int m=l+r>>1;
    build(lc,l,m);build(rc,m+1,r);
}
void update(int &i,int j,int l,int r,int k,int z){
    i=++num;lc=Lc;rc=Rc;  //����һ���ӽڵ��ʡ�ռ䣬�ӿ��ٶ�
    if(l==r){t[i].v=z;return;}
    int m=l+r>>1;
    if(k<=m)update(lc,Lc,l,m,k,z);
    else update(rc,Rc,m+1,r,k,z);
}
int query(int i,int l,int r,int k){
    if(l==r)return t[i].v;
    int m=l+r>>1;
    if(k<=m)return query(lc,l,m,k);
    return query(rc,m+1,r,k);
}

inline void solve_1(int k){
    int x=read(),z=read();
    update(rt[++cnt],rt[k],1,n,x,z);
}
inline void solve_2(int k){
    int x=read();rt[++cnt]=rt[k];
    printf("%d\n",query(rt[cnt],1,n,x));
}

int main(){
    n=read();m=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    build(rt[0],1,n);  //�Ȱѵ�0�汾����������
    while(m--){
        int k=read(),zz=read();
        switch(zz){
            case 1:solve_1(k);break;
            case 2:solve_2(k);break;
        }
    }
    return 0;
}


/*区间第k大*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cctype>
#define ll long long
#define gc getchar
#define maxn 200005
using namespace std;

inline ll read(){
    ll a=0;int f=0;char p=gc();
    while(!isdigit(p)){f|=p=='-';p=gc();}
    while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48);p=gc();}
    return f?-a:a;
}int n,m,cnt,a[maxn],b[maxn];

struct ahaha{
    int v,ch[2];
}t[maxn*20];int num,rt[maxn];
#define lc t[i].ch[0]
#define rc t[i].ch[1]
#define Lc t[j].ch[0]
#define Rc t[j].ch[1]
void update(int &i,int j,int l,int r,int k){
    i=++num;t[i]=t[j];++t[i].v;
    if(l==r)return;
    int m=l+r>>1;
    if(k<=m)update(lc,Lc,l,m,k);
    else update(rc,Rc,m+1,r,k);
}
int query(int i,int j,int l,int r,int k){
    if(l==r)return l;
    int m=l+r>>1,v=t[Lc].v-t[lc].v;
    if(k<=v)return query(lc,Lc,l,m,k);
    return query(rc,Rc,m+1,r,k-v);
}

inline void solve(){
    int x=read(),y=read(),k=read();
    printf("%d\n",b[query(rt[x-1],rt[y],1,cnt,k)]);   //别忘了要求输出的是原数，别把离散化后的值输出了
}

int main(){
    n=read();m=read();
    for(int i=1;i<=n;++i)  //先要离散化，否则没法存
        a[i]=b[i]=read();
    sort(b+1,b+n+1);cnt=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;++i)   //建n棵权值线段树
        update(rt[i],rt[i-1],1,cnt,lower_bound(b+1,b+cnt+1,a[i])-b);
    while(m--)
        solve();
    return 0;
}