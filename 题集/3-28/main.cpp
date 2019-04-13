#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct QNode
{
    int data;
    QNode* next;
}QNode,*QueuePtr;

typedef struct
{
    QueuePtr rear;
}Queue;

void InitQueue(Queue &Q)
{
    Q.rear=(QueuePtr)malloc(sizeof(QNode));
    Q.rear->next=Q.rear;//初始循环链表为空
}

void EnQueue(Queue &Q,int x)
{//在尾结点后插入，新的结点变为尾结点
    QNode* q=(QueuePtr)malloc(sizeof(QNode));
    q->data=x;
    q->next=Q.rear->next
    Q.rear->next=q;
    Q.rear=q;
}

void DeQueue(Queue &Q)
{//删除头结点
    QNode *p=Q.rear->next;
    Q.rear->next=p->next;
    free(p);
}

int main()
{
    return 0;
}
