#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef int SElemType;
typedef int TElemType;
//********************栈的定义及实现*******************//
const int STACK_INIT_SIZE=100;
const int STACKINCREMENT=10;

typedef struct
{
    SElemType *top;
    SElemType *base;
    int stackSize;
}SqStack;

//函数原型说明
void InitStack(SqStack &S);//初始化栈
void DestroyStack(SqStack &S);//销毁栈
void clearStack(SqStack &S);//清空栈
bool stackEmpty(SqStack &S);//判空
int StackLength(SqStack &S);//返回栈的长度
SElemType GetTop(SqStack &S);//返回栈顶元素
void Push(SqStack &S,SElemType elem);//入栈
SElemType Pop(SqStack &S);//出栈，并返回原栈顶元素

//函数实现
//初始化栈
void InitStack(SqStack &S)
{
    S.base=(SElemType* )malloc(STACK_INIT_SIZE*sizeof(SElemType));
    S.top=S.base;
    S.stackSize=STACK_INIT_SIZE;
}
//销毁栈
void DestroyStack(SqStack &S)
{
    free(S.base);
    S.base=NULL;
}
//清空栈
void clearStack(SqStack &S)
{
    S.top=S.base;
}
//判空
bool stackEmpty(SqStack &S)
{
    if(S.top==S.base) return true;
    else return false;
}
//返回栈的长度
int StackLength(SqStack &S)
{
    return (S.top-S.base);
}
//返回栈顶元素
SElemType GetTop(SqStack &S)
{
    if(S.base==S.top) return 0;
    return *(S.top-1);
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

//***********************二叉树*********************//
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//访问函数
void visit(BiTree &T){
    printf("%c ",T->data);
}

//***********************算法开始*************************//
void PreOrderTraverse(BiTree T){
    SqStack S;
    InitStack(S);
    int temp;
    BiTree p=T;
    while(p || !stackEmpty(S)){
        if(p){
            visit(p);
            Push(S,p->data);
            p=p->lchild;
        }
        else{
            temp=Pop(S);
            p=p->rchild;
        }
    }
}

int main()
{
    return 0;
}
