#include <iostream>
#include <cstdio>
using namespace std;

//ADT of linearList
template <class T>
class linearList
{
    virtual ~linearList() {};
    virtual bool listEmpty() const = 0;//�п�
    virtual int listLength() const = 0;//���ر�
    virtual T& getElem(int theIndex) const = 0;//�õ�Ԫ��
    virtual int locateElem(const T& theElem) const = 0;//����Ԫ��λ��
    virtual T& priorElem(int theIndex) const = 0;//�õ�ǰ��
    virtual T& nextElem(int theIndex) const = 0;//�õ����
    virtual void listInsert(int theIndex,const T& theElem) = 0;//����Ԫ��
    virtual void listDelete(int theIndex) = 0;//ɾ��Ԫ��
};

//�����㶨��
template <class T>
struct LNode
{
    T elem;//������
    LNode<T> *next;//ָ����
    //ʵ�ַ���
    LNode () {}
    LNode (const T& theElem){
        this->elem=theElem;}
    LNode (const T& theElem,LNode<T>* next){
        this->elem=theElem;
        this->next=next;}
};

//������
template <class T>
class linkedList : public linearList<T>{
public:
    //�������������
    linkedList(int LIST_INIT_SIZE=10);
    ~linkedList();

    //ADTʵ�ַ���
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
    //Ԫ�ض���
    LNode<T>* firstNode;//���Ա��׽��
    int length;//������
};

//����ʵ��
//���캯��
template <class T>
linkedList<T> :: linkedList(int LIST_INIT_SIZE)
{
    if(LIST_INIT_SIZE<1) {cout<<"LIST_INIT_SIZE must be >= 1";}
    firstNode->next=NULL;
    length=0;
}

//���ƹ��캯��
template <class T>
linkedList<T> :: ~linkedList()
{
    while(firstNode!=NULL)
    {
        //��ͣɾ���׽��
        LNode<T>* nextNode=firstNode->next;
        delete firstNode;
        firstNode=nextNode;
    }
}

//�õ�Ԫ��
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

//����Ԫ��λ��
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

//�õ�ǰ��
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

//�õ����
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

//����Ԫ��
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
    }//0û��ǰ��
    else
    {
        for(int i=0;i<theIndex-1;i++)
        {
            curNode=curNode->next;
        }//�ҵ�ǰ��
        insertNode->next=curNode->next->next;
        curNode->next=insertNode;
        length++;
    }
}

//ɾ��Ԫ��
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

//����������
template <class T>
void createList(int n, LNode<T>* &L)
{
    //��λ������n��Ԫ�ص�ֵ������������
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

//�ϲ�������������
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
