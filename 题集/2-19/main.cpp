#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode* next;
}LNode,*LinkList;

//逆序建立链表
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

//**********************算法开始*********************//
int find_loc(LinkList &L,int mink,int maxk)
{
    LinkList p,q,pre=NULL;
    if(mink>maxk) return -1;
    p=L;
    pre=p;
    p=p->next;
    while(p && p->data<maxk)
    {
        if(p->data<=mink)
        {
            pre=p;
            p=p->next;
        }
        else{
            pre->next=p->next;
            q=p;
            p=p->next;
            free(q);
        }
    }
    return 0;
}
int main()
{
    int n,mink,maxk;
    LinkList L,p;
    scanf("%d",&n);
    CreateList(L,n);
    scanf("%d%d",&mink,&maxk);
    int loc=find_loc(L,mink,maxk);
    if(loc==-1) printf("mink must be < maxk");
    if(loc==0){
        p=L;
        while(p->next!=NULL)
        {
            p=p->next;
            printf("%d ",p->data);
        }
    }
    return 0;
}
