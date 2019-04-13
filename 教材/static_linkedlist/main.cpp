#include <iostream>
#include <cstdio>
using namespace std;

const int MAXSIZE=1000;

//��̬������
template <class T>
class staticLinkedList{

public:
//��̬����Ԫ�ؽṹ�嶨��
struct staticElem
{
    T data;
    int cur;
}component,SLinkList[MAXSIZE];

int locateElem(staticElem S[MAXSIZE],const T& theElem)const;//����Ԫ��

void InitSpace(staticElem space[MAXSIZE]);//������ռ��ʼ��Ϊ����
int Malloc(staticElem space[MAXSIZE])const;//�ӱ������������㣬������c�����е�malloc
void Free(staticElem space[MAXSIZE],int k);//�������������ӵ���������������c�����е�free

void difference(staticElem space[MAXSIZE],int &S);//�󼯺�(A-B)U(B-A)
};

//����Ԫ��
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

//������ռ��ʼ��Ϊ����
template <class T>
void staticLinkedList<T> ::InitSpace(staticElem space[MAXSIZE])
{
    for(int i=0;i<MAXSIZE-1;i++)
    {
        space[i].cur=i+1;
    }
    space[MAXSIZE-1].cur=0;
}

//�ӱ������������㣬������c�����е�malloc
template <class T>
int staticLinkedList<T> ::Malloc(staticElem space[MAXSIZE])const
{
    int i=space[0].cur;
    if(space[0].cur) space[0].cur=space[i].cur;//������ǿգ���ͷ���ָ��ͷ���ԭָ����һ����ָ���Ԫ�أ�ԭ��һ��Ԫ�ش���������
    return i;
}

//�����н����յ���������
template <class T>
void staticLinkedList<T> ::Free(staticElem space[MAXSIZE],int k)
{
    space[k].cur=space[0].cur;
    space[0].cur=k;
}

//�󼯺�(A-B)U(B-A)
template <class T>
void staticLinkedList<T>::difference(staticElem space[MAXSIZE],int &S)
{
    //��������A�����е�Ԫ�أ���������ͷ���ΪS������������B�����е�Ԫ�أ���S������û�и�Ԫ�أ�����룻���У���ɾ��
    InitSpace(space);//��ʼ����������
    S=Malloc(space);//����ͷ���
    int tail=S;//β����ʼ��Ϊͷ��㣻
    //����S����
    int m,n,b;//A����Ԫ�ظ�����B����Ԫ�ظ�����B����Ԫ��
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
    {
        int j=Malloc(space);
        scanf("%d",space[j].data);//����AԪ���е�ֵ
        space[tail].cur=j;//��������
        tail=j;//����β���
    }
    space[tail].cur=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b);
        int pre=S,now=space[S].cur;//�ֱ�ָ��ͷ���͵�һ�����
        while(now!=space[tail].cur && space[now].data!=b)
        {
            pre=now;
            now=space[now].cur;
        }//Ѱ��������b��ȵ�Ԫ��
        if(now==space[tail].cur)
        {
            //�������ڸ�Ԫ��
            //��������ĩβ
            int j=Malloc(space);
            space[j].data=b;
            space[j].cur=space[tail].cur;
            space[tail].cur=j;
        }
        else
        {
            space[pre].cur=space[now].cur;
            Free(space,now);//��S������ɾ����Ԫ��
            if(now==tail) tail=pre;//��ɾ������β��㣬����preΪβ���
        }
    }
}
int main()
{
    return 0;
}
