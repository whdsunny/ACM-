/*²¢²é¼¯*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int bin[1010];
int n,m,x,y;
int find(int x){
	if(bin[x]==x)return x;return bin[x]=find(bin[x]);
}
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy) bin[fx]=fy;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		bin[i]=i;
	}
	while(m--){
		cin>>x>>y;
		merge(x,y);
	}
	int count=0;
	for(int i=1;i<=n;i++){
		if(i==bin[i]) count++;
	}
	cout<<count<<endl;
	return 0;
}
