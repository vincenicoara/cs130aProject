#ifndef BASICTRIENODE_H
#define BASICTRIENODE_H
#include <string>
#include "MultiSet.h"
#include "BasicTrieNode.h"

using namespace std;

class BasicTrieNode {
private:
    MultiSet   *ptr2ms;
    int        number;
public:
	BasicTrieNode() {ptr2ms = 0; number=0;}
 	virtual int WhoAmI() {return(0);}
 	virtual bool CheckTrie(int*);    
 	bool checkTN();                             
 	virtual void SetPtr(int i, BasicTrieNode* j){}
 	virtual BasicTrieNode* GetPtr(int i) {}
 	void SetPtr2MS(MultiSet* ptr) {ptr2ms = ptr;}
 	MultiSet* GetPtr2MS() {return ptr2ms;}
 	void numberPlus() {number++;}
 	void numberMinus() {number--;}
 	void deleteRec(string x);  
 	
 	void addNumberMultiSets(int i) {number += + i;}
 	int getNumberMultiSets(){return number;}
 	bool containsMultiSet(){
  		if (ptr2ms == NULL) return false;
  		else return true;
	}
};

#endif