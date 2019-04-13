#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int INFINITY=INT_MAX;
const MAX_VERTEX_NUM=20;
typedef enum{DG,DN,UDG,UDN} GraphKind;
typedef struct ArcCell{
    int adj;//������Ȩͼ��0Ϊ���ڽӣ�1Ϊ�ڽӣ�������Ȩͼ��Ϊ��Ȩֵ
    InfoType* info;//���������Ϣָ��
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct{
    int vexs[MAX_VERTEX_NUM];//��������
    AdjMatrix arcs;//���ڽӾ���
    int vexnum,arcnum;//�������ͻ���
    GraphKind kind;//ͼ�����࣬0~3�ֱ��������ͼ��������������ͼ��������
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
        if(MGraph.arcs[i][j]==1)//������Ȩͼ��ˣ���Ȩͼ���Ϊ!=INFINITY
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
    int IncInfo;//�Ƿ������Ϣ
    scanf("%d%d%d",&G.vexnum,&G.arcnum,&IncInfo);
    for(int i=0;i<G.vexnum;i++)
        scanf("%d",G.vexs[i]);//������������
    for(int i=0;i<G.vexnum;i++)
        for(int j=0;j<G.vexnum;j++)
        {
            G.arcs[i][j]={0,NULL};
        }//��ʼ������ͼ������
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
    int IncInfo;//�Ƿ������Ϣ
    scanf("%d%d%d",&G.vexnum,&G.arcnum,&IncInfo);
    for(int i=0;i<G.vexnum;i++)
        scanf("%d",G.vexs[i]);//������������
    for(int i=0;i<G.vexnum;i++)
        for(int j=0;j<G.vexnum;j++)
        {
            G.arcs[i][j]={0,NULL};
        }//��ʼ��������������
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
    int IncInfo;//�Ƿ������Ϣ
    scanf("%d%d%d",&G.vexnum,&G.arcnum,&IncInfo);
    for(int i=0;i<G.vexnum;i++)
        scanf("%d",G.vexs[i]);//������������
    for(int i=0;i<G.vexnum;i++)
        for(int j=0;j<G.vexnum;j++)
        {
            G.arcs[i][j]={0,NULL};
        }//��ʼ������ͼ������
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
    int IncInfo;//�Ƿ������Ϣ
    scanf("%d%d%d",&G.vexnum,&G.arcnum,&IncInfo);
    for(int i=0;i<G.vexnum;i++)
        scanf("%d",G.vexs[i]);//������������
    for(int i=0;i<G.vexnum;i++)
        for(int j=0;j<G.vexnum;j++)
        {
            G.arcs[i][j]={0,NULL};
        }//��ʼ��������������
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
