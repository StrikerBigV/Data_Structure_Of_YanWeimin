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
//************************算法开始********************//
bool bracketsMatch()
{
    char c;
    SqStack S;
    InitStack(S);
    c=getchar();
    Push(S,c);
    while((c=getchar())!='\n')
    {//输入有效字符
        if(c=='(' || c=='[' ||c=='{') Push(S,c);//左括号直接入栈
        else if(c==')'){
            if(GetTop(S)=='(') Pop(S);//如果右括号与栈顶元素匹配，则栈顶元素出栈，下同
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
    if(!stackEmpty(S)) return false;//栈里还有未匹配的左括号
    return true;
}

int main()
{
    if(bracketsMatch()) printf("True\n");
    else printf("False\n");
    return 0;
}
