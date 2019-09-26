#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1010;
char num1[maxn],num2[maxn];
int sum[maxn];
int subtraction(char num1[],char num2[],int sum[]){
	int len,i,j;
	char *tmp;
	int num[1010];
	memset(num,0,sizeof(num));
	int len1=strlen(num1);
	int len2=strlen(num2);
	int flag=0;
	if(len1-len2<0){
		flag=1;
		tmp=num1;
		num1=num2;
		num2=tmp;
		len=len1;
		len1=len2;
		len2=len;
	}
	else if(len1==len2){
		for(i=0;i<len1;i++){
			if(num1[i]==num2[i]) continue;
			if(num1[i]>num2[i]){
				flag=0;
				break;
			}
			else {
				flag=1;
				tmp=num1;
				num1=num2;
				num2=tmp;
				break;
			}
		}
	}
	len=len1>len2?len1:len2;
	for(i=len1-1,j=0;i>=0;i--,j++){
		sum[i]=num1[i]-'0';
	}
	for(i=len2-1,j=0;i>=0;i--,j++){
		num[i]=num2[i]-'0';
	}
	for(i=0;i<=len;i++){
		sum[i]=sum[i]-num[i];
		if(sum[i]<0){
			sum[i]+=10;
			sum[i+1]--;
		}
	}
	for(i=len-1;i>=0&&sum[i]==0;i--)
		;
	len=i+1;
	if(flag==1){
		sum[len]=-1;
		len++;
	}
	return len;
}
int main(){
	int len,i;
	int sum[maxn];
	memset(sum,0,sizeof(sum));
	cin>>num1>>num2;
	len=subtraction(num1,num2,sum);
	if(sum[i=len-1]<0){
		printf("-");
		i--;
	}
	for(;i>=0;i--){
		printf("%d",sum[i]);
	}
	printf("\n");
	return 0;
}
