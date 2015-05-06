#ifndef ULL_H
#define ULL_H
#include "ULLNode.h"
#include "MultiSet.h"

class ULL: public MultiSet{
private:
	ULLNode* first;
public:
	ULL();
	~ULL();
	ULLNode* getFirst();
	void setFirst(ULLNode*);
	void insert(int);
	void deleteValue(int);
	void deleteAllValues(int);
	void deleteMin();
	void deleteMax();
	void deleteAll();
	int minElem();
	int maxElem();
	void printAll();
	void printNumberElements();
	void printMin();
	void printMax();
	int distance(int k);
	void append(ULLNode*);
	int WhoAmI(){return 2;}
	bool Check(int* pcount);
};

#endif