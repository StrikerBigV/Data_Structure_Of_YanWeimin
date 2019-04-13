#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef enum PointerTag{Link;Thread;}//Link==0������ָ�룻Thread==1����������
typedef struct BiThrNode{
    TElemType data;
    struct BiThrNode *lchild,*rchild;
    PointerTag LTag,RTag;
}BiThrNode,*BiThrTree;

//���ʺ���
void visit(BiTree &T){
    printf("%c",T->data);
}

//�����������������
void InOrderTraverse_Thr(BiThrTree T){
    BiThrTree p=T->lchild;//pָ������
    while(p!=T){//����������TΪ�ջ��߱�������
        while(p->LTag==Link) p=p->lchild;
        visit(p);//�ҵ�������Ϊ�յĽ�㣬����
        while(p->RTag==Thread && p->rchild!=T){
            p=p->rchild;
            visit(p);//���ʺ�̽��
        }
        p=p->rchild;
    }
}

//����������

int main()
{
    return 0;
}
