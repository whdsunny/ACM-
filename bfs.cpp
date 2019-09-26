/*bfs*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m,ex,ey,sx,sy;
int mp[105][105];
int vis[105][105];
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
struct node{
	int x,y;
	int step;
};
queue<node>Q;
bool check(node next){
	if(next.x<0||next.x>n||next.y<0||next.y>m||mp[next.x][next.y]){
		return false;
	}
	return true;
}
int bfs(int x,int y){
	node st;
	st.x=x;
	st.y=y;
	st.step=0;
	vis[st.x][st.y]=1;
	while(!Q.empty()) Q.pop();
	Q.push(st);
	while(!Q.empty()){
		node now=Q.front();
		Q.pop();
		if(now.x==ex&&now.y==ey){
			return now.step;
			break;
		}
		for(int i=0;i<4;i++){
			node next;
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			if(check(next)&&!vis[next.x][next.y]){
				next.step=now.step+1;
				vis[next.x][next.y]=1;
				Q.push(next);
			}
		}
	}
}
int main(){
	cin>>n>>m;
	memset(mp,0,sizeof(mp));
	memset(vis,0,sizeof(vis));
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
	int ans=bfs(sx,sy);
	printf("%d\n",ans);
	return 0;
}
