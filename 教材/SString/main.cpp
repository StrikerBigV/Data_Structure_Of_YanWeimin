#include <iostream>
#include <cstdio>
using namespace std;

const int MAXSTRLEN=255;
typedef unsigned char SString[MAXSTRLEN+1];//0��λװ���ĳ���

// �ַ�ƴ��
void Concat(SString &T,SString S1,SString S2)
{
    if(S1[0]+S2[0]<=MAXSTRLEN){
        T[0]=S1[0]+S2[0];
        for(int i=1;i<S1[0];i++)
            T[i]=S1[i];
        for(int i=S1[0];i<T[0];i++)
            T[i]=S2[i-S1[0]];
    }
    else if(S1[0]<MAXSTRLEN){//�ض�
        T[0]=MAXSTRLEN;
        for(int i=1;i<=S1[0];i++)
            T[i]=S1[i];
        for(int i=S1[0];i<=MAXSTRLEN;i++)
            T[i]=S2[i-S1[0]];
    }
    else{//ֻ�е�һ���ַ���
        T[0]=MAXSTRLEN;
        for(int i=1;i<=MAXSTRLEN;i++)
            T[i]=S1[i];
    }
}

//�����Ӵ�
bool SubString(SString &T,SString S,int pos,int len)
{
    if(pos<0 || pos>S[0] || len<0 || pos+len>S[0]+1) return false;
    else{
        T[0]=len;
        for(int i=1;i<=len;i++)
            T[i]=S[pos+i-1];
        return true;
    }
}

//����ģʽƥ���㷨
int Index(SString S,SString T,int pos)
{//���ڣ��򷵻��ִ���λ��λ�ã����򷵻�0
    int i=pos,j=1;
    while(i<=S[0] && j<=T[0])
    {
        if(S[i]==T[i]) {i++;j++}
        else{
            i=i-j+2;
            j=1;
        }
    }
    if(j>T[0]) return i-T[0];
    else return 0;
}

int main()
{
    return 0;
}
