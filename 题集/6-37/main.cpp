#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef int SElemType;
typedef int TElemType;
//********************ջ�Ķ��弰ʵ��*******************//
const int STACK_INIT_SIZE=100;
const int STACKINCREMENT=10;

typedef struct
{
    SElemType *top;
    SElemType *base;
    int stackSize;
}SqStack;

//����ԭ��˵��
void InitStack(SqStack &S);//��ʼ��ջ
void DestroyStack(SqStack &S);//����ջ
void clearStack(SqStack &S);//���ջ
bool stackEmpty(SqStack &S);//�п�
int StackLength(SqStack &S);//����ջ�ĳ���
SElemType GetTop(SqStack &S);//����ջ��Ԫ��
void Push(SqStack &S,SElemType elem);//��ջ
SElemType Pop(SqStack &S);//��ջ��������ԭջ��Ԫ��

//����ʵ��
//��ʼ��ջ
void InitStack(SqStack &S)
{
    S.base=(SElemType* )malloc(STACK_INIT_SIZE*sizeof(SElemType));
    S.top=S.base;
    S.stackSize=STACK_INIT_SIZE;
}
//����ջ
void DestroyStack(SqStack &S)
{
    free(S.base);
    S.base=NULL;
}
//���ջ
void clearStack(SqStack &S)
{
    S.top=S.base;
}
//�п�
bool stackEmpty(SqStack &S)
{
    if(S.top==S.base) return true;
    else return false;
}
//����ջ�ĳ���
int StackLength(SqStack &S)
{
    return (S.top-S.base);
}
//����ջ��Ԫ��
SElemType GetTop(SqStack &S)
{
    if(S.base==S.top) return 0;
    return *(S.top-1);
}
//��ջ
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
//��ջ
SElemType Pop(SqStack &S)
{
   if(S.base==S.top) return -1;
   return *(--S.top);
}

//***********************������*********************//
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//���ʺ���
void visit(BiTree &T){
    printf("%c ",T->data);
}

//***********************�㷨��ʼ*************************//
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
