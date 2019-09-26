#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1010;
char num1[maxn],num2[maxn];
int a[maxn],b[maxn],c[maxn];
int substract(int *p1,int *p2,int len1,int len2){
	if(len1<len2) return -1;
	if(len1==len2){
		for(int i=len1-1;i>=0;i--){
			if(p1[i]>p2[i]) break;
			else if(p1[i]<p2[i]) return -1;
		}
	}
	for(int i=0;i<=len1-1;i++){
		p1[i]-=p2[i];
		if(p1[i]<0){
			p1[i]+=10;
			p1[i+1]--;
		}
	}
	for(int i=len1-1;i>=0;i--){
		if(p1[i]){
			int ans=i;
			return (ans+1);
		}
	}
	return 0;
}
int main(){
	int len,i,j;
	int sum[maxn*2];
	memset(sum,0,sizeof(sum));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	cin>>num1>>num2;
	int len1=strlen(num1);
	int len2=strlen(num2);
	for(i=len1-1,j=0;i>=0;i--,j++){
		a[j]=num1[i]-'0';
	}
	for(i=len2-1,j=0;i>=0;i--,j++){
		b[j]=num2[i]-'0';
	}
	if(len1-len2<0) printf("0\n");
	int cnt=len1-len2;
	for(i=len1-1;i>=0;i--){
		if(i>=cnt) b[i]=b[i-cnt];
		else b[i]=0;
	}
	len2=len1;
	int tmp;
	for(j=0;j<=cnt;j++){
		while((tmp=substract(a,b+j,len1,len2-j))>=0){
			len1=tmp;
			c[cnt-j]++;
		}
	}
	for(i=maxn-1;c[i]==0&&i>=0;i--)
		;
	if(i>=0) for(;i>=0;i--) printf("%d",c[i]);
	else printf("0");
	printf("\n");
	return 0;
}
