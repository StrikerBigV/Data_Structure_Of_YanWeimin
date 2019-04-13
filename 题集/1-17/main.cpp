#include <iostream>
#include <cstdio>
using namespace std;
int febKM(int k,int m)
{
    int *feb,now;
    int i,j;
    feb=new int[k+1];
    for(i=0;i<k;i++)
    {
        if(i<k-1) feb[i]=0;
        else feb[i]=1;
    }
    for(i=k;i<=m;i++)
    {
        now=0;
        for(j=i-k;j<i;j++)
        {
            now+=feb[j];
        }
        feb[i]=now;
    }
    return feb[m];
}
int main()
{
    int k,m;
    scanf("%d%d",&k,&m);
    printf("%d",febKM(k,m));
    return 0;
}
