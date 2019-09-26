#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e6+10;
ll x0,x1,a,b,mod;
char s[maxn];

struct matrix{
	ll a[2][2];
	matrix(){
		memset(a,0,sizeof(a));
	}
	matrix operator * (const matrix p) const {
		matrix res;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
					res.a[i][j]=(res.a[i][j]+p.a[i][k]*a[k][j]%mod)%mod;
				}
			}
		}
		return res;
	}
}r,mat;

void init(){
	r.a[0][0]=a;r.a[0][1]=b;
	r.a[1][0]=1;r.a[1][1]=0;
	mat.a[0][0]=x1;
	mat.a[1][0]=x0;
}

matrix qpow(matrix r,ll p){
	matrix res;
	res.a[0][0]=res.a[1][1]=1;
	while(p){
		if(p&1) res=r*res;
		r=r*r;
		p>>=1;
	}
	return res;
}

matrix matpow(matrix r){
	matrix res;
	res.a[0][0]=res.a[1][1]=1;
	int len=strlen(s);
	for(int i=len-1;i>=0;i--){
		int t=s[i]-'0';
		res=res*qpow(r,t);
		r=qpow(r,10);
	}
	return res;
}

int main(){
	scanf("%lld%lld%lld%lld",&x0,&x1,&a,&b);
	scanf("%s",s);
	scanf("%lld",&mod);
	x0%=mod;x1%=mod;a%=mod;b%=mod;
	init();
	matrix ans=mat*matpow(r);
	printf("%lld\n",ans.a[1][0]%mod);
	return 0;
}