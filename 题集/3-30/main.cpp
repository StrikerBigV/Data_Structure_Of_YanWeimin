#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXSIZE=100;

typedef struct
{
    int *data;
    int rear;
    int length;
}Queue;

void InitQueue(Queue &Q)
{
    Q.data=(int*)malloc(sizeof(int));
    Q.rear=0;
    Q.length=0;
}

bool EnQueue(Queue &Q,int x)
{
    if((Q.rear+1)%MAXSIZE == (Q.rear+MAXSIZE-Q.length)%MAXSIZE) return false;//加一 判满
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MAXSIZE;
    Q.length++;
}

int DeQueue(Queue &Q)
{
    int ret;
    if(Q.rear == (Q.rear+MAXSIZE-Q.length)%MAXSIZE) return -1;//相等 判空
    ret=Q.data[(Q.rear+MAXSIZE-Q.length)%MAXSIZE];
    Q.length--;
    return ret;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
