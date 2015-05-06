#ifndef TRIENODE_H
#define TRIENODE_H
#include "BasicTrieNode.h"

using namespace std;

const int StrMaxElem = 81;
const int TrieMaxElem = 26;

class TrieNode:  public BasicTrieNode{
private:
  	BasicTrieNode* ptr[TrieMaxElem];
public:
  	TrieNode()
  		{BasicTrieNode();
    	int i;
    	for (i=0; i < TrieMaxElem; i++)
      		SetPtr(i,0);
  		}
  	int WhoAmI() {return(1);}
  	bool CheckTrie(int*);   
  	 

  	void SetPtr(int i, BasicTrieNode* j) {ptr[i]=j;}
  	BasicTrieNode* GetPtr(int i) {return ptr[i];}
  	bool isOnlyMS(){
  		int j = 0;
			for (int i = 0; i < TrieMaxElem; i++){
				if (ptr[i] != NULL){
					if (ptr[i]->GetPtr2MS() != NULL)
					j++;
				}
			}
			if (j > 1) return false;
			else return true;
		}
};

#endif