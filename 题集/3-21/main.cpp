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

//**************************�㷨��ʼ*********************//
bool isArSign(char c)
{
    if(c=='+' || c=='-' || c=='*' || c== '/' || c=='(' || c==')' || c=='#') return true;
    return false;
}//�Ƿ�Ϊ���������
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
}//�ж����ȼ�
char res[100];
int cnt=0;
void infixToSuffix(SqStack &S)
{
    char c,temp;
    c=getchar();
    Push(S,c);
    while((c=getchar())!='#'){//��ȡ�ַ���
        if(!isArSign(c)) res[cnt++]=c;//�ַ�Ϊ����������������
        else{
            if(c=='(') Push(S,c);//�ַ�Ϊ'('����ջ
            else if(c==')'){//�ַ�Ϊ')'����ͣ��ջֱ������'('
                while((temp=Pop(S))!='(') res[cnt++]=temp;
            }
            else{
                if(precede(GetTop(S),c)) Push(S,c);//�ַ�Ϊ��ͨ����������������ȼ���ջ��Ԫ�ظߣ�����ջ
                else{
                    while(!precede(GetTop(S),c)) res[cnt++]=Pop(S);//���򣬲�ͣ��ջֱ�����ȼ���ջ��Ԫ�ظ�
                    Push(S,c);//��ջ
                }
            }
        }
    }
    while(GetTop(S)!='#') res[cnt++]=Pop(S);//��ջ��ʣ��Ԫ��������������
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
