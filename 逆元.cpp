//逆元板子
//费马小定理
//复杂度 O(logn)
typedef long long ll;
const int mod=1000000009;
ll pw(ll a,ll b) {
    if(b<0) return 0;
    ll ret=1;
    a%=mod;
    while(b){
        if(b&1) ret=(ret*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ret;
}
ll inv(ll a) {
    return pw(a,mod-2);
}
//C(n,r)%p的值,其中p是大质数(如1e9+7)
//C(n,r)=n!*(r!*(n-r)!)^(p-2)%p
typedef long long ll;
const int mod=;
ll pw(ll a,ll b){
    if(b<0) return 0;
    ll ret=1;
    a%=mod;
    while(b){
        if(b&1) ret=(ret*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ret;
} 
ll inv(ll n,ll m){
    ll a=1,b=1;
    for(int i=2;i<=n<<1;i++)
        a=(a*i)%mod;
    for(int i=2;i<=m;i++)
        b=(b*i)%mod;
    for(int i=2;i<=n-m;i++)
        b=(b*i)%mod;
    return (a*pw(b,mod-2))%mod;
}


//扩展欧几里得算法求逆元 
//复杂度 O(logn)
typedef long long ll;
const int mod=;
void ex_gcd(ll a,ll b,ll &x,ll &y){
    if(!b){x=1;y=0;return ;}
    ex_gcd(b,a%b,y,x);
    ll t=x;x=y,y=t-(a/b)*y;
}
ll inv(ll a){
    ll x,y;
    ex_gcd(a,mod,x,y);
    x=(x%mod+mod)%mod;
    return x;
}


//逆元线性筛（P为质数)
//复杂度 O(N)
const int mod=1e9+7;
const int maxn=1e5+10;
int inv[maxn];
inv[1]=1;
for(int i=2;i<10000;i++)
    inv[i]=inv[mod%i]*(mod-mod/i)%mod;
//求阶乘的逆元（阶乘组数：fac[])
inv[maxn]=mod_pow(fac[maxn],mod-2);
for(ll i=maxn-1;i>=0;i--)
    inv[i]=(inv[i+1]*(i+1))%mod;


//逆元打表
typedef long long ll;
const int maxn=1e5+10;
int inv[maxn];
void inverse(int n,int p){
    inv[1]=1;
    for(int i=2;i<=n;i++){
        inv[i]=(ll)(p-p/i)*inv[p%i]%p;
    }
}