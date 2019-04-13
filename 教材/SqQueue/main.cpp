#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
//循环队列，用数组定义
const int MAXQSIZE=100;

typedef struct
{
    QElemType *base;
    int Front;
    int rear;
}SqQueue;

void InitQueue(SqQueue &Q)
{
    Q.base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
    Q.Front=Q.rear=0;
}

int QueueLength(SqQueue &Q)
{
    return (Q.rear-Q.Front+MAXQSIZE)%MAXQSIZE;
}

bool EnQueue(SqQueue &Q,QELemType e)
{
    if((Q.rear+1)%MAXQSIZE==Q.Front) return false;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;
    return true;
}

int main()
{
    return 0;
}
