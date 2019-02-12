#include"Sequence.h"
#include"DNA.h"
#include "RNA.h"
#include "Protein.h"
#include "CodonsTable.h"
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std;

int main()
{
    string fileName="RNA_codon_table.txt";
    cout<<"Choose sequence do u want to enter: "<<endl;
    cout<<"1- DNA"<<endl;
    cout<<"2- RNA"<<endl;
    cout<<"3- Protein"<<endl;
    int ch;
    cin>>ch;
    if(ch==1){
        DNA dna;
        cin>>dna;
        cout<<"What type want to convert : "<<endl;
        cout<<"1- RNA"<<endl;
        cout<<"2- Protein"<<endl;
        cin>>ch;
        if(ch==1){
            RNA rna;
            rna=dna.ConvertToRNA();
            cout<<rna;
        }else if(ch==2){
            Protein protein;
            RNA rna;
            rna=dna.ConvertToRNA();
            CodonsTable table;
            table.LoadCodonsFromFile(fileName.c_str());
            protein=rna.ConvertToProtein(table);
            cout<<protein;
        }
    }else if(ch==2){
        RNA rna;
        cin>>rna;
        cout<<"What type want to convert : "<<endl;
        cout<<"1- DNA"<<endl;
        cout<<"2- Protein"<<endl;
        cin>>ch;
        if(ch==1){
            DNA dna;
            dna=rna.ConvertToDNA();
            cout<<dna;
        }else if(ch==2){
            Protein protein;
            CodonsTable table;
            table.LoadCodonsFromFile(fileName.c_str());
            protein=rna.ConvertToProtein(table);
            cout<<protein;
        }
    }else if(ch==3){
        Protein protein;
        cin>>protein;
    }
}
