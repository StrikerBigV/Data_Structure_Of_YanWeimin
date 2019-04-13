#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

//结点定义
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

//函数声明
void InitQueue(LinkQueue &Q);//构造空队列
void DestroyQueue(LinkQueue &Q);//销毁队列
void clearQueue(LinkQueue &Q);//清空队列
bool QueueEmpty(LinkQueue &Q);//判空
int QueueLength(LinkQueue &Q);//求队列长度
QElemType GetHead(LinkQueue &Q);//返回队首元素
void EnQueue(LinkQueue &Q,QElemType e);//插入元素到队尾
QElemType DeQueue(LinkQueue &Q);//删除队首元素并返回

// 函数实现
bool QueueEmpty(LinkQueue Q){
    if(Q.Front==Q.rear) return true;;
    else return false;
}

void InitQueue(LinkQueue &Q)
{
    Q.Front=(QueuePtr)malloc(sizeof(QNode));
    Q.Front->next=NULL;
    Q.rear=Q.Front;
}

void DestroyQueue(LinkQueue &Q)
{
    while(Q.Front)
    {
        Q.rear=Q.Front->next;
        free(Q.Front);
        Q.Front=Q.rear;
    }
}

void clearQueue(LinkQueue &Q)
{
    QueuePtr p=Q.Front->next,q;
    Q.Front=Q.rear;
    Q.Front->next=NULL;
    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
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
int main()
{
    return 0;
}
