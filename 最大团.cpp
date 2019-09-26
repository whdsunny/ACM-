#include<cstdio>  
#include<cstring>  
#define N 1010  
/* 
最大团 = 补图G的最大独立集数 
———>最大独立集数 = 补图G'最大团 
*/  
//最大团模板  
bool a[N][N];//a为图的邻接表(从1开始)   
int ans,cnt[N],group[N],n,m,vis[N];//ans表示最大团，cnt[N]表示当前最大团的节点数，group[N]用以寻找一个最大团集合   
bool dfs(int u,int pos){//u为当从前顶点开始深搜，pos为深搜深度（即当前深搜树所在第几层的位置）   
    int i,j;  
    for(i=u+1;i<=n;i++){//按递增顺序枚举顶点   
        if(cnt[i]+pos<=ans) return 0;//剪枝   
        if(a[u][i]){//与目前团中元素比较，取 Non-N(i)   
            for(j=0;j<pos;j++) if(!a[i][vis[j]]) break;   
            if(j==pos){// 若为空，则皆与 i 相邻，则此时将i加入到 最大团中   
                vis[pos]=i;//深搜层次也就是最大团的顶点数目，vis[pos] = i表示当前第pos小的最大团元素为i（因为是按增顺序枚举顶点 ）   
                if(dfs(i,pos+1)) return 1;      
            }      
        }  
    }      
    if(pos>ans){  
        for(i=0;i<pos;i++)  
            group[i]=vis[i]; // 更新最大团元素   
        ans=pos;  
        return 1;      
    }      
    return 0;  
}   
void maxclique(){//求最大团   
    ans=-1;  
    for(int i=n;i>0;i--)  
    {  
        vis[0]=i;  
        dfs(i,1);  
        cnt[i]=ans;  
    }  
}  
int main(){  
    //freopen("D:\in.txt","r",stdin);  
    int T;  
    //scanf("%d",&T);  
    while(~scanf("%d",&n)){  
        if(n==0) break;  
        //scanf("%d%d",&n,&m );  
        int x,y;  
        memset(a,0,sizeof(a));  
        /*for(int i = 0; i < m; i++) 
        { 
            scanf("%d%d",&x,&y); 
            a[x][y] = a[y][x] = 1; 
        }*/  
        //相邻顶点间有边相连，模型转换成求 无向图 最大独立集。   
        //要求原图的最大独立集，转化为求原图的补图的最大团(最大团顶点数量 = 补图的最大独立集)      
        for(int i=1;i<=n;i++)//求原图的补图   
            for(int j=1;j<=n;j++)  
                 scanf("%d",&a[i][j]);  
        maxclique();//求最大团   
        if(ans<0) ans=0;//ans表示最大团  
        printf("%d\n",ans);  
        /*for(int i = 0; i < ans; i++) 
            printf( i == 0 ? "%d" : " %d", group[i]);//group[N]用以寻找一个最大团集合  
        if( ans > 0 ) puts("");*/  
    }          
} 