#include <cstdio>
#include <cstdarg>
#include <cstdlib>
using namespace std;

const int MAX_ARRAY_DIM=8;
typedef struct
{
    ElemType *base;// 数组基址
    int dim;//数组维数
    int *bounds;//数组维界基址，顺序存放每一维的元素个数
    int *constants;//数组映像函数常量地址，顺序存放每一维元素步长
}Array;

// 初始化数组
bool InitArray(Array &A,int dim,...)
{
    va_list ap;//定义存放变长参数表信息的数组
    if(dim<1 || dim>MAX_ARRAY_DIM) return false;
    A.dim=dim;
    A.bounds=(int *)malloc(dim*sizeof(int));
    int elemtotal=1;
    va_start(ap,dim);//利用宏初始化参数数组
    for(int i=0;i<dim;i++){
        A.bounds[i]=va_arg(ap,int);//将一个变长参数赋给一个维界
        if(A.bounds[i]<0) return false;
        elemtotal*=A.bounds[i];
    }
    va_end(ap);//销毁参数数组
    A.base=(ElemType*)malloc(elemtotal*sizeof(ElemType));
    A.constants=(int*)malloc(dim*sizeof(int));
    A.constants[dim-1]=1;//此处应该是元素大小，暂写为1
    for(int i=dim-2;i>=0;i--)
        A.constants[i]=A.constants[i+1]*A.bounds[i+1];//公式
    return true;
}

//销毁数组
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

//求出某元素在数组的相对地址off
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

//给出下标，求值
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

//给出下标，赋值
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
