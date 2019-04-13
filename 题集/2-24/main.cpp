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

//***********************算法开始*********************//
//逆序合并
void MergeRevList(LinkList &A,LinkList &B,LinkList &C)
{
    LinkList pa=A,qa=pa,pb=B,qb=pb;
    pa=pa->next;
    pb=pb->next;
    A->next=NULL;
    C=A;
    while(pa && pb)
    {
        if(pa->data < pb->data)
        {
            qa=pa;
            pa=pa->next;
            qa->next=A->next;
            A->next=qa;
        }
        else
        {
            qb=pb;
            pb=pb->next;
            qb->next=A->next;
            A->next=qb;
        }
    }
    while(pa)
    {
        qa=pa;
        pa=pa->next;
        qa->next=A->next;
        A->next=qa;
    }
    while(pb)
    {
        qb=pb;
        pb=pb->next;
        qb->next=A->next;
        A->next=qb;
    }
    free(B);
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    LinkList A,B,C;
    createList(A,m);
    createList(B,n);
    MergeRevList(A,B,C);
    LinkList p=C->next;
    while(p->next)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d",p->data);
    return 0;
}
