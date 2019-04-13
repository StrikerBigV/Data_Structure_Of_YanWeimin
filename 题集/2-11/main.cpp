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

//******************算法开始*******************//
//找到第一个大于x的位置
int find_loc(SqList &L,int x)
{
    int left=1,right=L.length;
    int mid;
    while(left<right)
    {
        mid=(left+right)/2;
        if(L.elem[mid]>x) right=mid;
        else left=mid+1;
    }
    return left;
}
//插入x
bool Insert(SqList &L,int x,int theIndex)
{
    if(x>L.elem[L.length]) return false;
    else{
        int* newbase=(int *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(int));
        L.elem=newbase;
        L.listsize+=LISTINCREMENT;
        for(int i=L.length;i>=theIndex;i--)
        {
            L.elem[i+1]=L.elem[i];
        }
        L.elem[theIndex]=x;
        L.length++;
    }
    return true;
}
int main()
{
    int n;
    scanf("%d",&n);
    SqList S;
    InitList(S);
    S.length=n;
    for(int j=1;j<=n;j++)
    {
        scanf("%d",&S.elem[j]);
    }
    int x;
    scanf("%d",&x);
    int loc=find_loc(S,x);
    if(Insert(S,x,loc)){
        for(int i=1;i<=S.length;i++)
        {
            printf("%d ",S.elem[i]);
        }
    }
    else printf("False !");
    return 0;
}
