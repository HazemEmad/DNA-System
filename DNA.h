#ifndef DNA_H
#define DNA_H
#include "Sequence.h"
#include"RNA.h"
class RNA;
enum DNA_Type{promoter, motif, tail, noncoding};

class DNA : public Sequence
{
   	private:
        DNA_Type type;
        DNA * complementary_strand;
        int startIndex;
        int endIndex;
    public:
 	 	// constructors and destructor
        DNA();
        DNA(char * seq, DNA_Type atype);
        DNA(DNA& rhs);
        ~DNA();
        void setDNA_Type(DNA_Type atype);
        void setComplementary_strand(DNA* complementary);
        void setStartIndex(int startInd);
        void setEndIndex(int EndInd);
        DNA_Type getType();
        string getTypeString();
        DNA * getComplementary_strand();
        int getStartIndex ();
        int getEndIndex();
 	 	// function printing DNA sequence information to user
        void Print();
        // function to convert the DNA sequence to RNA sequence
        // It starts by building the complementary_strand of the current
        // DNA sequence (starting from the startIndex to the endIndex), then,
        // it builds the RNA corresponding to that complementary_strand.
        RNA ConvertToRNA();
 	 	// function to build the second strand/pair of DNA sequence
	    // To build a complementary_strand (starting from the startIndex to
        // the endIndex), convert each A to T, each T to A, each C to G, and
        // each G to C. Then reverse the resulting sequence.
        void BuildComplementaryStrand();
        virtual DNA &operator +( DNA &obj);
        virtual bool operator ==(  DNA &obj);
        virtual bool operator !=(  DNA &obj);
        friend std::ostream& operator<< (std::ostream& out, DNA& obj);
        friend std::istream& operator>> (std::istream& in, DNA& obj);

};

#endif // DNA_H
