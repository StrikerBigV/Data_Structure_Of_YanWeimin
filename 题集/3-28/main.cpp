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
    Q.rear->next=Q.rear;//��ʼѭ������Ϊ��
}

void EnQueue(Queue &Q,int x)
{//��β������룬�µĽ���Ϊβ���
    QNode* q=(QueuePtr)malloc(sizeof(QNode));
    q->data=x;
    q->next=Q.rear->next
    Q.rear->next=q;
    Q.rear=q;
}

void DeQueue(Queue &Q)
{//ɾ��ͷ���
    QNode *p=Q.rear->next;
    Q.rear->next=p->next;
    free(p);
}

int main()
{
    return 0;
}
