//一维树状数组
//计算节点的父节点
int lowbit(int x){
	return x&(-x);
}

//单点修改
void add(int i,int x){
	while(i<=n){
		bit[i]+=x;
		i-=lowbit(i);
	}
}
void sub(int i,int x){
	while(i<=n){
		bit[i]-=x;
		i-=lowbit(i);
	}
}

//区间查询
int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=lowbit(i);
	}
}
int qury(int x,int y){
	return sum(y)-sum(x-1);
}

//区间修改 单点查询
//差分 记录数组中每个元素与前一个元素的差
void add(int i,int x){
	while(i<=n){
		bit[i]+=x;
		i+=lowbit(i);
	}
}
void range_add(int l,int r,int x){
	add(l,x);
	add(r+1,-x);
}
int qury(int x){
	int ans=0;
	while(x){
		ans+=bit[i];
		i-=lowbit(i);
	}
	return ans;
}

//区间修改 区间查询
void add(int i,int x){
	while(i<=n){
		bit1[i]+=x;
		bit2[i]+=i*x;
		i+=lowbit(i);
	}
}
void range_add(int l,int r,int x){
	add(l,x);add(r+1,-x);
}
int qury(int x){
	int ans=0;
	while(x){
		ans+=(x+1)*bit1[i]-bit2[i];
		x-=lowbit(x);
	}
	return ans;
}
int range_qury(int l,int r){
	return qury(r)-qury(l-1);
}

//区间求最大值/最小值
void update(int i,int val){
	while(i<=n){
		bit[i]=val;
		for(int x=1;x<lowbit(i);x<<=1){
			bit[i]=max(bit[i],bit[i-x]);
		}
		i+=lowbit(i);
	}
	return ;
}
int qury(int x,int y){
	int ans=0;
	while(x<=y){
		ans=max(ans,a[y]);
		y--;
		while(y-x>=lowbit(y)){
			ans=max(ans,bit[y]);
			y-=lowbit(y);
		}
	}
	return ans;
}


//二维树状数组
//单点修改 区间查询 
void add(int x,int y,int z){
	int val=y;
	while(x<=n){
		y=val;
		while(y<=n){
			tree[x][y]+=z;
			y+=lowbit(y);
		}
		x+=lowbit(x);
	}
}
int qury(int x,int y){
	int ans=0,val=y;
	while(x){
		y=val;
		while(y){
			ans+=tree[x][y];
			y-=lowbit(y);
		}
		x-=lowbit(x);
	}
	return ans;
}

//区间修改 单点查询 
void add(int x,int y,int z){
	int val=y;
	while(x<=n){
		y=val;
		while(y<=n){
			tree[x][y]+=z;
			y+=lowbit(y);
		}
		x+=lowbit(x);
	}
}
void range_add(int xa,int ya,int xb,int yb,int z){
	add(xa,ya,z);
	add(xa,yb+1,-z);
	add(xb+1,ya,-z);
	add(xb+1,yb+1,z);
}
int qury(int x,int y){
	int ans=0,val=y;
	while(x){
		y=val;
		while(y){
			ans+=tree[x][y];
			y-=lowbit(y);
		}
		x-=lowbit(x);
	}
	return ans;
}