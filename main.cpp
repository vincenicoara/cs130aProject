#include <iostream>
#include <string>
#include "BasicTrieNode.h"
#include "MultiSet.h"
#include "Trie.h"
#include "TrieNode.h"
#include "ULL.h"
#include "ULLNode.h"

using namespace std;

int main(void)
{
  Trie * trie = new Trie();

  trie->Create("abc");
  trie->Create("a");
  trie->Create("dda");


  trie->Insert("abc",2);
  trie->Insert("a",3);


  trie->Insert("dda",87);


  trie->PrintNumGT("a");
  //trie->Merge("cat","catnip");
  cout << endl;

  return 0;
}
/*
// Test for BasicTrieNodes and  TrieNodes
  BasicTrieNode  *bpointer,*pointer,*ptr;
  ptr = new TrieNode();
  bpointer = new BasicTrieNode();
  cout << bpointer->WhoAmI()<< endl;
  pointer = new TrieNode();
  cout << pointer->WhoAmI()<< endl;
  ptr->SetPtr(1,bpointer);
  ptr->SetPtr(2,pointer);
  cout << ptr->GetPtr(1)->WhoAmI() << endl;
  cout << ptr->GetPtr(2)->WhoAmI() << endl;

  // Test for ULL
  MultiSet *ms1;
  ms1=new ULL();

  cout << ms1->WhoAmI() << endl;

  ULLNode *pt1;

  pt1= new ULLNode();

  ms1->setFirst(pt1);

  ms1->setNumber(5);
  
  cout <<  ms1->getNumber() << endl;


  // Using CheckTrie                                                   //*****
  // int temp;                                                         //*****
  // Trie t;                                                           //*****
  // Assume that t has been initialized correctly                      //*****
  // temp=0;     // ADDED
  // if(t.GetRoot()->CheckTrie(&temp)) cout << "True " << temp << endl;//*****
  //           else cout << "False 0" << endl;                         //*****
  // MultiSet  *q;                                                     //*****
  // temp=0;     // ADDED
  // Assume that q points to a MultiSet (ULL or HBLT)                  //*****
  //  if (q->Check(&temp)) cout << "True " << temp << " ";             //*****
  //        else cout << "False 0 ";                                   //*****
  //  cout << q->WhoAmI()-1 << endl;                                   //*****
  //
  */