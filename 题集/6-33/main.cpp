#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int maxn=110;
int n;
typedef struct{
    int L[maxn];
    int R[maxn];
    int num;
}BiTree;

bool IsChild(BiTree T,int u,int v){
    if(u==v) return true;
    if(T.L[v]==0){
        if(T.R[v]==0) return false;
        else{
            if(IsChild(T,u,T.R[v])) return true;
            else return false;
        }
    }
    else{
        if(IsChild(T,u,T.L[v])) return true;
        else{
            if(T.R[v]==0) return false;
            else{
                if(IsChild(T,u,T.R[v])) return true;
                else return false;
            }
        }
    }
}

int main()
{
    int u,v;
    scanf("%d",&n);
    getchar();
    BiTree T;
    T.num=0;
    for(int i=0;i<n;i++)
        {scanf("%d%d",&T.L[i],&T.R[i]);T.num++;}
    getchar();
    scanf("%d%d",&u,&v);
    if(IsChild(T,u,v)) printf("True!");
    else printf("False!");
    return 0;
}
