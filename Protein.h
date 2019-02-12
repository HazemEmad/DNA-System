#ifndef PROTEIN_H
#define PROTEIN_H

#include "Sequence.h"
class DNA;

enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};

class Protein : public Sequence
{
  	private:
        Protein_Type type=Cellular_Function;
      public:
 	 	// constructors and destructor
 	 	Protein();
 	 	Protein(char * p);
 	 	~Protein();
 	 	void setProtein_Type(Protein_Type atype);
 	 	Protein_Type getProtein_Type();
 	 	string getTypeString();
 	 	void Print();
 	 	// return an array of DNA sequences that can possibly
        // generate that protein sequence
        //DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA);
        virtual Protein& operator +(Protein &obj);
        virtual bool operator ==(  Protein &obj);
        virtual bool operator !=(  Protein &obj);
        friend std::ostream& operator<< (std::ostream& out, Protein& obj);
        friend std::istream& operator>> (std::istream& in, Protein& obj);
};

#endif // PROTEIN_H
