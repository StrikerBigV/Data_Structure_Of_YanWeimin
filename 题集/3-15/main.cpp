#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int STACK_INIT_SIZE=100;
const int STACKINCRMENT=10;

typedef struct
{
    int *base0,*top0;
    int *base1,*top1;
    int stackSize;
}douStack;

void InitSatck(douStack &S)
{
    S.base0=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
    S.top0=S.base0;
    S.base1=S.base0+STACK_INIT_SIZE-1;
    S.top1=S.base1;
    S.stackSize=STACK_INIT_SIZE;
}

void Push(douStack &S,int i,int x)
{
    if(S.top0==S.top1){
        int *newbase=(int *)realloc(S.base1,STACKINCRMENT*sizeof(int));
        int *p;
        for(p=newbase;p>(newbase-S.base1+S.top1);p--)
            *p=*(p-S.base1+S.top1);
        S.base1=newbase;
        S.top1=p;
        S.stackSize+=STACKINCRMENT;
    }
    if(i==0) *S.top0++=x;
    if(i==1) *S.top1--=x;
}

int Pop(douStack &S,int i)
{
    if(S.base0==S.top0 || S.base1==S.top1) return -1;
    if(i==0) return * --S.top0;
    if(i==1) return * ++S.top1;
}

int main()
{
    int m,n,a,b;
    scanf("%d%d",&m,&n);
    douStack S;
    InitSatck(S);
    for(int i=0;i<m;i++){
        scanf("%d",&a);
        Push(S,0,a);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b);
        Push(S,1,b);
    }
    int i,x;
    scanf("%d%d",&i,&x);
    if(i==0){
        Push(S,0,x);
        for(int *p=S.base0;p<S.top0;p++)
            printf("%d ",*p);
    }
    else{
        Push(S,1,x);
        for(int *p=S.base1;p>S.top1;p--)
            printf("%d ",*p);
    }
    return 0;
}
