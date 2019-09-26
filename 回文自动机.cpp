struct Palindromic_Tree{
	int nxt[maxn][26];
	int fail[maxn];
	int cnt[maxn];
	int num[maxn];
	int len[maxn];
	int S[maxn];
	int last,n,p;
	
	int newnode(int l){
		for(int i=0;i<26;i++) nxt[p][i]=0;
		cnt[p]=0;
		num[p]=0;
		len[p]=l;
		return p++;
	}
	
	void init(){
		p=0;
		newnode(0);
		newnode(-1);
		last=0;
		n=0;
		S[n]=-1;
		fail[0]=1;
	}
	
	int get_fail(int x){
		while(S[n-len[x]-1]!=S[n]) x=fail[x];
		return x;
	}
	
	void add(int c){
		c-='a';
		S[++n]=c;
		int cur=get_fail(last);
		if(!nxt[cur][c]){
			int now=newnode(len[cur]+2);
			fail[now]=nxt[get_fail(fail[cur])][c];
			nxt[cur][c]=now;
			num[now]=num[fail[now]]+1;
		}
		last=nxt[cur][c];
		cnt[last]++;
	}
	
	void count(){
		for(int i=p-1;i>=2;i--) cnt[fail[i]]+=cnt[i];
	}
}T;