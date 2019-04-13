#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int LIST_INIT_SIZE=100;
const int LISTINCREMENT=10;

typedef struct{
    int *elem;
    int length;
    int listsize;
}SqList;

typedef struct LNode{
    int data;
    struct LNode* next;
}LNode,*LinkList;

void InitList(SqList &L)
{
    L.elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
}

//**************************¸Ä½øËã·¨********************//
bool DeleteK(SqList &a,int i,int k)
{
    if(i<1 || k<0 || (i+k)>a.length) return false;
    else if(i+k==a.length) a.length-=k;
    else{
        for(int j=0;j<=k;j++)
        {
            a.elem[i+j]=a.elem[i+j+k];
        }
        a.length-=k;
    }
    return true;
}
int main()
{
    int n,i,k;
    scanf("%d%d%d",&n,&i,&k);
    SqList S;
    InitList(S);
    S.length=n;
    for(int j=1;j<=n;j++)
    {
        scanf("%d",&S.elem[j]);
    }
    if(DeleteK(S,i,k))
    {
        for(int j=1;j<=S.length;j++)
        {
            printf("%d ",S.elem[j]);
        }
    }
    else printf("False !");
    return 0;
}
