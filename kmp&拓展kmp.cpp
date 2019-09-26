//kmp
/*
这个模板 字符串是从0开始的
nx数组是从1开始的
*/
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=1e6+10;
int nx[maxn];
char S[maxn],T[maxn];
int slen,tlen;

void getnx(){
    int j=0,k=-1;
    nx[0]=-1;
    while(j<tlen){
        if(k==-1 || T[j]==T[k]) nx[++j]=++k;
        else k=nx[k];
    }
}
/*
返回模式串T在主串S中首次出现的位置
返回的位置是从0开始的。
*/
int KMP_Index(){
    int i=0,j=0;
    getnx();
    while(i<slen && j<tlen){
        if(j==-1 || S[i]==T[j]){
            i++;j++;
        }
        else j=nx[j];
    }
    if(j==tlen) return i-tlen;
    else return -1;
}
/*
返回模式串在主串S中出现的次数
*/
int KMP_Count(){
    int ans=0,j=0;
    if(slen==1&&tlen==1){
        if(S[0]==T[0]) return 1;
        else return 0;
    }
    getnx();
    for(int i=0;i<slen;i++) {
        while(j>0 && S[i]!=T[j]) j = nx[j];
        if(S[i]==T[j]) j++;
        if(j==tlen){
            ans++;
            j=nx[j];
        }
    }
    return ans;
}

int main(){    
    int TT;
    int i,cc;
    cin>>TT;
    while(TT--){
        cin>>S>>T;
        slen=strlen(S);
        tlen=strlen(T);
        cout<<"模式串T在主串S中首次出现的位置是: "<<KMP_Index()<<endl;
        cout<<"模式串T在主串S中出现的次数为: "<<KMP_Count()<<endl;
    }
    return 0;
}







/*拓展kmp*/
const int maxn=100010;   //字符串长度最大值
int next[maxn],ex[maxn]; //ex数组即为extend数组
//预处理计算next数组
void GETNEXT(char *str){
    int i=0,j,po,len=strlen(str);
    next[0]=len;//初始化next[0]
    while(str[i]==str[i+1]&&i+1<len)//计算next[1]
    i++;
    next[1]=i;
    po=1;//初始化po的位置
    for(i=2;i<len;i++){
        if(next[i-po]+i<next[po]+po)//第一种情况，可以直接得到next[i]的值
        next[i]=next[i-po];
        else{//第二种情况，要继续匹配才能得到next[i]的值
            j=next[po]+po-i;
            if(j<0)j=0;//如果i>po+next[po],则要从头开始匹配
            while(i+j<len&&str[j]==str[j+i])//计算next[i]
            j++;
            next[i]=j;
            po=i;//更新po的位置
        }
    }
}
//计算extend数组
void EXKMP(char *s1,char *s2){
    int i=0,j,po,len=strlen(s1),l2=strlen(s2);
    GETNEXT(s2);//计算子串的next数组
    while(s1[i]==s2[i]&&i<l2&&i<len)//计算ex[0]
    i++;
    ex[0]=i;
    po=0;//初始化po的位置
    for(i=1;i<len;i++){
        if(next[i-po]+i<ex[po]+po)//第一种情况，直接可以得到ex[i]的值
        ex[i]=next[i-po];
        else{//第二种情况，要继续匹配才能得到ex[i]的值
            j=ex[po]+po-i;
            if(j<0)j=0;//如果i>ex[po]+po则要从头开始匹配
            while(i+j<len&&j<l2&&s1[j+i]==s2[j])//计算ex[i]
            j++;
            ex[i]=j;
            po=i;//更新po的位置
        }
    }
}
