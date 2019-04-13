#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int INFINITY=INT_MAX;
const MAX_VERTEX_NUM=20;
typedef enum{DG,DN,UDG,UDN} GraphKind;
typedef struct ArcCell{
    int adj;//对于无权图，0为不邻接，1为邻接；对于有权图，为其权值
    InfoType* info;//弧的相关信息指针
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct{
    int vexs[MAX_VERTEX_NUM];//顶点向量
    AdjMatrix arcs;//弧邻接矩阵
    int vexnum,arcnum;//顶点数和弧数
    GraphKind kind;//图的种类，0~3分别代表有向图、有向网、无向图、无向网
}MGraph;

int LocateVex(MGraph G,VertexType v){
    int n=MGraph.vexnum;
    for(int i=0;i<n;i++)
    {
        if(MGraph.vexs[i]==v)
            return i;
    }
}

int First_Adj(MGrpah G,VertexType v){
    int n=MGraph.vexnum,i,j;
    for(i=0;i<n;i++)
    {
        if(MGraph.vexs[i]==v)
            break;
    }
    for(j=0;j<n;j++)
    {
        if(MGraph.arcs[i][j]==1)//对于无权图如此，有权图则改为!=INFINITY
            break;
    }
    return j;
}

bool CreateGraph(MGraph &G){
    cin>>G.kind;
    switch(G.kind){
        case DG:    return CreateDG(G);
        case DN:    return CreateDN(G);
        case UDG:   return CreateUDG(G);
        case UDN:   return CreateUDN(G);
        default:    return false;
    }
}

bool CreateDG(MGraph &G){
    int IncInfo;//是否包含信息
    scanf("%d%d%d",&G.vexnum,&G.arcnum,&IncInfo);
    for(int i=0;i<G.vexnum;i++)
        scanf("%d",G.vexs[i]);//构建顶点向量
    for(int i=0;i<G.vexnum;i++)
        for(int j=0;j<G.vexnum;j++)
        {
            G.arcs[i][j]={0,NULL};
        }//初始化有向图弧矩阵
    int v1,v2;
    for(int k=0;k<G.arcnum;i++)
    {
        scanf("%d%d",&v1,&v2);
        int i,j;
        i=LocateVex(G,v1),j=LocateVex(G,v2);
        G.arcs[i][j].adj=1;
        if(IncInfo) cin>>G.arcs[i][j].info;
    }
    return true;
}

bool CreateDN(MGraph &G){
    int IncInfo;//是否包含信息
    scanf("%d%d%d",&G.vexnum,&G.arcnum,&IncInfo);
    for(int i=0;i<G.vexnum;i++)
        scanf("%d",G.vexs[i]);//构建顶点向量
    for(int i=0;i<G.vexnum;i++)
        for(int j=0;j<G.vexnum;j++)
        {
            G.arcs[i][j]={0,NULL};
        }//初始化有向网弧矩阵
    int v1,v2,weight;
    for(int k=0;k<G.arcnum;i++)
    {
        scanf("%d%d%d",&v1,&v2,&weight);
        int i,j;
        i=LocateVex(G,v1),j=LocateVex(G,v2);
        G.arcs[i][j].adj=weight;
        if(IncInfo) cin>>G.arcs[i][j].info;
    }
    return true;
}

bool CreateUDG(MGraph &G){
    int IncInfo;//是否包含信息
    scanf("%d%d%d",&G.vexnum,&G.arcnum,&IncInfo);
    for(int i=0;i<G.vexnum;i++)
        scanf("%d",G.vexs[i]);//构建顶点向量
    for(int i=0;i<G.vexnum;i++)
        for(int j=0;j<G.vexnum;j++)
        {
            G.arcs[i][j]={0,NULL};
        }//初始化无向图弧矩阵
    int v1,v2;
    for(int k=0;k<G.arcnum;i++)
    {
        scanf("%d%d",&v1,&v2);
        int i,j;
        i=LocateVex(G,v1),j=LocateVex(G,v2);
        G.arcs[i][j].adj=1;
        if(IncInfo) cin>>G.arcs[i][j].info;
        G.arcs[j][i]=G.arcs[i][j];
    }
    return true;
}

bool CreateUDN(MGraph &G){
    int IncInfo;//是否包含信息
    scanf("%d%d%d",&G.vexnum,&G.arcnum,&IncInfo);
    for(int i=0;i<G.vexnum;i++)
        scanf("%d",G.vexs[i]);//构建顶点向量
    for(int i=0;i<G.vexnum;i++)
        for(int j=0;j<G.vexnum;j++)
        {
            G.arcs[i][j]={0,NULL};
        }//初始化无向网弧矩阵
    int v1,v2,weight;
    for(int k=0;k<G.arcnum;i++)
    {
        scanf("%d%d%d",&v1,&v2,&weight);
        int i,j;
        i=LocateVex(G,v1),j=LocateVex(G,v2);
        G.arcs[i][j].adj=weight;
        if(IncInfo) cin>>G.arcs[i][j].info;
        G.arcs[j][i]=G.arcs[i][j];
    }
    return true;
}

int main()
{
    return 0;
}
