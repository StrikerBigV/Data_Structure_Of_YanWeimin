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

//**************************算法开始*********************//
bool isArSign(char c)
{
    if(c=='+' || c=='-' || c=='*' || c== '/' || c=='(' || c==')' || c=='#') return true;
    return false;
}//是否为四则运算符
bool precede(char a,char b)
{
    if(a=='#') return true;
    if(a=='+' || a=='-'){
        if(b=='+' || b=='-') return false;
        else return true;
    }
    if(a=='*' || a=='/'){
        if(b=='(') return true;
        else return false;
    }
    if(a=='(') return true;
}//判断优先级
char res[100];
int cnt=0;
void infixToSuffix(SqStack &S)
{
    char c,temp;
    c=getchar();
    Push(S,c);
    while((c=getchar())!='#'){//读取字符中
        if(!isArSign(c)) res[cnt++]=c;//字符为变量，放入结果数组
        else{
            if(c=='(') Push(S,c);//字符为'('，入栈
            else if(c==')'){//字符为')'，不停出栈直到遇到'('
                while((temp=Pop(S))!='(') res[cnt++]=temp;
            }
            else{
                if(precede(GetTop(S),c)) Push(S,c);//字符为普通四则运算符，若优先级比栈顶元素高，则入栈
                else{
                    while(!precede(GetTop(S),c)) res[cnt++]=Pop(S);//否则，不停出栈直到优先级比栈顶元素高
                    Push(S,c);//入栈
                }
            }
        }
    }
    while(GetTop(S)!='#') res[cnt++]=Pop(S);//将栈中剩余元素输出到结果数组
}
int main()
{
    SqStack S;
    InitStack(S);
    infixToSuffix(S);
    for(int i=0;i<cnt;i++)
        printf("%c",res[i]);
    return 0;
}
