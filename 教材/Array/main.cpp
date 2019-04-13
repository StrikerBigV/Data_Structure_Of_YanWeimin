#include <cstdio>
#include <cstdarg>
#include <cstdlib>
using namespace std;

const int MAX_ARRAY_DIM=8;
typedef struct
{
    ElemType *base;// �����ַ
    int dim;//����ά��
    int *bounds;//����ά���ַ��˳����ÿһά��Ԫ�ظ���
    int *constants;//����ӳ����������ַ��˳����ÿһάԪ�ز���
}Array;

// ��ʼ������
bool InitArray(Array &A,int dim,...)
{
    va_list ap;//�����ű䳤��������Ϣ������
    if(dim<1 || dim>MAX_ARRAY_DIM) return false;
    A.dim=dim;
    A.bounds=(int *)malloc(dim*sizeof(int));
    int elemtotal=1;
    va_start(ap,dim);//���ú��ʼ����������
    for(int i=0;i<dim;i++){
        A.bounds[i]=va_arg(ap,int);//��һ���䳤��������һ��ά��
        if(A.bounds[i]<0) return false;
        elemtotal*=A.bounds[i];
    }
    va_end(ap);//���ٲ�������
    A.base=(ElemType*)malloc(elemtotal*sizeof(ElemType));
    A.constants=(int*)malloc(dim*sizeof(int));
    A.constants[dim-1]=1;//�˴�Ӧ����Ԫ�ش�С����дΪ1
    for(int i=dim-2;i>=0;i--)
        A.constants[i]=A.constants[i+1]*A.bounds[i+1];//��ʽ
    return true;
}

//��������
bool DestroyArray(Array &A)
{
    if(!A.base) return false;
    free(A.base);
    if(!A.bounds) return false;
    free(A.bounds);
    if(!A.constants) return false;
    free(A.constants);
    return true;
}

//���ĳԪ�����������Ե�ַoff
bool Locate(Array &A,va_liat ap,int &off)
{
    int ind;
    off=0;
    for(int i=0;i<A.dim;i++){
        ind=va_arg(ap,int);
        if(ind<0 || ind>=A.bounds[i]) return false;
        off+=A.constants[i]*ind;
    }
}

//�����±꣬��ֵ
bool Value(Array &A,ElemType &e,...)
{
    va_list ap;
    bool result;
    int off;
    va_start(ap,e);
    if(!(result=Locate(A,ap,off))) return false;
    e=*(A.base+off);
    return true;
}

//�����±꣬��ֵ
bool Assign(Array &A,ElemType e,...)
{
    va_list ap;
    bool result;
    int off;
    va_start(ap,e);
    if(!(Locate(A,ap,off))) return false;
    *(A.base+off)=e;
    return true;
}

int main()
{
    return 0;
}
