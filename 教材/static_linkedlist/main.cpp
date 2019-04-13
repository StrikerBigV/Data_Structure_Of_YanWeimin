#include <iostream>
#include <cstdio>
using namespace std;

const int MAXSIZE=1000;

//静态链表类
template <class T>
class staticLinkedList{

public:
//静态链表元素结构体定义
struct staticElem
{
    T data;
    int cur;
}component,SLinkList[MAXSIZE];

int locateElem(staticElem S[MAXSIZE],const T& theElem)const;//查找元素

void InitSpace(staticElem space[MAXSIZE]);//将数组空间初始化为链表
int Malloc(staticElem space[MAXSIZE])const;//从备用链表申请结点，类似于c语言中的malloc
void Free(staticElem space[MAXSIZE],int k);//将空闲链表链接到备用链表，类似于c语言中的free

void difference(staticElem space[MAXSIZE],int &S);//求集合(A-B)U(B-A)
};

//查找元素
template <class T>
int staticLinkedList<T> ::locateElem(staticElem S[MAXSIZE] ,const T& theElem) const
{
    int position=S[0].cur;
    while(position && S[position].data!=theElem)
    {
        position=S[position].cur;
    }
    return position;
}

//将数组空间初始化为链表
template <class T>
void staticLinkedList<T> ::InitSpace(staticElem space[MAXSIZE])
{
    for(int i=0;i<MAXSIZE-1;i++)
    {
        space[i].cur=i+1;
    }
    space[MAXSIZE-1].cur=0;
}

//从备用链表申请结点，类似于c语言中的malloc
template <class T>
int staticLinkedList<T> ::Malloc(staticElem space[MAXSIZE])const
{
    int i=space[0].cur;
    if(space[0].cur) space[0].cur=space[i].cur;//若链表非空，则将头结点指向头结点原指向下一个的指向的元素，原下一个元素从链表脱落
    return i;
}

//将空闲结点回收到备用链表
template <class T>
void staticLinkedList<T> ::Free(staticElem space[MAXSIZE],int k)
{
    space[k].cur=space[0].cur;
    space[0].cur=k;
}

//求集合(A-B)U(B-A)
template <class T>
void staticLinkedList<T>::difference(staticElem space[MAXSIZE],int &S)
{
    //依次输入A集合中的元素，建立链表，头结点为S，再依次输入B集合中的元素，若S链表中没有该元素，则插入；若有，则删除
    InitSpace(space);//初始化备用链表
    S=Malloc(space);//申请头结点
    int tail=S;//尾结点初始化为头结点；
    //构建S集合
    int m,n,b;//A集合元素个数，B集合元素个数，B集合元素
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
    {
        int j=Malloc(space);
        scanf("%d",space[j].data);//输入A元素中的值
        space[tail].cur=j;//插入链表
        tail=j;//更新尾结点
    }
    space[tail].cur=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b);
        int pre=S,now=space[S].cur;//分别指向头结点和第一个结点
        while(now!=space[tail].cur && space[now].data!=b)
        {
            pre=now;
            now=space[now].cur;
        }//寻找有无与b相等的元素
        if(now==space[tail].cur)
        {
            //若不存在该元素
            //插入链表末尾
            int j=Malloc(space);
            space[j].data=b;
            space[j].cur=space[tail].cur;
            space[tail].cur=j;
        }
        else
        {
            space[pre].cur=space[now].cur;
            Free(space,now);//从S链表中删除该元素
            if(now==tail) tail=pre;//若删除的是尾结点，则令pre为尾结点
        }
    }
}
int main()
{
    return 0;
}
