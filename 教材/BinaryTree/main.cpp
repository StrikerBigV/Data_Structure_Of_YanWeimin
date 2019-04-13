#include <cstdio>
#include <cstdlib>
using namespace std;

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
//*******************************************************************//

//****************************正文开始******************************//
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//访问函数
void visit(BiTree &T){
    printf("%c",T->data);
}

// 构建二叉树
void CreateBiTree(BiTree &T){
    char ch;
    scanf("%c",&ch);
    if(ch==' ') T=NULL;//空树
    else{
        T=(BiTNode*)malloc(sizeof(BiTNode));
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);//递归构建左右子树
    }
}

//递归先序遍历
void PreOrderTraverse(BiTree &T){
    if(T){
        visit(T);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

//非递归先序遍历法一
//以当前结点为主要处理对象
void PreOrderTraverse_2(BiTree T){
    SqStack S;
    InitStack(S);
    BiTree p=T;
    while(p || !stackEmpty()){//当前结点存在，或者栈不空；否则，结束循环
        if(p){//当前结点存在
            visit(p);//访问
            Push(S,p);//入栈
            p=p->lchild;//处理当前结点左子树
        }
        else{//当前结点不存在
            p=Pop(S);//退栈
            p=p->rchild;//处理栈顶结点右子树
        }
    }
}

//非递归先序遍历法二
//以栈为主要处理对象
void PreOrderTraverse_3(BiTree T){
    SqStack S;
    InitStack(S);
    BiTree p=T;
    Push(S,p);//根入栈，相当于驱动栈的处理
    while(!stackEmpty(S)){//栈不空，否则循环结束
        while(p=GetTop(S)){//栈顶结点存在，一直访问左子树直到叶子结点
            visit(p);//访问
            Push(S,p->lchild);//栈顶结点左子树根入栈
        }
        p=Pop(S);//空指针退栈
        if(!stackEmpty(S)){
            p=Pop(S);
            Push(S,p->rchild);//由后向前依次将右子树根入栈
        }
    }
}

//递归中序遍历
//与递归先序遍历只有访问语句的顺序不同
void InOrderTraverse(BiTree &T){
    if(T){
        InOrderTraverse(T->lchild);
        visit(T);
        InOrderTraverse(T->rchild);
    }
}

//非递归中序遍历法一
//与非递归先序遍历只有访问语句顺序不同
void InOrderTraverse_2(BiTree &T){
    SqStack S;
    InitStack(S);
    BiTree p=T;
    while(p || !stackEmpty(S)){
        if(p){
            Push(S,p);
            p=p->lchild;
        }
        else{
            p=Pop(S);
            visit(p);
            p=p->rchild;
        }
    }
}

//非递归中序遍历法二
//同上
void InOrderTraverse_3(BiTree &T){
    SqStack S;
    InitStack(S);
    BiTree p=T;
    Push(S,p);
    while(!stackEmpty(S)){
        while(p=GetTop(S)){
            Push(S,p->lchild);
        }
        p=Pop(S);
        if(!stackEmpty(S)){
            p=Pop(S);
            visit(p);
            Push(S,p->rchild);
        }
    }
}

//递归后序遍历
void PostOrderTraverse(BiTree &T){
    if(T){
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        visit(T);
    }
}

//非递归后续遍历
void PostOrderTraverse_2(BiTree &T){
    SqStack S;
    InitStack(S);
    BiTree p=T,cur=NULL;
    Push(S,p);
    while(!stackEmpty(S)){
        p=GetTop(S);
        if((p->lchild==NULL && p->rchild==NULL) || (cur==p->lchild || cur==p->rchild)){
            p=Pop(S);
            visit(p);
        }
        else{
            if(p->rchild!=NULL) Push(S,p->rchild);
            if(p->lchild!=NULL) Push(S,p->lchild);
        }
    }
}

int main()
{
    return 0;
}
