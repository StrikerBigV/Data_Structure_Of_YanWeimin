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

//教材其它算法，涉及具体数据类型
//数制转换，将十进制数转换为d进制数输出
typedef int SElemType;
void conversion(int d)
{
    int N,res;
    SqStack S;
    InitStack(S);
    scanf("%d",&N);
    while(N)
    {
        Push(S,N%d);//余数入栈
        N/=d;//整除
    }
    while(!stackEmpty(S))
    {
        r=Pop(S);
        printf("%d",r);
    }
}
//括号匹配的检验
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
    return true;
}
//行编辑程序
void LineEdit()
{
    char c;
    SqStack S;
    c=getchar();
    while(c!=EOF)
    {//处理全文，EOF为全文结束符
        while(c!=EOF && c!='\n')
        {//处理一行，'\n'为换行符
            switch(c)
            {
                case '#' :char r=Pop(S);//遇到'#'，栈顶元素出栈
                case '@' :clearStack(S);//遇到'@'，清空栈中元素
                default :Push(S,c);//遇到其它有效字符，入栈
            }
            c=getchar();
        }
        //此处应为将缓冲区元素输入到数据区的代码
        clearStack(S);//处理完一行，清空栈
        if(c!=EOF) c=getchar();
    }
    DestroyStack(S);//处理完全文，销毁栈
}

//迷宫求解，较为具体
//坐标数据类型
typedef struct
{
    int x,y;
}PosType;
//栈的数据类型
typedef struct
{
    int ord;//通道块在路径上的序号
    PosType seat;//通道块在迷宫中的坐标
    int di;//走向下一个通道块的方向
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
    int curStep=1;//探索第一步
    PosType curPos=Start;//起始位置为起点
    do
    {
        if(pass(curPos))//可通，即为未访问过的通道块
        {
            footPrint(curPos);//留下足迹
            SElemType e; e.ord=curStep;e.seat=curPos;e.di=1;
            Push(S,e);//该通道块入栈
            if(curPos==End) return true;//若到达终点，结束，存在通道
            curPos=NextPos(curPos,1);//访问该通道块的东邻点
            curStep++;//下一步
        }
        else
        {//不可通
            if(!stackEmpty(S)) SElemType e=Pop(S);
            while(e.di==4 && !stackEmpty(S))//若上个通道块四个方向均探索过，则出栈
            {
                markPrint(e.seat);SElemType e=pop(S);//留下不能通过的足迹
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

//表达式求值，根据算符优先关系
typedef char SElemType;
OperandType EvaluateExpression()
{
    InitStack(OPTR); Push(OPTR,'#');//运算符栈
    InitStack(OPND); c=getchar();//操作数栈
    while(c!='#' || GetTop(OPTR)!='#')
    {//读取过程中，且运算符栈有有效运算符
        if(!In(c,OP)) {Push(OPND,c);}//操作数入操作数栈
        else
        {//读取的运算符与栈顶运算符比较
            switch Precede(GetTop(OPTR),c)
            {
                case '<' :Push(OPTR,c); c=getchar();break;//栈顶运算符优先级低，则读取的运算符入栈
                case '=' :char x=Pop(OPTR); c=getchar();break;//左右括号相遇，出栈
                case '>' :char theta=Pop(OPTR);char a=Pop(OPND);char b=Pop(OPND);
                            Push(OPND,Operate(a,theta,b));break;//栈顶运算符等级高，则出栈，运算结果入操作数栈
            }
        }
    }
    return GetTop(OPND);
}

//汉诺塔问题
void hanoi(int n,char x,char y,char z)
{//将n个圆盘由x柱放到z柱
    if(n==1) Move(x,1,z);//一个圆盘，直接放到z柱
    else
    {
        hanoi(n-1,x,z,y);//将上面n-1个圆盘放到y柱
        Move(x,n,z);//将n盘放到z柱
        hanoi(n-1,y,x,z);//将剩余n-1个盘放到z柱
    }
}

int main()
{
    return 0;
}
