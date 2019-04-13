#include <cstdoi>
#include <string>

typedef string StringType;

void StrAssign(StringType &t,StringType s);
int Strcompare(StringType s,StringType t);
int StrLength(StringType s);
StringType Concat(StringType s,StringType t);
StringType SubString(StringType s,int start,int len);

void Replace(StringType &S,StringType T,StringType V)
{
    int lenS=StrLength(S),lenT=StrLength(T),lenV=StrLength(V);
    for(int i=0;i<lenS-lenT+1;i++)
    {
        if(!Strcompare(SubString(S,i,lenT),T))
        {
            StringType pre,Next;
            StrAssign(pre,SubString(S,0,i-1));
            StrAssign(Next,SubString(S,i+lenT,lenS-i-lenT+1));
            StringType temp;
            StrAssign(temp,Concat(pre,V));
            StrAssign(S,Concat(temp,Next));
            i+=lenV;
        }
    }
}
