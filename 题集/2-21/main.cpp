#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int LIST_INIT_SIZE=100;

typedef struct{
    int *elem;
    int length;
    int listsize;
}SqList;

void InitList(SqList &L)
{
    L.elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
}

//*********************Ëã·¨¿ªÊ¼*******************//
void Reverse(SqList &L)
{
    int temp;
    for(int i=1;i<=L.length/2;i++)
    {
        temp=L.elem[i];
        L.elem[i]=L.elem[L.length-i+1];
        L.elem[L.length-i+1]=temp;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    SqList S;
    InitList(S);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&S.elem[i]);
        S.length++;
    }
    Reverse(S);
    for(int i=1;i<=n;i++)
    {
        printf("%d ",S.elem[i]);
    }
    return 0;
}
