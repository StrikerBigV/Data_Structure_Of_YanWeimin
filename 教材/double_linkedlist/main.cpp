#include <iostream>
#include <cstdio>
using namespace std;

template <class T>
struct DuLNode
{
    T data;
    DuLNode<T>* prior;//前驱指针
    DuLNode<T>* next;//后继指针
};

//简单类定义，主要描述插入和删除算法
template <class T>
class double_linkedList
{
    void listInsert(DuLNode<T>* &L,int theIndex,const T& theElem);
    void listDelete(DuLNode<T>* &L,int theIndex,const T& tehElem);
    DuLNode<T>* getElem(DuLNode<T>* &L,int theIndex)const;
};

//得到元素
template <class T>
DuLNode<T>* double_linkedList<T> :: getElem(DuLNode<T>* &L,int theIndex) const
{
    DuLNode<T>* curNode=L;
    if(theIndex<0) {cout<<"theIndex must be >= 0"; return -1;}
    for(int i=0;i<theIndex;i++)
    {
        curNode=curNode->next;
    }
    return curNode;
}

//插入
template <class T>
void double_linkedList<T> :: listInsert(DuLNode<T>* &L,int theIndex,const T& theElem)
{
    DuLNode<T>* p=getElem(L,theIndex);
    if(!p) {cout<<"theIndex must be >= 0"; return -1;}
    DuLNode<T>* insertNode=new DuLNode<T>;
    insertNode->data=theElem;
    insertNode->prior=p->prior;
    p->prior->next=insertNode;
    insertNode->next=p;
    p->prior=insertNode;
}

//删除
template <class T>
void double_linkedList<T> :: listDelete(DuLNode<T>* &L,int theIndex,const T& theElem)
{
    DuLNode<T>* p=getElem(L,theIndex);
    if(!p) {cout<<"theIndex must be >= 0"; return -1;}
    theElem=p->data;
    p->prior->next=p->next;
    p->next->prior=p->prior;
    delete p;
}
int main()
{
    return 0;
}
