#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int LIST_INIT_SIZE=100;
const int LISTINCREMENT=10;

typedef struct{
    int *elem;
    int length;
    int listsize;
}SqList;

void InitList(SqList &L)
{
    L.elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
}

//**************************�㷨��ʼ**********************//
//question 1
void intersection_1(SqList &A,SqList &B,SqList &C)
{
    int i=0,j=0,k=0;
    while(i<A.length && j<B.length){
    if(A.elem[i]<B.elem[j]) i++;
    else if(A.elem[i]>B.elem[j]) j++;//�ҵ���һ����ȵ�Ԫ��
    else{
        if(C.length==0){//����ǵ�һ��λ�ã�ֱ�Ӳ���
            C.elem[k++]=A.elem[i];
            C.length++;
        }
        else if(C.elem[C.length-1]!=A.elem[i]){//����λ�ã���C����һ��Ԫ�غ�ĿǰԪ����ͬ��������
            C.elem[k++]=A.elem[i];
            C.length++;
        }
            i++;
        }
    }
}

//question 2
void intersection_2(SqList &A,SqList &B)
{
    int i=0,j=0,k=0;
    while(i<A.length && j<B.length)
    {
        if(A.elem[i]<B.elem[j]) i++;
        else if(A.elem[i]>B.elem[j]) j++;
        else{
            A.elem[k++]=A.elem[i];
            i++;
        }
    }
    A.length=k;
}

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    SqList A,B,C;
    InitList(A);
    InitList(B);
    InitList(C);
    A.length=m;
    B.length=n;
    for(int i=0;i<m;i++)
        scanf("%d",&A.elem[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&B.elem[i]);
    intersection_1(A,B,C);
    for(int i=0;i<C.length;i++)
        printf("%d ",C.elem[i]);
    return 0;
}
