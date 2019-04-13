#include <cstdio>
#include <cstdlib>
using namespace std;

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
//*******************************************************************//

//****************************���Ŀ�ʼ******************************//
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//���ʺ���
void visit(BiTree &T){
    printf("%c",T->data);
}

// ����������
void CreateBiTree(BiTree &T){
    char ch;
    scanf("%c",&ch);
    if(ch==' ') T=NULL;//����
    else{
        T=(BiTNode*)malloc(sizeof(BiTNode));
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);//�ݹ鹹����������
    }
}

//�ݹ��������
void PreOrderTraverse(BiTree &T){
    if(T){
        visit(T);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

//�ǵݹ����������һ
//�Ե�ǰ���Ϊ��Ҫ�������
void PreOrderTraverse_2(BiTree T){
    SqStack S;
    InitStack(S);
    BiTree p=T;
    while(p || !stackEmpty()){//��ǰ�����ڣ�����ջ���գ����򣬽���ѭ��
        if(p){//��ǰ������
            visit(p);//����
            Push(S,p);//��ջ
            p=p->lchild;//����ǰ���������
        }
        else{//��ǰ��㲻����
            p=Pop(S);//��ջ
            p=p->rchild;//����ջ�����������
        }
    }
}

//�ǵݹ������������
//��ջΪ��Ҫ�������
void PreOrderTraverse_3(BiTree T){
    SqStack S;
    InitStack(S);
    BiTree p=T;
    Push(S,p);//����ջ���൱������ջ�Ĵ���
    while(!stackEmpty(S)){//ջ���գ�����ѭ������
        while(p=GetTop(S)){//ջ�������ڣ�һֱ����������ֱ��Ҷ�ӽ��
            visit(p);//����
            Push(S,p->lchild);//ջ���������������ջ
        }
        p=Pop(S);//��ָ����ջ
        if(!stackEmpty(S)){
            p=Pop(S);
            Push(S,p->rchild);//�ɺ���ǰ���ν�����������ջ
        }
    }
}

//�ݹ��������
//��ݹ��������ֻ�з�������˳��ͬ
void InOrderTraverse(BiTree &T){
    if(T){
        InOrderTraverse(T->lchild);
        visit(T);
        InOrderTraverse(T->rchild);
    }
}

//�ǵݹ����������һ
//��ǵݹ��������ֻ�з������˳��ͬ
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

//�ǵݹ������������
//ͬ��
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

//�ݹ�������
void PostOrderTraverse(BiTree &T){
    if(T){
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        visit(T);
    }
}

//�ǵݹ��������
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
