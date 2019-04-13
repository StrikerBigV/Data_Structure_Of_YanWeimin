#include <iostream>
#include <cstdio>
using namespace std;

//整数幂型函数结构体定义
struct term
{
    float coef;//系数
    int expn;//指数
    term* next;//指针域

    term(){};
    term(int theExpn) {term->expn=theExpn;}
    term(float theCoef) {term->coef=theCoef;}
    term(float theCoef,int theExpn){term->expn=theExpn;term->coef=theCoef;}
};

//多项式定义
class polynomial{
public:
    void createPolyn(term* &P,int m);
    void AddPolyn(term* &a,term* &b);
    int cmp(term &a,term &b);

};
int main()
{
    return 0;
}
