//1.查询是否出现过
/*
  trie tree的储存方式：将字母储存在边上，边的节点连接与它相连的字母 
  trie[rt][x]=tot:rt是上个节点编号，x是字母，tot是下个节点编号 
*/ 
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int maxn=2e6+10;
int tot=1,n;
int trie[maxn][26];
//bool isw[maxn];查询整个单词用
void insert(char *s,int rt){
    for(int i=0;s[i];i++){
        int x=s[i]-'a';
        if(trie[rt][x]==0){//现在插入的字母在之前同一节点处未出现过 
            trie[rt][x]=++tot;//字母插入一个新的位置，否则不做处理 
        }
        rt=trie[rt][x];//为下个字母的插入做准备  
    }
    /*isw[rt]=true;标志该单词末位字母的尾结点，在查询整个单词时用到*/
}
bool find(char *s,int rt){
    for(int i=0;s[i];i++){
        int x=s[i]-'a';
        if(trie[rt][x]==0) return false;//以rt为头结点的x字母不存在，返回0 
        rt=trie[rt][x];//为查询下个字母做准备 
    }
    return true;
    //查询整个单词时，应该return isw[rt] 
}
char s[22];
int main(){
    tot=0;
    int rt=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>s;
        insert(s,rt);
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>s;
        if(find(s,rt)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


//2.查询前缀出现次数
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int trie[400001][26],len,root,tot,sum[400001];
bool p;
int n,m; 
char s[11];
void insert(){
    len=strlen(s);
    root=0;
    for(int i=0;i<len;i++){
        int id=s[i]-'a';
        if(!trie[root][id]) trie[root][id]=++tot;
        sum[trie[root][id]]++;//前缀后移一个位置保存 
        root=trie[root][id];
    }
}
int search(){
    root=0;
    len=strlen(s);
    for(int i=0;i<len;i++){
        int id=s[i]-'a';
        if(!trie[root][id]) return 0;
        root=trie[root][id];
    }//root经过此循环后变成前缀最后一个字母所在位置的后一个位置 
    return sum[root];//因为前缀后移了一个保存，所以此时的sum[root]就是要求的前缀出现的次数 
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>s;
        insert();
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        cin>s;
        printf("%d\n",search());
    }
    return 0;
}


