#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

//用到的一些无关函数
//改变数组长度
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
    virtual bool listEmpty() const = 0;//判空
    virtual int listLength() const = 0;//返回表长
    virtual T& getElem(int theIndex) const = 0;//得到元素
    virtual int locateElem(const T& theElem) const = 0;//查找元素位置
    virtual T& priorElem(int theIndex) const = 0;//得到前驱
    virtual T& nextElem(int theIndex) const = 0;//得到后继
    virtual void listInsert(int theIndex,const T& theElem) = 0;//插入元素
    virtual void listDelete(int theIndex) = 0;//删除元素
};

//arrayList 数组
template <class T>
class arrayList : public linearList<T>{
public:
    //构造和析构函数
    arrayList(int LIST_INIT_SIZE = 10);
    ~arrayList() {delete [] elem;}

    //ADT方法
    bool listEmpty() {return length == 0;}
    int listLength() {return length;}
    T& getElem(int theIndex) const;
    int locateElem(const T& theElem) const;
    T& priorElem(int theIndex) const;
    T& nextElem(int theIndex) const;
    void listInsert(int theIndex,const T& theElem);
    void listDelete(int theIndex);
protected:
    //元素定义
    T* elem;//线性表首地址
    int length;//当前线性表长度
    int listSize;//数组容量
};

//定义实现
//构造函数
template <class T>
arrayList<T> ::arrayList(int LIST_INIT_SIZE)
{
    if(LIST_INIT_SIZE<1) {cout<<"listSize must be >= 0";}
    listSize=LIST_INIT_SIZE;
    elem=new T[listSize];
    length=0;
}

//得到元素
template <class T>
T& arrayList<T>::getElem(int theIndex) const
{
    if(theIndex<0 || theIndex>=length) {cout<<"theIndex is wrong"; return -1;}
    return elem[theIndex];
}

//查找元素位置
template <class T>
int arrayList<T> ::locateElem(const T& theElem) const
{
    int index=(int) (find(elem,elem+length,theElem) - elem);
    if(index==length) return -1;
    else return index;
}

//得到前驱
template <class T>
T& arrayList<T>::priorElem(int theIndex) const
{
    if(theIndex<=0) {cout<<"theIndex must be > 0"; return -1;}
    return elem[theIndex-1];
}

//得到后继
template <class T>
T& arrayList<T>::nextElem(int theIndex) const
{
    if(theIndex>=length-1) {cout<<"theIndex must be < length-1"; return -1;}
    return elem[theIndex+1];
}

//插入元素
template <class T>
void arrayList<T>::listInsert(int theIndex,const T& theElem)
{
    if(theIndex<0 || theIndex>length) {cout<<"theIndex must be suitable"; return -1;}
    if(length>listSize){
        changeLength1D(theElem,length,2*length);
        listSize*=2;
    }//若元素个数超过容量，则数组容量加倍
    copy_backward(elem+theIndex,elem+length,elem+length+1);//从theIndex到最后一位全部右移一位
    elem[theIndex]=theElem;
    length++;
}

//删除元素
template <class T>
void arrayList<T> ::listDelete(int theIndex)
{
    if(theIndex<0 || theIndex>length) {cout<<"theIndex must be suitable"; return -1;}
    copy(elem+theIndex+1,elem+length,elem+theIndex);//从theIndex开始全部左移一位
}

//归并两个非递减数组
template <class T>
void mergeList(arrayList La,arrayList Lb,arrayList &Lc)
{
    T* pa=La.elem,T* pb=La.elem;//two pointers,用两个指针分别指向a,b两个数组
    pc=Lc.listSize=Lc.length=La.length+Lb.length;
    Lc.elem=new T[Lc.listSize];//赋给c数组容量和大小
    while((pa<=La.elem+La.length-1) && (pb<=Lb.elem+Lb.length-1))
    {
        if(*pa<=*pb) *pc++=*pa++;
        else *pc++=*pb++;
    }//分别比较a指针与b指针所指数的大小，小的赋给c数组
    while(pa<La.elem+La.length-1) *pc++=*pa++;
    while(pb<La.elem+La.length-1) *pc++=*pb++;//剩余数全部赋给c数组
}
int main()
{
    return 0;
}
