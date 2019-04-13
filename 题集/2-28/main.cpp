#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode* next;
}LNode,*LinkList;

void CreateList(LinkList &L,int n)
{
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    LinkList p;
    for(int i=1;i<=n;i++)
    {
        p=(LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->data);//逆序输入
        p->next=L->next;
        L->next=p;
    }
}

//**********************算法开始***********************//
void intersection(LinkList &A,LinkList &B)
{
    LinkList pa=A,pb=B,pc=A;
    pa=pa->next;
    pb=pb->next;
    while(pa && pb)
    {
        if(pa->data<pb->data) {pa=pa->next;}
        else if(pa->data>pb->data) {pb=pb->next;}
        else if(pa->data!=pc->data)
        {
            pc=pc->next;
            pc->data=pa->data;
            pa=pa->next;
            pb=pb->next;
        }
    }
    pc->next=NULL;
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    LinkList A,B;
    CreateList(A,m);
    CreateList(B,n);
    intersection(A,B);
    LinkList p=A;
    while(p->next)
    {
        p=p->next;
        printf("%d ",p->data);
    }
    return 0;
}
