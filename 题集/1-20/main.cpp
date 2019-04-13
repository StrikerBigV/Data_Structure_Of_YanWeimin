#include <iostream>
#include <cstdio>
using namespace std;
int mi(int n,int x)
{
    int res=1;
    for(int i=0;i<n;i++)
        res*=x;
    return res;
}
int cal(int n,int x)
{
    int *a;
    a=new int[n+2];
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int res=a[0];
    for(int i=1;i<=n;i++)
    {
        res+=mi(i,x);
    }
    return res;
}
int main()
{
    int n,x0;
    scanf("%d%d",&n,&x0);
    printf("%d",cal(n,x0));
    return 0;
}
