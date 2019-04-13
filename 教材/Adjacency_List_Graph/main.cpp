#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAX_VERTEX_NUM=20;
typedef struct ArcNode{//表结点，代表一条弧
    int adj;//该弧指向的顶点在邻接表中的位置
    struct ArcNode *nextarc;//指向由对应头结点指向的下一条弧
    InfoType* info;
}ArcNode;
typedef struct VNode{//头结点，代表一个顶点
    VertexType data;
    ArcNode *firstarc;//邻接数组的第一个结点，代表第一条指向的弧
}VNode,AdjLIst[MAX_VERTEX_NUM];
typedef struct{
    AdjLIst vertices;
    int vexnum,arcnum;
    int kind;
}ALGraph;

int main()
{
    return 0;
}
