#include <iostream>
#include <cstdio>
using namespace std;

//ADT of linearList
template <class T>
class linearList
{
    virtual ~linearList() {};
    virtual bool listEmpty() const = 0;//判空
    virtual int listLength() const = 0;//返回表长
    virtual T& getElem(int theIndex) const = 0;//得到元素
    virtual int locateElem(const T& theElem) const = 0;//查找元素位置
    virtual T& priorElem(int theIndex) const = 0;//得到前驱
    virtual T& nextElem(int theIndex) const = 0;//得到后继
    virtual void listInsert(int theIndex,const T& theElem) = 0;//插入元素
    virtual void listDelete(int theIndex) = 0;//删除元素
};

//链表结点定义
template <class T>
struct LNode
{
    T elem;//数据域
    LNode<T> *next;//指针域
    //实现方法
    LNode () {}
    LNode (const T& theElem){
        this->elem=theElem;}
    LNode (const T& theElem,LNode<T>* next){
        this->elem=theElem;
        this->next=next;}
};

//链表定义
template <class T>
class linkedList : public linearList<T>{
public:
    //构造和析构函数
    linkedList(int LIST_INIT_SIZE=10);
    ~linkedList();

    //ADT实现方法
    bool listEmpty()const {return length==0;}
    int listLength()const {return length;}
    T& getElem(int theIndex)const;
    int locateElem(const T& theElem)const;
    T& priorElem(int theIndex)const;
    T& nextElem(int theIndex)const;
    void listInsert(int theIndex,const T& theElem);
    void listDelete(int theIndex);
    void createList(int n);

protected:
    //元素定义
    LNode<T>* firstNode;//线性表首结点
    int length;//链表长度
};

//定义实现
//构造函数
template <class T>
linkedList<T> :: linkedList(int LIST_INIT_SIZE)
{
    if(LIST_INIT_SIZE<1) {cout<<"LIST_INIT_SIZE must be >= 1";}
    firstNode->next=NULL;
    length=0;
}

//复制构造函数
template <class T>
linkedList<T> :: ~linkedList()
{
    while(firstNode!=NULL)
    {
        //不停删除首结点
        LNode<T>* nextNode=firstNode->next;
        delete firstNode;
        firstNode=nextNode;
    }
}

//得到元素
template <class T>
T& linkedList<T> :: getElem(int theIndex) const
{
    LNode<T>* curNode=firstNode;
    if(theIndex<0) {cout<<"theIndex must be >= 0"; return -1;}
    for(int i=0;i<theIndex;i++)
    {
        curNode=curNode->next;
    }
    return curNode->elem;
}

//查找元素位置
template <class T>
int linkedList<T> :: locateElem(const T& theElem) const
{
    int location=0;
    LNode<T>* curNode=firstNode;
    while(curNode!=NULL && curNode->elem!=theElem)
    {
        curNode=curNode->next;
        location++;
    }
    if(curNode==NULL) return -1;
    else return location;
}

//得到前驱
template <class T>
T& linkedList<T> :: priorElem(int theIndex) const
{
    T res;
    if(theIndex<=0 || theIndex>length-1) {cout<<"theIndex must be suitable"; return -1;}
    LNode<T>* curNode=firstNode;
    if(theIndex==1) return firstNode->elem;
    for(int i=0;i<theIndex-1;i++)
    {
        curNode=curNode->next;
    }
    res=curNode->elem;
    return res;
}

//得到后继
template <class T>
T& linkedList<T> :: nextElem(int theIndex) const
{
    T res;
    if(theIndex<0 || theIndex>=length-1) {cout<<"theIndex must be suitable"; return -1;}
    LNode<T>* curNode=firstNode;
    for(int i=0;i<=theIndex;i++)
    {
        curNode=curNode->next;
    }
    res=curNode->elem;
    return res;
}

//插入元素
template <class T>
void linkedList<T> :: listInsert(int theIndex,const T& theElem)
{
    if(theIndex<0 || theIndex>length-1) {cout<<"theIndex must be suitable"; return -1;}
    LNode<T>* insertNode=new LNode<T>(theElem);
    LNode<T>* curNode=firstNode;
    if(theIndex==0)
    {
        insertNode->next=firstNode;
        firstNode=insertNode;
        length++;
    }//0没有前驱
    else
    {
        for(int i=0;i<theIndex-1;i++)
        {
            curNode=curNode->next;
        }//找到前驱
        insertNode->next=curNode->next->next;
        curNode->next=insertNode;
        length++;
    }
}

//删除元素
template <class T>
void linkedList<T> :: listDelete(int theIndex)
{
    if(theIndex<0 || theIndex>length-1) {cout<<"theIndex must be suitable"; return -1;}
    LNode<T>* deleteNode;
    LNode<T>* curNode=firstNode;
    if(theIndex==0)
    {
        deleteNode=firstNode;
        firstNode=firstNode->next;
    }
    else
    {
        for(int i=0;i<theIndex-1;i++)
        {
            curNode=curNode->next;
        }
        deleteNode=curNode->next;
        curNode->next=curNode->next->next;
    }
    delete deleteNode;
    length--;
}

//建立单链表
template <class T>
void createList(int n, LNode<T>* &L)
{
    //逆位序输入n个元素的值，建立单链表
    L=new LNode<T>;
    L->next=NULL;
    for(int i=n-1;i>=0;i--)
    {
        LNode<T>* inputNode=new LNode<T>;
        scanf(inputNode->elem);
        inputNode->next=L->next;
        L->next=inputNode;
    }
}

//合并两个有序链表
template <class T>
void MergeList(LNode<T>* &La, LNode<T>* &Lb, LNode<T>* &Lc)
{
    LNode<T>* pa=La->next;
    LNode<T>* pb=Lb->next;
    LNode<T>* pc=La;
    Lc=pa;
    while(pa && pb)
    {
        if(pa->elem <= pb->elem)
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else
        {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    pc->next=pa ? pa : pb;
    delete pb;
}
int main()
{
    return 0;
}
