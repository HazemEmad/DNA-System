#include "RNA.h"
#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
RNA::RNA()
{
    //ctor
}

RNA::~RNA()
{
    //dtor
}
bool validate_RNA(char* ch)
{
    bool ret=false;
    string str=ch;
    for(int i=0; i<strlen(ch); i++)
    {
        if(str.at(i)=='A' || str.at(i)=='C' || str.at(i)=='G' || str.at(i)=='U')
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

RNA::RNA(char * seq, RNA_Type atype)
{
    if(validate_RNA(seq)){
        this->setSeq(seq);
        this->type=atype;
    }
}
RNA::RNA(RNA& rhs)
{
    this->setSeq(rhs.getSeq());
    this->type=rhs.type;
}

void RNA::setRNA_Type(RNA_Type atype)
{
    type=atype;
}
RNA_Type RNA::getRNA_Type()
{
    return type;
}

void RNA::Print()
{
    cout<<"Sequence of RNA: "<<this->getSeq();
    cout<<"Type: "<<this->getTypeString();
}

Protein RNA::ConvertToProtein(CodonsTable & table)
{
    string RNA_seq=this->getSeq();
    string Protein_seq="";
    char *ch;
    Protein obj;
    for(int i=0;i<RNA_seq.length();i++){
        if(i+3<RNA_seq.length()){
            string subseq=RNA_seq.at(i)+RNA_seq.at(i+1)+RNA_seq.at(i+2)+" ";
            i=i+2;
            ch=new char[subseq.length()];
            strcpy(ch,subseq.c_str());
            Codon codon=table.getAminoAcid(ch);
            if(codon.AminoAcid==' '){
                ch=new char[Protein_seq.length()];
                strcpy(ch,Protein_seq.c_str());
                obj.setSeq(ch);
                return obj;
            }else{
                Protein_seq=Protein_seq+codon.AminoAcid;
            }

        }else{
            ch=new char[Protein_seq.length()];
            strcpy(ch,Protein_seq.c_str());
            obj.setSeq(ch);
            return obj;
        }
    }
     ch=new char[Protein_seq.length()];
     strcpy(ch,Protein_seq.c_str());
     obj.setSeq(ch);
     return obj;
}

DNA RNA::ConvertToDNA()
{
    DNA dna;
    string sequence=this->getSeq();
    for(int i=0;i<sequence.length();i++){
        if(sequence.at(i)=='U'){
            sequence.at(i)='T';
            }
    }
    char ch[sequence.length()];
    strcpy(ch,sequence.c_str());
    dna.setSeq(ch);
    dna.setStartIndex(0);
    dna.setEndIndex(sequence.length());
    dna.BuildComplementaryStrand();
    return dna;
}

RNA&RNA::operator +( RNA &obj)
{
    string aSeq1=this->getSeq();
    string aSeq2=obj.getSeq();
    string res=aSeq1+aSeq2;
    char ch[res.length()];
    strcpy(ch, res.c_str());
    RNA result;
    result.setSeq(ch);
    return result;
}
bool RNA::operator ==(  RNA &obj)
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
bool RNA::operator !=(  RNA &obj)
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

string RNA::getTypeString(){
    string r="";
    switch(this->type){
        case mRNA:
            r = "mRNA";
            break;
         case pre_mRNA:
            r = "pre_mRNA";
            break;
         case mRNA_exon:
            r = "mRNA_exon";
            break;
         case mRNA_intron:
            r = "mRNA_intron";
            break;
    }
    return r;
}

std::ostream& operator<< (std::ostream& out, RNA& obj)
{
    out<<"Type of RNA: "<<obj.getTypeString()<<endl;
    char ch[strlen(obj.getSeq())];
    string str=obj.getSeq();
    for(int i=0;i<strlen(ch);i++){
      str[i]=ch[i];
    }
    out<<"Sequence: "<<str<<endl;
    return out;
}
std::istream& operator>> (std::istream& in, RNA& obj)
{
    string str;
    again:
    cout<<"Sequence of RNA: ";
    in>>str;
    char ch[str.length()];
    strcpy(ch,str.c_str());
    if(validate_RNA(ch)==true){
    obj.setSeq(ch);
    int num;
    cout<<"Types(1- mRNA, 2- pre_mRNA, 3- mRNA_exon, 4- mRNA_intron) "<<endl;
    cout<<"Choose number of type: ";
    in>>num;
    RNA_Type type;
    if(num==1){
       type=mRNA;
    }else if(num==2){
        type=pre_mRNA;
    }else if(num==3){
        type=mRNA_exon;
    }else if(num==4){
        type=mRNA_intron;
    }
    obj.setRNA_Type(type);
    }else{
        cout<<"The sequence isn't correct !";
        goto again;
    }
    return in;
}
