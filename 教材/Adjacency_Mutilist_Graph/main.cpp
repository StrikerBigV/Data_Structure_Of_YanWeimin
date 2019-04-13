#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_VERTEX_NUM=20;
typedef enum{unvisited,visited} VisitIf;
typedef struct EBox{//弧结点
    VisitIf mark;//是否访问
    int ivex;//弧的一个顶点位置
    struct *ilink;//依附于i顶点的下一条弧
    int jvex;//弧的另一个顶点位置
    struct *jlink;//依附于j顶点的下一条弧
    InfoType *info;
}EBox;
typedef struct VexBox{
    int data;
    EBox *firstedge;//依附于该顶点的第一条弧
}VexBox;
typedef struct{
    VexBox adjmulist[MAX_VERTEX_NUM];
    int vexnum,edgenum;
}AMLGraph;

int main()
{
    return 0;
}
