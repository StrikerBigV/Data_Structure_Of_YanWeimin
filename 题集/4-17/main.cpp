#include <iostream>
#include <cstdio>
using namespace std;

const int MAXSTRLEN=255;
typedef unsigned char SString[MAXSTRLEN+1];

void Replace(SString &S,SString T,SString V)
{
    int i,j,k;
    for(i=1;i<=S[0];i++)
    {
        for(j=i,k=1;k<=T[0] && S[i]==T[k];k++,j++);//寻找与T相等的子串
        if(k>T[0]){//如果找到
            if(T[0]==V[0]){//如果T与V长度相等，则直接替换
                for(int l=1;l<=T[0];l++)
                    S[i+l-1]=V[l];
            }
            else if(T[0]<V[0]){//如果T比V短，则T后的元素往右移，再把中间的部分用V填满
                for(int l=S[0];l>=i+T[0];i--)
                    S[l+V[0]-T[0]]=S[l];
                for(int l=1;l<=V[0];l++)
                    S[i+l-1]=V[l];
            }
            else{//如果T比V长，则T后的元素往左移，再把中间的部分用V填满
                for(int l=i+V[0];l<=S[0];i++)
                    S[l]=S[l+V[0]-T[0]];
                for(int l=1;l<=V[0];l++)
                    S[i+l-1]=V[l];
            }
        }
    }
}
int main()
{
    //int lens,lent,lenv;
    SString S,T,V;
    S[0]=3;
    S[1]='a';
    S[2]='b';
    S[3]='c';
    T[0]=1;
    T[1]='b';
    V[0]=1;
    V[1]='c';
    printf("%d,%d",(int)T[0],(int)V[0]);
    Replace(S,T,V);
    for(int i=1;i<=3;i++)
        printf("%c",S[i]);
    return 0;
}
