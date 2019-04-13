#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef int QElemType;
//���ж���
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;
//�����ж���
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

//�ڽӱ�ͼ����
const int MAX_VERTEX_NUM=20;
typedef struct ArcNode{//���㣬����һ����
    int adj;//�û�ָ��Ķ������ڽӱ��е�λ��
    struct ArcNode *nextarc;//ָ���ɶ�Ӧͷ���ָ�����һ����
    InfoType* info;
}ArcNode;
typedef struct VNode{//ͷ��㣬����һ������
    int data;
    ArcNode *firstarc;//�ڽ�����ĵ�һ����㣬�����һ��ָ��Ļ�
}VNode,AdjLIst[MAX_VERTEX_NUM];
typedef struct{
    AdjLIst vertices;
    int vexnum,arcnum;
    int kind;
}ALGraph;
//Ѱ�ҵ�һ���ڽӵ�
int FirstAdjVex(ALGraph G,int v){
    if(G.vertices[v].firstarc!=NULL)
        return G.vertices[v].firstarc->adj;
    else return -1;
}
//Ѱ��v�����w����һ���ڽӵ�
int NextAdjVex(ALGraph G,int v,int w){
    ArcNode *p=G.vertices[v].firstarc;
    if(v==w) return 0;//�������v��w�������
    else{
        while(p->nextarc){
            if(p->adj==w) break;
            else p=p->nextarc;
        }
        if(p->nextarc!=NULL) return p->nextarc->adj;//�õ����
        else return -1;//�õ㲻����
    }
}
//�õ�����v������
int GetVex(ALGraph G,int v){
    return G.vertices[v].data;
}
//���ʶ���v������
void Visit(ALGraph G,int v){
    if(v<MAX_VERTEX_NUM){
        printf("%d",G.vertices[v].data);
    }
}

//***************************DFS************************//
bool visited[MAX_VERTEX_NUM+10];//�������
void DFSTraverse(ALGraph G){
    for(int v=0;v<G.vexnum;v++)
        visited[v]=false;//��ʼ���������
    for(int v=0;v<G.vexnum;v++){
        if(!visited[v]) DFS(G,v);//��δ���ʹ��Ķ�����������������
    }
}
//��һ������������������
void DFS(AlGraph G,int v){
    Visit(G,v);
    visited[v]=true;//�ѷ���
    for(int w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w)){//������v�ڽӵ����е�
        if(!visited[w]) DFS(G,w);//���δ���ʣ�����һ�������������
    }
}

//***********************BFS*************************//
void BFSTraverse(ALGraph G){
    for(int v=0;v<G.vexnum;v++)
        visited[v]=false;//��ʼ���������
    LinkQueue Q;
    InitQueue(Q);//�������У�װ����
    for(int v=0;v<G.vexnum;v++){
        Visit(G,v);
        visited[v]=true;//�ѷ���
        EnQueue(Q,v);//���շ��ʵĶ���������
        while(!QueueEmpty(Q)){//���в���
            int top=DeQueue(Q);//ȡ����Ԫ��
            for(int w=FirstAdjVex(G,top);w>=0;w=NextAdjVex(G,top,w)){//�Զ���Ԫ�ص������ڽӵ�
                if(!visited[w]){//��δ����
                    Visit(G,w);
                    visited[w]=true;
                    EnQueue(Q,w);//���ʲ��������
                }
            }
        }
    }
}

//**********************��������ͼ�����������ɭ��***********************//
//���ĺ����ֵܱ�ʾ��
typedef struct CSNode{
    int data;
    struct CSNode *firstchild,*nextsibling;
}CSNode,*CSTree;
//���������������ɭ��
void DFSForest(ALGraph G,CSTree &T){
    CSNode *q;
    T=NULL;
    for(int v=0;v<G.vexnum;v++)
        visited[v]=false;
    for(int v=0;v<G.vexnum;v++){
        if(!visited[v]){
            CSNode *p=(CSNode*)malloc(sizeof(CSNode));
            *p={GetVex(G,v),NULL,NULL};//��ʼ�������
            if(!T) T=p;//�ǵ�һ���������ĸ�
            else q->nextsibling=p;//��ǰһ�����������ֵ�
            q=p;//qָ��ǰ�������ĸ�
            DFSTree(G,v,p);//������pΪ������������
        }
    }
}
//��ͼG���ӵ�v��ʼ�������������������TΪ������������
void DFSTree(ALGraph G,int v,CSNode* &T){
    CSNode *q;
    bool first=true;//�ǵ�һ��δ���ʵ��ڽӵ�
    visited[v]=true;
    for(int w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w)){
        if(!visited[w]){
            CSNode *p=(CSNode *)malloc(sizeof(CSNode));
            *p={GetVex(G,w);NULL,NULL};//���䲢��ʼ�����ӽ��
            if(first){//����ǵ�һ��δ���ʵ��ڽӵ�
                T->firstchild=p;//�������ڵ�һ������
                first=false;
            }
            else{
                q->nextsibling=p;//����������һ�ڽӵ�
            }
            q=p;
            DFSTree(G,w,q);// �ݹ齨����������
        }
    }
}

int main()
{
    return 0;
}
