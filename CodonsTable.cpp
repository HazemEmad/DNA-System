#include "CodonsTable.h"
#include "fstream"
#include <cstring>
using namespace std;

CodonsTable::CodonsTable()
{

}
CodonsTable::~CodonsTable()
{
    //dtor
}
Codon* CodonsTable::getCodons()
{
    return codons;
}
void CodonsTable::LoadCodonsFromFile(string codonsFileName)
{
    ifstream infile;
    char ch;
    int counter=0;
    int index=0;
    char * val;
    infile.open(codonsFileName.c_str());
    if(!infile.fail()){
        while(infile>>ch){
            val[counter]=ch;
            counter++;
            if(counter==4){
                counter=0;
                if(val=="UAA" || val=="UAG" || val=="UGA"){
                    this->setCodon(val,' ',index);
                    index++;
                }else{
                    infile>>ch;
                    this->setCodon(val,ch,index);
                    index++;
                }
            }
        }
    }
    infile.close();
}

Codon CodonsTable::getAminoAcid(char * value)
{
    Codon codon;
    for(int i=0;i<64;i++){

        if(this->getCodons()[i].value==value){
            codon=this->codons[i];
        }
    }
    return codon;
}
void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{
    codons[index].AminoAcid=AminoAcid;
    strcpy(codons[index].value,value);

}
