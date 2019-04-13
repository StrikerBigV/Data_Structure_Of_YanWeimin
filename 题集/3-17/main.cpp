#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int STACK_INIT_SIZE=100;
const int STACKINCREMENT=10;

typedef char SElemType;

typedef struct
{
    SElemType *top;
    SElemType *base;
    int stackSize;
}SqStack;

//初始化栈
void InitStack(SqStack &S)
{
    S.base=(SElemType* )malloc(STACK_INIT_SIZE*sizeof(SElemType));
    S.top=S.base;
    S.stackSize=STACK_INIT_SIZE;
}
//判空
bool stackEmpty(SqStack &S)
{
    if(S.top==S.base) return true;
    else return false;
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

//***************************算法开始************************//
bool Bool(){
    char c;
    SqStack S;
    InitStack(S);
    while((c=getchar())!='&' && c!='@')
    {
        Push(S,c);
    }
    if(c=='@') return false;
    else{
        while((c=getchar())!='&' && c!='@')
        {
            char top=Pop(S);
            if(top!=c) return false;
        }
        if(c=='&') return false;
    }
    return true;
}
int main()
{
    if(Bool()) printf("True\n");
    else printf("False\n");
    return 0;
}
