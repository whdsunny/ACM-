1/*.��άƫ��
����һ��N��Ԫ�ص�����a����ʼֵȫ��Ϊ0����������н����������ֲ���?
����1����ʽ1 x k����λ��x��Ԫ�ؼ���k?
����2����ʽΪ2 x y���������[x,y]������Ԫ�صĺ�*/
#include<cstdio>
#include<cstring>
#include<iostream>
#define ll long long

using namespace std;

const int N=5000010;
int n,m,totx=0,tot=0;     //totx�ǲ����ĸ���,totѯ�ʵı�� 

struct node{
    int type,id;
    ll val;
    bool operator < (const node &a) const   //���������,����ʱ������ 
    {
        if (id!=a.id) return id<a.id;
        else return type<a.type;
    }
};
node A[N],B[N];
ll ans[N];

void CDQ(int L,int R)
{
    if (L==R) return;
    int M=(L+R)>>1;
    CDQ(L,M);
    CDQ(M+1,R);
    int t1=L,t2=M+1;
    ll sum=0; 
    for (int i=L;i<=R;i++)
    {
        if ((t1<=M&&A[t1]<A[t2])||t2>R) //ֻ�޸���������ڵ��޸�ֵ
        {
            if (A[t1].type==1) sum+=A[t1].val;   //sum���޸ĵ���ֵ
            B[i]=A[t1++]; 
        }
        else                         //ֻͳ���ұ������ڵĲ�ѯ���
        {
            if (A[t2].type==3) ans[A[t2].val]+=sum;
            else if (A[t2].type==2) ans[A[t2].val]-=sum;
            B[i]=A[t2++];
        }
    }
    for (int i=L;i<=R;i++) A[i]=B[i];
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        tot++;
        A[tot].type=1; A[tot].id=i;            //�޸Ĳ��� 
        scanf("%lld",&A[tot].val);
    }
    for (int i=1;i<=m;i++)
    {
        int t;
        scanf("%d",&t);
        tot++;
        A[tot].type=t; 
        if (t==1)
            scanf("%d%lld",&A[tot].id,&A[tot].val);
        else
        {
            int l,r;
            scanf("%d%d",&l,&r);
            totx++; 
            A[tot].val=totx; A[tot].id=l-1;    //ѯ�ʵ�ǰһ��λ�� 
            tot++; A[tot].type=3; A[tot].val=totx; A[tot].id=r;  //ѯ�ʵĺ�˵� 
        }
    }
    CDQ(1,tot);
    for (int i=1;i<=totx;i++) printf("%lld\n",ans[i]);
    return 0;
}

/*2.��άƫ��
ƽ������N���㣬ÿ����ĺ���������[0,1e7]֮�䣬��M��ѯ�ʣ�ÿ��ѯ��Ϊ��ѯ��ָ������֮���ж��ٸ��㣬������(x1,y1,x2,y2)�ķ�ʽ����������(x1,y1)Ϊ���½����꣬(x2,y2)Ϊ���Ͻ�����*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=200005;
int w,n,ans[N];
struct node{
    int bh,t,xa,ya,xb,yb,z;  //����ʹ��y1 
};
node q[N],c[N<<1]; 
int cc,tree[500005];

int cmp(const node &a,const node &b)
{
    if (a.xa==b.xa) return a.t<b.t;   //��������ѯ��ǰ 
    return a.xa<b.xa;    
}

void add(int bh,int a)
{
    for (int i=bh;i<=w;i+=(i&(-i)))
        tree[i]+=a;
}

int ask(int bh)
{
    int ans=0;
    for (int i=bh;i>0;i-=(i&(-i)))
        ans+=tree[i];
    return ans;
}

void solve(int l,int r)
{
    if (l==r) return;
    int mid=(l+r)>>1;
    cc=0;
    for (int i=l;i<=mid;i++)
        if (q[i].t==0)
           c[cc++]=q[i];
    for (int i=mid+1;i<=r;i++)
        if (q[i].t)
        {
            c[cc++]=q[i];
            c[cc++]=q[i];
            c[cc-2].xa--;
            c[cc-1].xa=c[cc-1].xb;
            c[cc-1].t=2;
        }
    sort(c,c+cc,cmp);
    for (int i=0;i<cc;i++)
    {
        if (c[i].t==0)  //���� 
            add(c[i].ya,c[i].z);
        else if (c[i].t==1)
            ans[c[i].bh]-=ask(c[i].yb)-ask(c[i].ya-1);
        else
            ans[c[i].bh]+=ask(c[i].yb)-ask(c[i].ya-1);
    }
    for (int i=0;i<cc;i++)
        if (c[i].t==0)
            add(c[i].ya,-c[i].z);
    solve(l,mid);
    solve(mid+1,r);
}

int main()
{
    freopen("locust.in","r",stdin);
    freopen("locust.out","w",stdout);
    scanf("%d%d",&w,&n);
    for (int i=1;i<=n;i++)
    {
        int x,y,xx,yy;
        q[i].bh=i;
        scanf("%d",&q[i].t);  
        q[i].t--;
        if (q[i].t==0)  //���� 
        {
            scanf("%d%d%d",&q[i].xa,&q[i].ya,&q[i].z);
        }
        else  //��ѯ 
        {
            scanf("%d%d%d%d",&x,&y,&xx,&yy);
            q[i].xa=min(x,xx);
            q[i].xb=max(x,xx);
            q[i].ya=min(y,yy);
            q[i].yb=max(y,yy);
        }
    }
    solve(1,n);
    for (int i=1;i<=n;i++)
        if (q[i].t)
           printf("%d\n",ans[i]);
    return 0;
}

/*3.��Ԫ��*/
//����д����Ƭ
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long

using namespace std;

const int N=200010;
struct node{
    int a,b,c,num;
};
node po[N];
int n,m,t[N],ans[N];

void add(int x,int z) {for (int i=x;i<=n;i+=(i&(-i))) t[i]+=z;}
int ask(int x) {int ans=0; for (int i=x;i>0;i-=(i&(-i))) ans+=t[i]; return ans;}

int cmp0(const node &A,const node &B) {return A.a<B.a;}
int cmp(const node &A,const node &B) {return A.b<B.b;}

void CDQ(int L,int R)
{
    if (L==R) return;
    int M=(L+R)>>1;
    CDQ(L,M); CDQ(M+1,R);

    sort(po+L,po+R+1,cmp);                 //��b���� 

    for (int i=L;i<=R;i++)
    {
        if (po[i].a<=M) add(po[i].c,1);    //��һά����ѡ�����a,������������ķָ��־����a 
        else ans[po[i].a]+=ask(po[i].c);
    }
    for (int i=L;i<=R;i++)
        if (po[i].a<=M) add(po[i].c,-1);
}

int main()
{
    scanf("%d",&n);
    int x;
    for (int i=1;i<=n;i++) {
        scanf("%d",&x);
        po[x].a=i;
    }
    for (int i=1;i<=n;i++) {
        scanf("%d",&x);
        po[x].b=i;
    }
    for (int i=1;i<=n;i++) {
        scanf("%d",&x);
        po[x].c=i;
    }

    sort(po+1,po+1+n,cmp0);    //��a���� 
    CDQ(1,n);

    ll Ans=0;
    for (int i=1;i<=n;i++) Ans+=(ll)ans[i];
    printf("%lld",Ans);
    return 0;
}

