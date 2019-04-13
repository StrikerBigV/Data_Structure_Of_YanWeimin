#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef enum PointerTag{Link;Thread;}//Link==0，代表指针；Thread==1，代表线索
typedef struct BiThrNode{
    TElemType data;
    struct BiThrNode *lchild,*rchild;
    PointerTag LTag,RTag;
}BiThrNode,*BiThrTree;

//访问函数
void visit(BiTree &T){
    printf("%c",T->data);
}

//中序遍历二叉线索树
void InOrderTraverse_Thr(BiThrTree T){
    BiThrTree p=T->lchild;//p指向根结点
    while(p!=T){//结束条件，T为空或者遍历结束
        while(p->LTag==Link) p=p->lchild;
        visit(p);//找到左子树为空的结点，访问
        while(p->RTag==Thread && p->rchild!=T){
            p=p->rchild;
            visit(p);//访问后继结点
        }
        p=p->rchild;
    }
}

//中序线索化

int main()
{
    return 0;
}
