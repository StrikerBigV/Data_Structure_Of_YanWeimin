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
//��ʼ��ջ
void InitStack(SqStack &S)
{
    S.base=(SElemType* )malloc(STACK_INIT_SIZE*sizeof(SElemType));
    S.top=S.base;
    S.stackSize=STACK_INIT_SIZE;
}
//�п�
bool stackEmpty(SqStack &S)
{
    if(S.top==S.base) return true;
    else return false;
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
//************************�㷨��ʼ********************//
bool bracketsMatch()
{
    char c;
    SqStack S;
    InitStack(S);
    c=getchar();
    Push(S,c);
    while((c=getchar())!='\n')
    {//������Ч�ַ�
        if(c=='(' || c=='[' ||c=='{') Push(S,c);//������ֱ����ջ
        else if(c==')'){
            if(GetTop(S)=='(') Pop(S);//�����������ջ��Ԫ��ƥ�䣬��ջ��Ԫ�س�ջ����ͬ
            else return false;
        }
        else if(c==']'){
            if(GetTop(S)=='[') Pop(S);
            else return false;
        }
        else if(c=='}'){
            if(GetTop(S)=='{') Pop(S);
            else return false;
        }
    }
    if(!stackEmpty(S)) return false;//ջ�ﻹ��δƥ���������
    return true;
}

int main()
{
    if(bracketsMatch()) printf("True\n");
    else printf("False\n");
    return 0;
}
