//线性筛法求解莫比乌斯函数
int a[maxn],prime[maxn],mu[maxn];
void Moblus(int n){
    for(int i=2;i<=n;i++){
        if(a[i]==0){
            prime[tot++]=i;
            mu[i]=-1;
        }
        for(int j=0;j<tot;j++){
            if(i*prime[j]>n) break;
            a[i*prime[j]]=1;
            if(i%prime[j]==0){
                mu[i*prime[j]]=0;
                break;
            }
            else mu[i*prime[j]]=-mu[i];
        }
    }
}

//线性筛
int a[maxn],prime[maxn];
void init(int n){
    for(int i=2;i<=n;i++){
        if(a[i]==0) prime[++cnt]=i;
        for(int j=1;j<=cnt;j++){
            if(i*prime[j]>n) break;
            a[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}

//埃式筛
int a[maxn],prime[maxn];
void init(int n){
    for(int i=2;i<=n;i++){
        if(a[i]==0) prime[++cnt]=i;
        for(int j=i*2;j<=n;j+=i) a[j]=1;
    }
}