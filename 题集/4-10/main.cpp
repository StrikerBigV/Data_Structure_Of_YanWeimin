#include <cstdoi>
#include <string>

typedef string StringType;

void StrAssign(StringType &t,StringType s);
int Strcompare(StringType s,StringType t);
int StrLength(StringType s);
StringType Concat(StringType s,StringType t);
StringType SubString(StringType s,int start,int len);

void Reverse(StringType s,String &t)
{
    StrAssign(t,'');
    int len=StrLength(s);
    for(int i=len-1;i>=0;i--)
    {
        StrAssign(t,Concat(t,SubString(s,i,1)));
    }
}
