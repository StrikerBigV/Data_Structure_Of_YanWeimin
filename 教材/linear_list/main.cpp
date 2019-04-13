#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

//�õ���һЩ�޹غ���
//�ı����鳤��
template <class T>
void changeLength1D(T *&a,int oldLength,int newLength)
{
    T* temp=new T [newLength];
    int number=min(oldLength,newLength);
    copy(a,a+number,temp);
    delete [] a;
    a=temp;
}

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

//arrayList ����
template <class T>
class arrayList : public linearList<T>{
public:
    //�������������
    arrayList(int LIST_INIT_SIZE = 10);
    ~arrayList() {delete [] elem;}

    //ADT����
    bool listEmpty() {return length == 0;}
    int listLength() {return length;}
    T& getElem(int theIndex) const;
    int locateElem(const T& theElem) const;
    T& priorElem(int theIndex) const;
    T& nextElem(int theIndex) const;
    void listInsert(int theIndex,const T& theElem);
    void listDelete(int theIndex);
protected:
    //Ԫ�ض���
    T* elem;//���Ա��׵�ַ
    int length;//��ǰ���Ա���
    int listSize;//��������
};

//����ʵ��
//���캯��
template <class T>
arrayList<T> ::arrayList(int LIST_INIT_SIZE)
{
    if(LIST_INIT_SIZE<1) {cout<<"listSize must be >= 0";}
    listSize=LIST_INIT_SIZE;
    elem=new T[listSize];
    length=0;
}

//�õ�Ԫ��
template <class T>
T& arrayList<T>::getElem(int theIndex) const
{
    if(theIndex<0 || theIndex>=length) {cout<<"theIndex is wrong"; return -1;}
    return elem[theIndex];
}

//����Ԫ��λ��
template <class T>
int arrayList<T> ::locateElem(const T& theElem) const
{
    int index=(int) (find(elem,elem+length,theElem) - elem);
    if(index==length) return -1;
    else return index;
}

//�õ�ǰ��
template <class T>
T& arrayList<T>::priorElem(int theIndex) const
{
    if(theIndex<=0) {cout<<"theIndex must be > 0"; return -1;}
    return elem[theIndex-1];
}

//�õ����
template <class T>
T& arrayList<T>::nextElem(int theIndex) const
{
    if(theIndex>=length-1) {cout<<"theIndex must be < length-1"; return -1;}
    return elem[theIndex+1];
}

//����Ԫ��
template <class T>
void arrayList<T>::listInsert(int theIndex,const T& theElem)
{
    if(theIndex<0 || theIndex>length) {cout<<"theIndex must be suitable"; return -1;}
    if(length>listSize){
        changeLength1D(theElem,length,2*length);
        listSize*=2;
    }//��Ԫ�ظ������������������������ӱ�
    copy_backward(elem+theIndex,elem+length,elem+length+1);//��theIndex�����һλȫ������һλ
    elem[theIndex]=theElem;
    length++;
}

//ɾ��Ԫ��
template <class T>
void arrayList<T> ::listDelete(int theIndex)
{
    if(theIndex<0 || theIndex>length) {cout<<"theIndex must be suitable"; return -1;}
    copy(elem+theIndex+1,elem+length,elem+theIndex);//��theIndex��ʼȫ������һλ
}

//�鲢�����ǵݼ�����
template <class T>
void mergeList(arrayList La,arrayList Lb,arrayList &Lc)
{
    T* pa=La.elem,T* pb=La.elem;//two pointers,������ָ��ֱ�ָ��a,b��������
    pc=Lc.listSize=Lc.length=La.length+Lb.length;
    Lc.elem=new T[Lc.listSize];//����c���������ʹ�С
    while((pa<=La.elem+La.length-1) && (pb<=Lb.elem+Lb.length-1))
    {
        if(*pa<=*pb) *pc++=*pa++;
        else *pc++=*pb++;
    }//�ֱ�Ƚ�aָ����bָ����ָ���Ĵ�С��С�ĸ���c����
    while(pa<La.elem+La.length-1) *pc++=*pa++;
    while(pb<La.elem+La.length-1) *pc++=*pb++;//ʣ����ȫ������c����
}
int main()
{
    return 0;
}
