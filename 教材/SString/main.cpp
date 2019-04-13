#include <iostream>
#include <cstdio>
using namespace std;

const int MAXSTRLEN=255;
typedef unsigned char SString[MAXSTRLEN+1];//0号位装串的长度

// 字符拼接
void Concat(SString &T,SString S1,SString S2)
{
    if(S1[0]+S2[0]<=MAXSTRLEN){
        T[0]=S1[0]+S2[0];
        for(int i=1;i<S1[0];i++)
            T[i]=S1[i];
        for(int i=S1[0];i<T[0];i++)
            T[i]=S2[i-S1[0]];
    }
    else if(S1[0]<MAXSTRLEN){//截断
        T[0]=MAXSTRLEN;
        for(int i=1;i<=S1[0];i++)
            T[i]=S1[i];
        for(int i=S1[0];i<=MAXSTRLEN;i++)
            T[i]=S2[i-S1[0]];
    }
    else{//只有第一个字符串
        T[0]=MAXSTRLEN;
        for(int i=1;i<=MAXSTRLEN;i++)
            T[i]=S1[i];
    }
}

//返回子串
bool SubString(SString &T,SString S,int pos,int len)
{
    if(pos<0 || pos>S[0] || len<0 || pos+len>S[0]+1) return false;
    else{
        T[0]=len;
        for(int i=1;i<=len;i++)
            T[i]=S[pos+i-1];
        return true;
    }
}

//早期模式匹配算法
int Index(SString S,SString T,int pos)
{//存在，则返回字串首位的位置，否则返回0
    int i=pos,j=1;
    while(i<=S[0] && j<=T[0])
    {
        if(S[i]==T[i]) {i++;j++}
        else{
            i=i-j+2;
            j=1;
        }
    }
    if(j>T[0]) return i-T[0];
    else return 0;
}

int main()
{
    return 0;
}
