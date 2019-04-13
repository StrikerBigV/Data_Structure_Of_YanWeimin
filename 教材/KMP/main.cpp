#include <iostream>
#include <cstdio>
using namespace std;

const int MAXSTRLEN=255;
typedef unsigned char SString[MAXSTRLEN+1];//0号位装串的长度

// 求next数组
void get_next(SString T,int next[])
{
    int i=1,j=0;
    next[1]=0;
    while(i<T[0])
    {
        if(j==0 || T[i]==T[j]){
            i++;
            j++;
            next[i]=j;
        }
        else j=next[j];
    }
}
//KMP算法
int Index_KMP(SString S,SString T,int pos)
{
    int i=pos,j=1;
    while(i<=S[0] && j<=T[0])
    {
        if(S[i]==T[i]) {i++;j++;}
        else j=next[j];
    }
    if(j>T[0]) return i-T[0];
    else return 0;
}
//改进next数组
void get_nextval(SString T,int nextval[])
{
    int i=1,j=0;
    nextval[1]=0;
    while(i<T[0])
    {
        if(j==0 || T[i]=T[j])
        {
            i++;
            j++;
            if(T[i]==T[j]) nextval[i]=j;
            else nextval[i]=nextval[j];
        }
        else j=nextval[j];
    }
}
int main()
{
    return 0;
}
