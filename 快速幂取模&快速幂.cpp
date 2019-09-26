//快速幂取模
long long Mode(long long a, long long b, long long mode)
{
	long long sum = 1;
	while (b) {
		if (b & 1) {
			sum = (sum * a) % mode;
			b--;
		}
		b /= 2;
		a = a * a % mode;
	}
	return sum;
}

//快速幂
typedef long long ll;  
ll pow(ll x,ll n,ll mod)  
{  
    ll res=1;  
    while(n>0)  
    {  
       if(n%2==1)     
       {  
         res=res*x;  
       }  
       x=x*x;   
       n>>=1;  
    }  
    return res;   
}  