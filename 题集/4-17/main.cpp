#include <iostream>
#include <cstdio>
using namespace std;

const int MAXSTRLEN=255;
typedef unsigned char SString[MAXSTRLEN+1];

void Replace(SString &S,SString T,SString V)
{
    int i,j,k;
    for(i=1;i<=S[0];i++)
    {
        for(j=i,k=1;k<=T[0] && S[i]==T[k];k++,j++);//Ѱ����T��ȵ��Ӵ�
        if(k>T[0]){//����ҵ�
            if(T[0]==V[0]){//���T��V������ȣ���ֱ���滻
                for(int l=1;l<=T[0];l++)
                    S[i+l-1]=V[l];
            }
            else if(T[0]<V[0]){//���T��V�̣���T���Ԫ�������ƣ��ٰ��м�Ĳ�����V����
                for(int l=S[0];l>=i+T[0];i--)
                    S[l+V[0]-T[0]]=S[l];
                for(int l=1;l<=V[0];l++)
                    S[i+l-1]=V[l];
            }
            else{//���T��V������T���Ԫ�������ƣ��ٰ��м�Ĳ�����V����
                for(int l=i+V[0];l<=S[0];i++)
                    S[l]=S[l+V[0]-T[0]];
                for(int l=1;l<=V[0];l++)
                    S[i+l-1]=V[l];
            }
        }
    }
}
int main()
{
    //int lens,lent,lenv;
    SString S,T,V;
    S[0]=3;
    S[1]='a';
    S[2]='b';
    S[3]='c';
    T[0]=1;
    T[1]='b';
    V[0]=1;
    V[1]='c';
    printf("%d,%d",(int)T[0],(int)V[0]);
    Replace(S,T,V);
    for(int i=1;i<=3;i++)
        printf("%c",S[i]);
    return 0;
}
