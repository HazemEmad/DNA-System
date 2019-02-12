#ifndef RNA_H
#define RNA_H

#include "Sequence.h"
#include "DNA.h"
#include "Protein.h"
#include "CodonsTable.h"
class DNA;
class Protein;
class CodonsTable;
enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class RNA : public Sequence
{
   private:
        RNA_Type type=mRNA;
  	public:
 	 	// constructors and destructor
        RNA();
        RNA(char * seq, RNA_Type atype);
        RNA(RNA& rhs);
        ~RNA();
        void setRNA_Type(RNA_Type atype);
        RNA_Type getRNA_Type();
         string getTypeString();
 	 	// function to be overridden to print all the RNA information
        void Print();
 	 	// function to convert the RNA sequence into protein sequence
        // using the codonsTable object
        Protein ConvertToProtein(CodonsTable & table);
 	 	// function to convert the RNA sequence back to DNA
        DNA ConvertToDNA();
        virtual RNA& operator +(RNA &obj);
        virtual bool operator ==(  RNA &obj);
        virtual bool operator !=(  RNA &obj);
        friend std::ostream& operator<< (std::ostream& out, RNA& obj);
        friend std::istream& operator>> (std::istream& in, RNA& obj);

};

#endif // RNA_H
