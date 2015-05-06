#ifndef MULTISET_H
#define MULTISET_H
#include "ULLNode.h"

using namespace std;


class MultiSet{
private:
	int number; // # of elements in the multiset
	MultiSet* ptr2previousVersion;
public:
	MultiSet();
	virtual int WhoAmI() {return 1;}
	virtual ULLNode*  getFirst(){ULLNode *p; return p;}
	virtual void setFirst(ULLNode* ptr){}
	MultiSet * getptr2prev();
	void setptr2prev(MultiSet *);
	int getNumber();
	void setNumber(int);
	void numberPlus();
	void numberMinus();
	int addNumberElements(int i){number += i; return number;}
};

#endif