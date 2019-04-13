#include <iostream>
#include <cstdio>
using namespace std;
const int arrsize=10010;
const int MAXINT=100000000;
int main()
{
    int a[arrsize],n,jc[arrsize],mi[arrsize];
    jc[0]=1;
    mi[0]=1;
    scanf("%d",&n);
    if(n>arrsize) return -1;;
    for(int i=1;i<n;i++)
    {
        jc[i]=jc[i-1]*i;
    }
    for(int i=1;i<n;i++)
    {
        mi[i]*=2;
    }
    for(int i=0;i<n;i++)
    {
        if(jc[i]*mi[i]>MAXINT) return -1;;
        a[i]=jc[i]*mi[i];
    }
    return 0;
}
