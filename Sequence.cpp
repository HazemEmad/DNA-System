#include "Sequence.h"
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std;

Sequence::Sequence()
{
    //ctor
}

Sequence::~Sequence()
{
    //dtor
}
Sequence::Sequence(int length)
{
    seq=new char[length];
}
Sequence::Sequence(Sequence& rhs)
{
    int len=strlen(rhs.seq);
    this->seq=new char[len];
    this->seq=rhs.seq;
}

void Sequence::setSeq(char *sequance)
{
    seq=sequance;
}

char* Sequence::getSeq()
{
    return seq;
}
void Sequence::Print()
{
}
Sequence&Sequence::operator +(const Sequence& obj)
{

}
bool Sequence::operator ==( Sequence &obj)
{
    string str1=this->getSeq();
    string str2=obj.getSeq();
    if(str1==str2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Sequence::operator !=( Sequence& obj)
{
    string str1=this->getSeq();
    string str2=obj.getSeq();
    if(str1==str2)
    {
        return false;
    }
    else
    {
        return true;
    }
}
ostream& operator<< (ostream& out, Sequence& obj)
{
    out<<obj.getSeq();
    return out;
}
istream& operator>> (istream& in, Sequence& obj)
{
    string str;
    in>>str;
    char ch[str.length()];
    strcpy(ch,str.c_str());
    obj.setSeq(ch);
    return in;
}


char* Align(Sequence *s1, Sequence *s2)
{
    char* X=s1->getSeq();
    char* Y=s2->getSeq();
    int m=strlen(X);
    int n=strlen(Y);
    int L[m+1][n+1];
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    int index = L[m][n];

    char lcs[index+1];
    lcs[index] = ' ';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {        if (X[i-1] == Y[j-1])
        {
            lcs[index-1] = X[i-1];
            i--;
            j--;
            index--;
        }

        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }

    string res=lcs;
    res.erase(res.size()-3);
    strcpy(lcs,res.c_str());
    return lcs;

}

