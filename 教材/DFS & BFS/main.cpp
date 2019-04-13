#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef int QElemType;
//队列定义
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;
//链队列定义
typedef struct
{
    QueuePtr Front;
    QueuePtr rear;
}LinkQueue;
bool QueueEmpty(LinkQueue Q){
    if(Q.Front==Q.rear) return true;;
    else return false;
}
void InitQueue(LinkQueue &Q)
{
    Q.Front=(QueuePtr)malloc(sizeof(QNode));
    Q.Front->next=NULL;
    Q.rear=Q.Front;
}
void EnQueue(LinkQueue &Q,QElemType e)
{
    QNode *p=(QueuePtr )malloc(sizeof(QNode));
    p->data=e;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
}

QElemType DeQueue(LinkQueue &Q)
{
    QNode *p=Q.Front->next;
    QElemType e=p->data;
    Q.Front->next=p->next;
    if(p==Q.rear) Q.rear=Q.Front;
    free(p);
    return e;
}

//邻接表图定义
const int MAX_VERTEX_NUM=20;
typedef struct ArcNode{//表结点，代表一条弧
    int adj;//该弧指向的顶点在邻接表中的位置
    struct ArcNode *nextarc;//指向由对应头结点指向的下一条弧
    InfoType* info;
}ArcNode;
typedef struct VNode{//头结点，代表一个顶点
    int data;
    ArcNode *firstarc;//邻接数组的第一个结点，代表第一条指向的弧
}VNode,AdjLIst[MAX_VERTEX_NUM];
typedef struct{
    AdjLIst vertices;
    int vexnum,arcnum;
    int kind;
}ALGraph;
//寻找第一个邻接点
int FirstAdjVex(ALGraph G,int v){
    if(G.vertices[v].firstarc!=NULL)
        return G.vertices[v].firstarc->adj;
    else return -1;
}
//寻找v相对于w的下一个邻接点
int NextAdjVex(ALGraph G,int v,int w){
    ArcNode *p=G.vertices[v].firstarc;
    if(v==w) return 0;//输入错误，v与w不能相等
    else{
        while(p->nextarc){
            if(p->adj==w) break;
            else p=p->nextarc;
        }
        if(p->nextarc!=NULL) return p->nextarc->adj;//该点存在
        else return -1;//该点不存在
    }
}
//得到顶点v的数据
int GetVex(ALGraph G,int v){
    return G.vertices[v].data;
}
//访问顶点v的数据
void Visit(ALGraph G,int v){
    if(v<MAX_VERTEX_NUM){
        printf("%d",G.vertices[v].data);
    }
}

//***************************DFS************************//
bool visited[MAX_VERTEX_NUM+10];//标记数组
void DFSTraverse(ALGraph G){
    for(int v=0;v<G.vexnum;v++)
        visited[v]=false;//初始化标记数组
    for(int v=0;v<G.vexnum;v++){
        if(!visited[v]) DFS(G,v);//对未访问过的顶点进行深度优先搜索
    }
}
//对一个点进行深度优先搜索
void DFS(AlGraph G,int v){
    Visit(G,v);
    visited[v]=true;//已访问
    for(int w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w)){//对于与v邻接的所有点
        if(!visited[w]) DFS(G,w);//如果未访问，进行一次深度优先搜索
    }
}

//***********************BFS*************************//
void BFSTraverse(ALGraph G){
    for(int v=0;v<G.vexnum;v++)
        visited[v]=false;//初始化标记数组
    LinkQueue Q;
    InitQueue(Q);//建立队列，装顶点
    for(int v=0;v<G.vexnum;v++){
        Visit(G,v);
        visited[v]=true;//已访问
        EnQueue(Q,v);//将刚访问的顶点插入队列
        while(!QueueEmpty(Q)){//队列不空
            int top=DeQueue(Q);//取队首元素
            for(int w=FirstAdjVex(G,top);w>=0;w=NextAdjVex(G,top,w)){//对队首元素的所有邻接点
                if(!visited[w]){//若未访问
                    Visit(G,w);
                    visited[w]=true;
                    EnQueue(Q,w);//访问并插入队列
                }
            }
        }
    }
}

//**********************建立无向图深度优先生成森林***********************//
//树的孩子兄弟表示法
typedef struct CSNode{
    int data;
    struct CSNode *firstchild,*nextsibling;
}CSNode,*CSTree;
//建立深度优先生成森林
void DFSForest(ALGraph G,CSTree &T){
    CSNode *q;
    T=NULL;
    for(int v=0;v<G.vexnum;v++)
        visited[v]=false;
    for(int v=0;v<G.vexnum;v++){
        if(!visited[v]){
            CSNode *p=(CSNode*)malloc(sizeof(CSNode));
            *p={GetVex(G,v),NULL,NULL};//初始化根结点
            if(!T) T=p;//是第一棵生成树的根
            else q->nextsibling=p;//是前一棵生成树的兄弟
            q=p;//q指向当前生成树的根
            DFSTree(G,v,p);//建立以p为根结点的生成树
        }
    }
}
//由图G，从点v开始深度优先搜索，建立以T为根结点的生成树
void DFSTree(ALGraph G,int v,CSNode* &T){
    CSNode *q;
    bool first=true;//是第一个未访问的邻接点
    visited[v]=true;
    for(int w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w)){
        if(!visited[w]){
            CSNode *p=(CSNode *)malloc(sizeof(CSNode));
            *p={GetVex(G,w);NULL,NULL};//分配并初始化孩子结点
            if(first){//如果是第一个未访问的邻接点
                T->firstchild=p;//将其置于第一孩子域
                first=false;
            }
            else{
                q->nextsibling=p;//将其置于上一邻接点
            }
            q=p;
            DFSTree(G,w,q);// 递归建立子生成树
        }
    }
}

int main()
{
    return 0;
}
