#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1010;
int sum[maxn];
char num1[maxn],num2[maxn];
int addition(char num1[],char num2[],int sum[]){
	int num[maxn];
	memset(num,0,sizeof(num));
	int len1=strlen(num1);
	int len2=strlen(num2);
	int len;
	len=len1>len2?len1:len2;
	for(int i=len1-1,j=0;i>=0;i--,j++){
		sum[j]=num1[i]-'0';
	} 
	for(int i=len2-1,j=0;i>=0;i--,j++){
		num[j]=num2[i]-'0';
	}
	for(int i=0;i<=len;i++){
		sum[i]+=num[i];
		if(sum[i]>9){
			sum[i]-=10;
			sum[i+1]++;	
		}
	}
	if(sum[len]!=0) len++;
	return len;
}
int main(){
	int len;
	memset(sum,0,sizeof(sum));
	cin>>num1>>num2;
	len=addition(num1,num2,sum);
	for(int i=len-1;i>=0;i--){
		printf("%d",sum[i]);
	}
	printf("\n");
	return 0;
} 
