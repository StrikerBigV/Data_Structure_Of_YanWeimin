#include <iostream>
#include <cstdio>
using namespace std;

//�������ͺ����ṹ�嶨��
struct term
{
    float coef;//ϵ��
    int expn;//ָ��
    term* next;//ָ����

    term(){};
    term(int theExpn) {term->expn=theExpn;}
    term(float theCoef) {term->coef=theCoef;}
    term(float theCoef,int theExpn){term->expn=theExpn;term->coef=theCoef;}
};

//����ʽ����
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
