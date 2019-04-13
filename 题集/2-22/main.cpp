#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int LIST_INIT_SIZE=100;

typedef struct LNode{
    int data;
    struct LNode* next;
}LNode,*LinkList;

//逆序建立链表
void createList(LinkList &L,int n)
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

//**********************算法开始**********************//
void Reverse(LinkList &L)
{
    LinkList p=L->next,q;
    L->next=NULL;
    while(p)
    {
        q=p;
        p=p->next;
        q->next=L->next;
        L->next=q;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    LinkList L;
    createList(L,n);
    Reverse(L);
    LinkList p=L;
    while(p->next)
    {
        p=p->next;
        printf("%d ",p->data);
    }
    return 0;
}
