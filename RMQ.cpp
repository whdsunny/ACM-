//RMQ 区间最值在线查询 

//预处理 O(nlogn)
void rmq_init(){
    for(int i=1;i<=n;i++){
        dp[i][0]=arr[i];
    }
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<j-1)][j-1]);
        }
    }
}

//查询 O(1)
int rmq(int l,int r){
    int k=log2(r-l+1);
    return min(dp[l][k],dp[r-(1<<k)+1][k]);
}