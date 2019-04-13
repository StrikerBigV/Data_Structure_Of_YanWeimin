#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

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

//�̲������㷨���漰������������
//����ת������ʮ������ת��Ϊd���������
typedef int SElemType;
void conversion(int d)
{
    int N,res;
    SqStack S;
    InitStack(S);
    scanf("%d",&N);
    while(N)
    {
        Push(S,N%d);//������ջ
        N/=d;//����
    }
    while(!stackEmpty(S))
    {
        r=Pop(S);
        printf("%d",r);
    }
}
//����ƥ��ļ���
typedef char SElemType;
bool bracketsMatch()
{
    char c;
    SqStack S;
    InitStack(S);
    c=getchar();
    Push(S,c);
    while(!stackEmpty(S))
    {
        c=getchar();
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
    return true;
}
//�б༭����
void LineEdit()
{
    char c;
    SqStack S;
    c=getchar();
    while(c!=EOF)
    {//����ȫ�ģ�EOFΪȫ�Ľ�����
        while(c!=EOF && c!='\n')
        {//����һ�У�'\n'Ϊ���з�
            switch(c)
            {
                case '#' :char r=Pop(S);//����'#'��ջ��Ԫ�س�ջ
                case '@' :clearStack(S);//����'@'�����ջ��Ԫ��
                default :Push(S,c);//����������Ч�ַ�����ջ
            }
            c=getchar();
        }
        //�˴�ӦΪ��������Ԫ�����뵽�������Ĵ���
        clearStack(S);//������һ�У����ջ
        if(c!=EOF) c=getchar();
    }
    DestroyStack(S);//������ȫ�ģ�����ջ
}

//�Թ���⣬��Ϊ����
//������������
typedef struct
{
    int x,y;
}PosType;
//ջ����������
typedef struct
{
    int ord;//ͨ������·���ϵ����
    PosType seat;//ͨ�������Թ��е�����
    int di;//������һ��ͨ����ķ���
}SElemType;
vector<vector<bool> > isVisited={false};
vector<vector<int> > maze;
bool pass(PosType p);
{
    if(isVisited[p.x][p.y]==true || maze[p.x][p.y]==-1) return false;
    return true;
}
void footPrint(PosType p);
{
    isVisited[p.x][p.y]=true;
}
void markPrint(PosType p);
{
    maze[p.x][p.y]=-1;
}
PosType NextPos(PosType p,int di);
{
    PosType next=p;;
    if(di==1) next.x+=1;
    else if(di==2) next.y-=1;
    else if(di==3) next.x-=1;
    else next.y+=1;
    return next;
}
bool MazePath(vector<vector<int> > maze,PosType Start,PosType End)
{
    SqStack S;
    InitStack(S);
    int curStep=1;//̽����һ��
    PosType curPos=Start;//��ʼλ��Ϊ���
    do
    {
        if(pass(curPos))//��ͨ����Ϊδ���ʹ���ͨ����
        {
            footPrint(curPos);//�����㼣
            SElemType e; e.ord=curStep;e.seat=curPos;e.di=1;
            Push(S,e);//��ͨ������ջ
            if(curPos==End) return true;//�������յ㣬����������ͨ��
            curPos=NextPos(curPos,1);//���ʸ�ͨ����Ķ��ڵ�
            curStep++;//��һ��
        }
        else
        {//����ͨ
            if(!stackEmpty(S)) SElemType e=Pop(S);
            while(e.di==4 && !stackEmpty(S))//���ϸ�ͨ�����ĸ������̽���������ջ
            {
                markPrint(e.seat);SElemType e=pop(S);//���²���ͨ�����㼣
            }
            if(e.di<4)
            {
                e.di++;
                Push(S,e);
                curPos=NextPos(e.seat,e.di);
            }
        }
    }while(!stackEmpty(S));
    return false;
}

//���ʽ��ֵ������������ȹ�ϵ
typedef char SElemType;
OperandType EvaluateExpression()
{
    InitStack(OPTR); Push(OPTR,'#');//�����ջ
    InitStack(OPND); c=getchar();//������ջ
    while(c!='#' || GetTop(OPTR)!='#')
    {//��ȡ�����У��������ջ����Ч�����
        if(!In(c,OP)) {Push(OPND,c);}//�������������ջ
        else
        {//��ȡ���������ջ��������Ƚ�
            switch Precede(GetTop(OPTR),c)
            {
                case '<' :Push(OPTR,c); c=getchar();break;//ջ����������ȼ��ͣ����ȡ���������ջ
                case '=' :char x=Pop(OPTR); c=getchar();break;//����������������ջ
                case '>' :char theta=Pop(OPTR);char a=Pop(OPND);char b=Pop(OPND);
                            Push(OPND,Operate(a,theta,b));break;//ջ��������ȼ��ߣ����ջ���������������ջ
            }
        }
    }
    return GetTop(OPND);
}

//��ŵ������
void hanoi(int n,char x,char y,char z)
{//��n��Բ����x���ŵ�z��
    if(n==1) Move(x,1,z);//һ��Բ�̣�ֱ�ӷŵ�z��
    else
    {
        hanoi(n-1,x,z,y);//������n-1��Բ�̷ŵ�y��
        Move(x,n,z);//��n�̷ŵ�z��
        hanoi(n-1,y,x,z);//��ʣ��n-1���̷ŵ�z��
    }
}

int main()
{
    return 0;
}
