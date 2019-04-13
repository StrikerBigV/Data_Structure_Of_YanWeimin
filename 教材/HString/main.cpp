#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct
{
    char* ch;
    int length;
}HString;

void StrAssign(HString &T,char *chars);//生成值为字符常量chars的变量T
int StrLength(HString S);//返回字符串长度
int StrCompare(HString S,HString T);//比较S与T的大小，S>T返回>0，S<T返回<0，S==T返回0
void ClearString(HString &S);//清空字符串
void Concat(HString &T,HString S1,HString S2);//拼接两字符串
bool SubString(HString &T,HString S,int pos,int len);//得到在pos位置开始长度为len的字符串
bool StrInsert(HString &S,int pos,HString T);//在字符串S的pos位置开始插入字符串T

//算法实现
void StrAssign(HString &T,char *chars)
{
    if(!T.ch) free(T.ch);//释放T中原空间
    int i=0;
    char *c=chars;
    while(*c){
        c++;
        i++;
    }//求chars长度
    if(!i){T.ch=NULL;T.length=0;}//长度为0，T为空字符串
    else{//否则
        T.ch=(char*)malloc(i*sizeof(char));//申请i个字符空间
        for(int j=0;j<i;j++)
        {
            T.ch[j]=chars[j];
        }//赋值
        T.length=i;
    }
}

int StrLength(HString S)
{
    return S.length;
}

int StrCompare(HString S,HString T)
{
    int i;
    for(i=0;i<S.length && i<T.length;i++)
    {
        if(S.ch[i]!=T.ch[i]) return S.ch[i]-T.ch[i];
    }
    return S.length-T.length;
}

void ClearString(HString &S)
{
    if(!S.ch){
        free(S.ch);
        S.ch=NULL;
    }
    S.length=0;
}

void Concat(HString &T,HString S1,HString S2)
{
    if(!T.ch) free(T.ch);
    T.ch=(char*)malloc((S1.length+S2.length)*sizeof(char));
    for(int i=0;i<S1.length;i++)
    {
        T.ch[i]=S1.ch[i];
    }
    for(int i=S1.length;i<S1.length+S2.length;i++)
    {
        T.ch[i]=S2.ch[i-S1.length];

    }
    T.length=S1.length+S2.length;
}

bool SubString(HString &T,HString S,int pos,int len)
{
    if(pos<0 || pos>S.length || len<0 || pos+len>S.length+1) return false;
    if(T.ch) free(T.ch);
    if(!len) {T.ch=NULL;T.length=0;}
    else{
        T.ch=(char*)malloc(len*sizeof(char));
        for(int i=0;i<len;i++)
        {
            T.ch[i]=S.ch[i+pos];
        }
        T.length=len;
    }
    return true;
}

bool StrInsert(HString &S,int pos,HString T)
{
    if(pos<0 || pos>S.length+1) return false;
    else{
        S.ch=(char*)realloc(S.ch,(S.length+T.length)*sizeof(char));
        for(int i=S.length-1;i>=pos;i--)
            S.ch[i+T.length]=S.ch[i];
        for(int i=pos-1;i<pos+T.length-1;i++)
            S.ch[i]=T.ch[i-pos+1];
        S.length+=T.length;
    }
    return true;
}

int main()
{
    return 0;
}
