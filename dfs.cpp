/*dfs*/
#include<iostream>
#include<cstdio> 
#include<cstring>
#include<algorithm>
using namespace std;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int mp[105][105];
int vis[105][105];
int n,m,x,y,sx,sy,ex,ey;
int check(int x,int y){
	if(x<0||x>n||y<0||y>m||mp[x][y]){
		return 0;
	}
	else return 1;
}
void dfs(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(check(xx,yy)&&!vis[xx][yy]){
			dfs(xx,yy);
		}
	}
}
int main(){
	memset(mp,0,sizeof(mp));
	memset(vis,0,sizeof(vis));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			if(mp[i][j]=='a'){
				sx=i;
				sy=j;
			}
			if(mp[i][j]=='b'){
				ex=i;
				ey=j;
			}
		}
	}
	dfs(sx,sy);
	return 0;
}
