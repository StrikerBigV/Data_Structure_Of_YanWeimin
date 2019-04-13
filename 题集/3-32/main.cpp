#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef int QElemType;
//ѭ�����У������鶨��
int k;
typedef struct
{
    QElemType *base;
    int Front;
    int rear;
}SqQueue;

void InitQueue(SqQueue &Q)
{
    Q.base=(QElemType *)malloc(k*sizeof(QElemType));
    Q.Front=Q.rear=0;
}

int QueueLength(SqQueue &Q)
{
    return (Q.rear-Q.Front+k)%k;
}

void EnQueue(SqQueue &Q,int e)
{
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%k;
}
void DeQueue(SqQueue &Q)
{
    Q.Front=(Q.Front+1)%k;
}
//***********************�㷨��ʼ*******************//
int cal(SqQueue &Q)
{
    int res=0;
    for(int i=0;i<k;i++)
    res+=Q.base[i];
    return res;
}//�������Ԫ�غ�
int main()
{
    int n;
    scanf("%d%d",&k,&n);
    SqQueue Q;
    InitQueue(Q);
    for(int i=0;i<k-1;i++)
        Q.base[i]=0;
    Q.base[k-1]=1;
    int temp;
    if(n<k) printf("%d",Q.base[n]);//ǰk-1��
    else{//k��֮��
        for(int i=0;i<n-k+1;i++)
        {
            temp=cal(Q);
            DeQueue(Q);
            EnQueue(Q,temp);
        }
        printf("%d",Q.base[(Q.rear+k-1)%k]);
    }
    return 0;
}
