#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_VERTEX_NUM=20;
typedef enum{unvisited,visited} VisitIf;
typedef struct EBox{//�����
    VisitIf mark;//�Ƿ����
    int ivex;//����һ������λ��
    struct *ilink;//������i�������һ����
    int jvex;//������һ������λ��
    struct *jlink;//������j�������һ����
    InfoType *info;
}EBox;
typedef struct VexBox{
    int data;
    EBox *firstedge;//�����ڸö���ĵ�һ����
}VexBox;
typedef struct{
    VexBox adjmulist[MAX_VERTEX_NUM];
    int vexnum,edgenum;
}AMLGraph;

int main()
{
    return 0;
}
