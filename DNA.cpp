#include "DNA.h"
#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

DNA::DNA()
{

}

DNA::~DNA()
{

}

void DNA::setDNA_Type(DNA_Type atype)
{
    type=atype;
}
void DNA::setComplementary_strand(DNA* complementary)
{
    this->complementary_strand=new DNA;
    this->complementary_strand->setSeq(complementary->getSeq());
}

void DNA::setStartIndex(int startInd)
{
    startIndex=startInd;
}
void DNA::setEndIndex(int EndInd)
{
    endIndex=EndInd;
}
DNA_Type DNA::getType()
{
    return type;
}
string DNA::getTypeString()
{
    string r="";
    switch(this->type)
    {
    case promoter:
        r = "promoter";
        break;
    case motif:
        r = "motif";
        break;
    case tail:
        r = "tail";
        break;
    case noncoding:
        r = "noncoding";
        break;
    }
    return r;
}
DNA * DNA::getComplementary_strand()
{
    return complementary_strand;
}
int DNA::getStartIndex ()
{
    return startIndex;
}
int DNA::getEndIndex()
{
    return endIndex;
}

bool validate_DNA(char* ch)
{
    bool ret=false;
    string str=ch;
    for(unsigned int i=0; i<str.size(); i++)
    {
        if(str.at(i)=='A' || str.at(i)=='C' || str.at(i)=='G' || str.at(i)=='T')
        {
            ret=true;
        }
        else
        {
            ret=false;
            break;
        }
    }
    return ret;
}

DNA::DNA(char * seq, DNA_Type atype)
{
    if(validate_DNA(seq)==true)
    {
        this->setSeq(seq);
        type=atype;
        BuildComplementaryStrand();
    }
}

DNA::DNA(DNA& rhs)
{
    this->setSeq(rhs.getSeq());
    startIndex=rhs.startIndex;
    endIndex=rhs.endIndex;
    type=rhs.type;
    complementary_strand=new DNA;
    complementary_strand=rhs.complementary_strand;
}

void DNA::Print()
{
    cout<<"DNA type: "<<this->getTypeString()<<endl;
    cout<<"First strand: "<<this->getSeq()<<endl;
    cout<<"complemntary strand: "<<complementary_strand->getSeq()<<endl;
}


RNA DNA::ConvertToRNA()
{
    RNA rna;
    string complementary=this->complementary_strand->getSeq();
    cout<<complementary<<endl;
    if(this->getStartIndex()==-1&&this->getEndIndex()==-1)
    {
        this->setStartIndex(0);
        this->setEndIndex(complementary.length());
    }

    for(int i=this->getStartIndex(); i<this->getEndIndex(); i++)
    {
        if(complementary.at(i)=='T')
        {
            complementary[i]='U';
        }
    }
    char ch[complementary.length()];
    strcpy(ch,complementary.c_str());
    rna.setSeq(ch);
    return rna;
}

void DNA::BuildComplementaryStrand()
{
    string aSeq=this->getSeq();
    cout<<aSeq<<endl;
    if(this->getStartIndex()==-1&&this->getEndIndex()==-1)
    {
        this->setStartIndex(0);
        this->setEndIndex(strlen(this->getSeq()));
    }
    for(int i=this->getStartIndex(); i<this->getEndIndex(); i++)
    {

            if(aSeq.at(i)=='A')
        {
            aSeq[i]='T';
        }
        else if(aSeq.at(i)=='C')
        {
            aSeq[i]='G';
        }
        else if(aSeq.at(i)=='G')
        {
            aSeq[i]='C';
        }
        else if(aSeq.at(i)=='T')
        {
            aSeq[i]='A';
        }
    }
    reverse(aSeq.begin(),aSeq.end());
    char ch[aSeq.length()];
    strcpy(ch,aSeq.c_str());
    DNA *dna=new DNA;
    dna->setSeq(ch);
    this->setComplementary_strand(dna);
    string out=this->complementary_strand->getSeq();
}
DNA&DNA::operator +( DNA& obj)
{
    string aSeq1=this->getSeq();
    string aSeq2=obj.getSeq();
    string res=aSeq1+aSeq2;
    char ch[res.length()];
    strcpy(ch,res.c_str());
    DNA result;
    result.setSeq(ch);
    return result;
}
bool DNA::operator ==( DNA &obj)
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
bool DNA::operator !=( DNA& obj)
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

ostream& operator<< (ostream& out, DNA &obj)
{
    out<<"Type of DNA: "<<obj.getTypeString()<<endl;
    out<<"First Strand: "<<obj.getSeq()<<endl;
    obj.setStartIndex(0);
    obj.setEndIndex(strlen(obj.getSeq()));
    out<<"Complementary Strand: "<<obj.getComplementary_strand()->getSeq()<<endl;
    return out;
}
std::istream& operator>> (std::istream& in, DNA &obj)
{
    string str;
again:
    cout<<"First Strand: ";
    in>>str;
    char ch[str.length()];
    strcpy(ch,str.c_str());
    if(validate_DNA(ch)==true)
    {
        obj.setSeq(ch);
        cout<<"Set Start index, End index"<<endl;
        int stInd;
        int EnInd;
        cout<<"Start Index:";
        in>>stInd;
        cout<<"End Index:";
        in>>EnInd;
        obj.setStartIndex(stInd);
        obj.setEndIndex(EnInd);
        obj.BuildComplementaryStrand();
        int num;
        cout<<"Types( 1- promoter, 2- motif, 3- tail, 4- noncoding) "<<endl;
        cout<<"Choose number of type: ";
        in>>num;
        DNA_Type type;
        if(num==1)
        {
            type=promoter;
        }
        else if(num==2)
        {
            type=motif;
        }
        else if(num==3)
        {
            type=tail;
        }
        else if(num==4)
        {
            type=noncoding;
        }
        obj.setDNA_Type(type);
    }
    else
    {
        cout<<"The sequence isn't correct !";
        goto again;
    }
    return in;
}
