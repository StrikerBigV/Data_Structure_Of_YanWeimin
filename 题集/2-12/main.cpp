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

//****************************Ëã·¨¿ªÊ¼************************//
int judgeEq(SqList &A, SqList &B)
{
    int lenA=A.length,lenB=B.length,judge=0;
    int Min=min(lenA,lenB);
    for(int i=1;i<=Min;i++)
    {
        if(A.elem[i]<B.elem[i]) judge=-1;
        if(A.elem[i]>B.elem[i]) judge=1;
    }
    if(judge==0)
    {
        if(lenA>lenB) judge=1;
        else if(lenA<lenB) judge=-1;
        else judge=0;
    }
    return judge;
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    SqList A,B;
    InitList(A);
    A.length=m;
    InitList(B);
    B.length=n;
    for(int i=1;i<=m;i++)
        scanf("%d",&A.elem[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&B.elem[i]);
    int judge=judgeEq(A,B);
    if(judge==0) printf("A = B");
    else if(judge==-1) printf("A < B");
    else printf("A > B");
    return 0;
}
