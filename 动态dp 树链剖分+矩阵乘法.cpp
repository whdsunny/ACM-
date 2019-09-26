#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
inline int read ()
{
    int w=1,s=0;
    char ch=getchar ();
    while (ch<'0'||ch>'9'){if (ch=='-') w=-1;ch=getchar ();}
    while ('0'<=ch&&ch<='9') s=(s<<1)+(s<<3)+(ch^48),ch=getchar ();
    return s*w;
}
struct Matrix{
    int a[3][3];
    Matrix (){memset (a,0,sizeof (a));}
    Matrix operator * (const Matrix &rhs) const
    {
        Matrix c;
        for (int i=1;i<=2;i++)
            for (int j=1;j<=2;j++)
                for (int k=1;k<=2;k++)
                    c.a[i][j]=max (c.a[i][j],a[i][k]+rhs.a[k][j]);
        return c;
    }
}val[MAXN];
struct SEG{
    int l,r;Matrix v;
}tr[MAXN<<2];
struct edge{
    int v,nxt;
}e[MAXN<<1];
int n,m,cnt,tot;
int p[MAXN],head[MAXN],f[MAXN][2];
int fa[MAXN],top[MAXN],bot[MAXN],dfn[MAXN],id[MAXN],size[MAXN],son[MAXN];
void add (int u,int v)
{
    e[++cnt].v=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
void dfs1 (int u,int ff)
{
    fa[u]=ff;size[u]=1;
    for (int i=head[u];i!=0;i=e[i].nxt)
        if (e[i].v!=ff)
        {
            dfs1 (e[i].v,u);
            f[u][0]+=max (f[e[i].v][0],f[e[i].v][1]);
            f[u][1]+=f[e[i].v][0];
            size[u]+=size[e[i].v];
            if (size[e[i].v]>size[son[u]]) son[u]=e[i].v;
        }
    f[u][1]+=p[u];
}
void dfs2 (int u,int topf)
{
    top[u]=topf;bot[u]=u;id[u]=++tot;dfn[tot]=u;
    if (son[u]) dfs2 (son[u],topf),bot[u]=bot[son[u]];
    for (int i=head[u];i!=0;i=e[i].nxt)
        if (!id[e[i].v])
            dfs2 (e[i].v,e[i].v);
}
void update (int rt)
{
    tr[rt].v=tr[rt<<1].v*tr[rt<<1|1].v;
}
void build (int rt,int l,int r)
{
    tr[rt].l=l,tr[rt].r=r;
    if (l==r)
    {
        int u=dfn[l],f0=0,f1=p[u];
        for (int i=head[u];i!=0;i=e[i].nxt)
            if (son[u]!=e[i].v&&fa[u]!=e[i].v)
            {
                f0+=max (f[e[i].v][0],f[e[i].v][1]);
                f1+=f[e[i].v][0];
            }
        tr[rt].v.a[1][1]=tr[rt].v.a[1][2]=f0;
        tr[rt].v.a[2][1]=f1;
        val[l]=tr[rt].v;
        return;
    }
    int mid=(l+r)>>1;
    build (rt<<1,l,mid);build (rt<<1|1,mid+1,r);
    update (rt);
}
Matrix query (int rt,int l,int r)
{
    if (l<=tr[rt].l&&tr[rt].r<=r) return tr[rt].v;
    int mid=(tr[rt].l+tr[rt].r)>>1;
    if (r<=mid) return query (rt<<1,l,r);
    if (mid<l) return query (rt<<1|1,l,r);
    else return query (rt<<1,l,r)*query (rt<<1|1,l,r);
}
void modify (int rt,int pos)
{
    if (tr[rt].l==tr[rt].r)
    {
        tr[rt].v=val[tr[rt].l];
        return;
    }
    int mid=(tr[rt].l+tr[rt].r)>>1;
    if (pos<=mid) modify (rt<<1,pos);
    else modify (rt<<1|1,pos);
    update (rt);
}
void Modify (int u,int v)
{
    val[id[u]].a[2][1]+=v-p[u];p[u]=v;
    Matrix pre,nw;
    while (u)
    {
        pre=query (1,id[top[u]],id[bot[u]]);
        modify (1,id[u]);
        nw=query (1,id[top[u]],id[bot[u]]);
        u=fa[top[u]];
        val[id[u]].a[1][1]+=max (nw.a[1][1],nw.a[2][1])-max (pre.a[1][1],pre.a[2][1]);
        val[id[u]].a[1][2]=val[id[u]].a[1][1];
        val[id[u]].a[2][1]+=nw.a[1][1]-pre.a[1][1];
    }
}
int main()
{
    n=read ();m=read ();
    for (int i=1;i<=n;i++) p[i]=read ();
    for (int i=1;i<n;i++)
    {
        int u=read (),v=read ();
        add (u,v);add (v,u);
    }
    dfs1 (1,0);dfs2 (1,1);build (1,1,n);
    while (m--)
    {
        int x=read (),y=read ();
        Modify (x,y);
        Matrix ans=query (1,id[top[1]],id[bot[1]]);
        printf ("%d\n",max (ans.a[1][1],ans.a[2][1]));
    }
    return 0;
}