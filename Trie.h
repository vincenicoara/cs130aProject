#ifndef TRIE_H
#define TRIE_H
#include <string>
#include "BasicTrieNode.h"
#include "TrieNode.h"
using namespace std;


class Trie {
private:
    BasicTrieNode *root;
    //bool Delete(char x[], int i, TrieNode *current );
  	bool CheckTrieNodeEmpty(TrieNode *current);
  	int CountN(BasicTrieNode*);
    int CountNT(BasicTrieNode *current);
    int PrintNumGT(string x, BasicTrieNode* current);
public:
	Trie() ;
  	void Create(string);
  	void Insert(string x, int);
  	void Merge(string, string);
  	void DeleteElem(string x, int);
  	void DeleteMax(string x);
  	void PrintMax(string x);
  	void PrintMin(string x);
  	void PrintNum(string x);
    void PrintNumGT(string x);
  	void Dist(string x, int k);
  	void CountN();
    void CountNT();
  	bool Member(string x);
  	void Delete(string x);
  	void DeleteAll(string x);
  	void deleteRec(string x);
  	void deleteAllRec(string x, bool, BasicTrieNode*, int);
    bool CheckTrie(int* count);
    BasicTrieNode* pointerToWord(string x); 
    void printAllElements(string x);
    bool containsMultiset(BasicTrieNode *);                               
};

#endif