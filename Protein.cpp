#include "Protein.h"
#include<cstring>
using namespace std;

Protein::Protein()
{
    //ctor
}

Protein::~Protein()
{
    //dtor
}

Protein::Protein(char * p)
{
    this->setSeq(p);
}
void Protein::setProtein_Type(Protein_Type atype)
{
    type=atype;
}
Protein_Type Protein::getProtein_Type()
{
    return type;
}

string Protein::getTypeString(){
    string r="";
    switch(this->type){
        case Hormon:
            r = "Hormon";
            break;
         case Enzyme:
            r = "Enzyme";
            break;
         case TF:
            r = "TF";
            break;
         case Cellular_Function:
            r = "Cellular_Function";
            break;
    }
    return r;
}

bool validate_Protein(char* ch)
{
    bool ret=false;
    string str=ch;
    for(int i=0; i<str.length(); i++)
    {
        if(str.at(i)=='B' || str.at(i)=='j' || str.at(i)=='X' || str.at(i)=='U' || str.at(i)=='Z')
        {
            ret=false;
        }
        else
        {
            ret=true;
            break;
        }
    }
    return ret;
}

void Protein::Print()
{
    cout<<"Sequence of Protein: "<<this->getSeq();
    cout<<"Type: "<<this->getTypeString();

}

//DNA* Protein::GetDNAStrandsEncodingMe(const DNA & bigDNA)
//{
//    DNA* Arr_DNA;
//    RNA rna =bigDNA.ConvertToRNA();
//    CodonsTable table;
//    table.LoadCodonsFromFile();
//    Protein protein=rna.ConvertToProtein(table);
//    for(int i=0;i<strlen(protein.getSeq());i++){
//        for()
//    }
//}

Protein&Protein::operator +( Protein &obj)
{
    string aSeq1=this->getSeq();
    string aSeq2=obj.getSeq();
    string res=aSeq1+aSeq2;
    char* ch;
    strcpy(ch, res.c_str());
    Protein result;
    result.setSeq(ch);
    return result;
}
bool Protein::operator ==(  Protein &obj)
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
bool Protein::operator !=(  Protein &obj)
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


std::ostream& operator<< (std::ostream& out, Protein& obj)
{
    out<<"Type of Protein: "<<obj.getTypeString()<<endl;
    out<<"Sequence: "<<obj.getSeq()<<endl;
    return out;
}
std::istream& operator>> (std::istream& in, Protein& obj)
{
    string str;
    cout<<"Sequence of Protein: ";
    again:
    in>>str;
    char* ch;
    strcpy(ch,str.c_str());
    if(validate_Protein(ch)==true){
    obj.setSeq(ch);
    int num;
    cout<<"Types( 1- Hormon, 2- Enzyme, 3- TF, 4- Cellular_Function) "<<endl;
    cout<<"Choose number of type: ";
    in>>num;
    Protein_Type type;
    if(num==1){
       type=Hormon;
    }else if(num==2){
        type=Enzyme;
    }else if(num==3){
        type=TF;
    }else if(num==4){
        type=Cellular_Function;
    }
    obj.setProtein_Type(type);
    }else{
        cout<<"The sequence isn't correct !";
        goto again;
    }
    return in;
}
