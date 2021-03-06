#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<iostream>

using namespace std;

class Sequence
{
protected:
    char * seq;
public:
    // constructors and destructor
    Sequence();
    Sequence(int length);
    Sequence(Sequence& rhs);
    virtual ~Sequence();
//    // pure virtual function that should be overridden because every
//    // type of sequence has its own details to be printed
    void setSeq(char *sequance);
    char* getSeq();
    virtual void Print()=0;
    virtual Sequence& operator +(const Sequence &obj);
    virtual bool operator ==(  Sequence &obj);
    virtual bool operator !=(  Sequence &obj);
    friend std::ostream& operator<< (std::ostream& out, Sequence& obj);
    friend std::istream& operator>> (std::istream& in, Sequence& obj);
//     friend function that will find the LCS (longest common
//     subsequence) between 2 sequences of any type, according to
//     polymorphism
    friend char* Align(Sequence* s1, Sequence *s2);
};


#endif // SEQUENCE_H
