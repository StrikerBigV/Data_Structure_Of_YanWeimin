#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

//��㶨��
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

//�����ж���
typedef struct
{
    QueuePtr Front;
    QueuePtr rear;
}LinkQueue;

//��������
void InitQueue(LinkQueue &Q);//����ն���
void DestroyQueue(LinkQueue &Q);//���ٶ���
void clearQueue(LinkQueue &Q);//��ն���
bool QueueEmpty(LinkQueue &Q);//�п�
int QueueLength(LinkQueue &Q);//����г���
QElemType GetHead(LinkQueue &Q);//���ض���Ԫ��
void EnQueue(LinkQueue &Q,QElemType e);//����Ԫ�ص���β
QElemType DeQueue(LinkQueue &Q);//ɾ������Ԫ�ز�����

// ����ʵ��
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
