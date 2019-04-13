#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAX_VERTEX_NUM=20;
typedef struct ArcBox{//弧结点
    int tailvex,headvex;//弧尾和弧头结点在顶点结点数组的位置
    ArcBox *hlink,*tlink;//分别指向以该弧头或弧尾为同一个弧头或弧尾的下一条弧
    InfoType *info;
}ArcBox;
typedef struct VexNode{
    int data;
    ArcBox *firstin,*firstout;//分别指向以该顶点为弧头或弧尾的第一条弧
}VexNode;
typedef struct{
    VexNode xlist[MAX_VERTEX_NUM];
    int vexnum,arcnum;
}OLDGraph;

bool CreateDG(OLDGraph &G){
    int IncInfo;
    scanf("%d%d%d",&G.vexnum,&G.arcnum,&IncInfo);
    for(int i=0;i<G.vexnum;i++)
    {
        scanf("%d",xlist[i].data);
        xlist[i].firstin=xlist[i].firstout=NULL:
    }
    for(int k=0;k<G.arcnum;k++)
    {
        int i,j,v1,v2;
        scanf("%d%d",&v1,&v2);
        i=LocateVex(G,v1);
        j=LocateVex(G,v2);
        ArcBox *p=(ArcBox *)malloc(sizeof(ArcBox));
        *p={i,j,G.xlist[j].firstin,G.xlist[i].firstout,NULL}
        G.xlist[j].firstin=G.xlist[i].firstout=p;
        if(IncInfo) cin>>(*p->info);
    }
}

int main()
{
    return 0;
}
