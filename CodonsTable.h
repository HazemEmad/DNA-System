#ifndef CODONSTABLE_H
#define CODONSTABLE_H
#include<iomanip>
using namespace std;
struct Codon
{
  	char value[4];    	    // 4th location for null character
    char AminoAcid;  	    // corresponding AminoAcid according to Table
};

class CodonsTable
{
   private:
        Codon codons[64];
   	public:
 	 	// constructors and destructor
        void LoadCodonsFromFile(string codonsFileName);
        CodonsTable();
        ~CodonsTable();
 	 	// function to load all codons from the given text file
 	 	Codon* getCodons();
        Codon getAminoAcid(char * value);
        void setCodon(char * value, char AminoAcid, int index);

};

#endif // CODONSTABLE_H
