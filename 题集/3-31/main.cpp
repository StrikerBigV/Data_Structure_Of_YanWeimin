#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef char SElemType,QElemType;
const int maxn=100;
// 栈的数据结构
const int STACK_INIT_SIZE=100;
const int STACKINCREMENT=10;

typedef struct
{
    SElemType *top;
    SElemType *base;
    int stackSize;
}SqStack;

void InitStack(SqStack &S)
{
    S.base=(SElemType* )malloc(STACK_INIT_SIZE*sizeof(SElemType));
    S.top=S.base;
    S.stackSize=STACK_INIT_SIZE;
}
//入栈
void Push(SqStack &S,SElemType elem)
{
    if((S.top-S.base)>=S.stackSize)
    {
        S.base=(SElemType *)realloc(S.base,(STACK_INIT_SIZE+STACKINCREMENT)*sizeof(SElemType));
        S.top=S.base+S.stackSize;
        S.stackSize+=STACKINCREMENT;
    }
    *S.top++=elem;
}
//出栈
SElemType Pop(SqStack &S)
{
   if(S.base==S.top) return -1;
   return *(--S.top);
}

//队列的数据结构
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

//链队列定义
typedef struct
{
    QueuePtr Front;
    QueuePtr rear;
}LinkQueue;

void InitQueue(LinkQueue &Q)
{
    Q.Front=(QueuePtr)malloc(sizeof(QNode));
    Q.Front->next=NULL;
    Q.rear=Q.Front;
}
void EnQueue(LinkQueue &Q,QElemType e)
{
    QNode *p=(QueuePtr )malloc(sizeof(QNode));
    p->data=e;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
}

QElemType DeQueue(LinkQueue &Q)
{
    QNode *p=Q.Front->next;
    QElemType e=p->data;
    Q.Front->next=p->next;
    if(p==Q.rear) Q.rear=Q.Front;
    free(p);
    return e;
}
//***********************算法开始*****************//
int main()
{
    char p[maxn],c;
    bool res=true;
    int num=0;
    while((c=getchar())!='@')
        p[num++]=c;
    SqStack S;
    InitStack(S);
    LinkQueue Q;
    InitQueue(Q);
    for(int i=0;i<num;i++)
    {
        Push(S,p[i]);
        EnQueue(Q,p[i]);
    }
    for(int i=0;i<num;i++)
    {
        if(Pop(S) != DeQueue(Q)) res=false;
    }
    if(res) printf("True");
    else printf("False");
    return 0;
}
