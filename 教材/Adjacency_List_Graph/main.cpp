#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAX_VERTEX_NUM=20;
typedef struct ArcNode{//���㣬����һ����
    int adj;//�û�ָ��Ķ������ڽӱ��е�λ��
    struct ArcNode *nextarc;//ָ���ɶ�Ӧͷ���ָ�����һ����
    InfoType* info;
}ArcNode;
typedef struct VNode{//ͷ��㣬����һ������
    VertexType data;
    ArcNode *firstarc;//�ڽ�����ĵ�һ����㣬�����һ��ָ��Ļ�
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
