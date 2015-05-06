#include <iostream>
#include <string>
#include "Trie.h"
#include "TrieNode.h"
#include "ULL.h"

using namespace std;


Trie::Trie(){
  root = new BasicTrieNode();
}

void Trie::Create(string x) {
  
  BasicTrieNode *current = root;
  int i = 0;

  if (current->WhoAmI() == 0){
    TrieNode *newTN = new TrieNode();
    BasicTrieNode *k = current;
    this->root = newTN;
    delete k;
    current = newTN;
  }

  while ( x[i] != '\0' ){
      int j = x[i] - 'a';

      // If no word comes out of index j and we are not on the last
      // letter, make a new TN and set the pointer from the index
      // at j to the new TN


      if (current->GetPtr(j) == NULL && x[i+1] != '\0'){
        TrieNode *newTN = new TrieNode();
        current->SetPtr(j, newTN);
        current = current->GetPtr(j);
      }

      //If the index at j leads to a BTN and we are not on the last
      // letter, create a new TN, set its ptr2ms to what  the BTN had,
      // and delete the BTN

      // If its not a BTN, then simply update your current pointer to 
      // that index.

      else if (current->GetPtr(j) != NULL && x[i+1] != '\0'){
        if (current->GetPtr(j)->WhoAmI() == 0){
            TrieNode *newTN = new TrieNode();
            BasicTrieNode *toDelete = current->GetPtr(j);
            MultiSet *msPtr = current->GetPtr(j)->GetPtr2MS();
            current->SetPtr(j, newTN); 
            current = current->GetPtr(j);
            current->SetPtr2MS(msPtr);
            //newTN->GetPtr(j)->SetPtr2MS(msPtr);
            delete toDelete;
        }
        else {
          current = current->GetPtr(j);
        }
      }

      // If we are on the the last letter and the pointer at index j 
      // is NULL, make a new BTN and set its ptr2Ms to a new Multiset

      else if (current->GetPtr(j) == NULL && x[i+1] == '\0'){
        current->SetPtr(j, new BasicTrieNode());
        current = current->GetPtr(j);
        current->SetPtr2MS(new ULL());
        }

      // If we are on the last letter and the pointer at j points to 
      // a BTN,  then set the pointer's ptr2ms to a new Multiset.

      //If that node already had a ptr2ms, then create a new multiset 
      // and set its ptr2prev to the previous multiset it was pointing
      // to
      
      else if (current->GetPtr(j) != NULL && x[i+1] == '\0'){
        if (current->GetPtr2MS() == 0){
          current = current->GetPtr(j);
          MultiSet *p = current->GetPtr2MS();
          MultiSet *p2 = new ULL();
          p2->setptr2prev(p);
          current->SetPtr2MS(p2);
        }
        else {
          current = current->GetPtr(j);
          MultiSet *p = current->GetPtr2MS();
          MultiSet *p2 = new ULL();
          p2->setptr2prev(p);
          current->SetPtr2MS(p2);
        }
      } 
    i++;
  }
}



void Trie::Merge(string s, string t){
  BasicTrieNode *sBTN = pointerToWord(s);
  BasicTrieNode *tBTN = pointerToWord(t);
  ULL *sULL = (ULL *) sBTN->GetPtr2MS();
  ULL *tULL = (ULL *) tBTN->GetPtr2MS();

  int tNum = tULL->getNumber();
  sULL->addNumberElements(tNum);

  

  MultiSet *tpointertoprev = tBTN->GetPtr2MS()->getptr2prev();

  sULL->append(tULL->getFirst());
  if (tpointertoprev != 0)
    tBTN->SetPtr2MS(tpointertoprev);
  else 
    tBTN->SetPtr2MS(new ULL());
}



void Trie::Insert(string x, int i){
    BasicTrieNode *p = pointerToWord(x);
    if (p == NULL) return;
    BasicTrieNode *current = this->pointerToWord(x);
    ULL *d = (ULL *) current->GetPtr2MS();
    d->insert(i);
}

void Trie::DeleteElem(string x, int i){
  BasicTrieNode *p = pointerToWord(x);
  if (p == NULL) return;
  BasicTrieNode *current = this->pointerToWord(x);
  ULL *d = (ULL *) current->GetPtr2MS();
  d->deleteValue(i);
}

void Trie::DeleteMax(string x){
  BasicTrieNode *p = pointerToWord(x);
  if (p == NULL) return;
  BasicTrieNode *current = this->pointerToWord(x);
  ULL *d = (ULL *) current->GetPtr2MS();
  d->deleteMax();
}

void Trie::PrintMax(string x){
  BasicTrieNode *p = pointerToWord(x);
  if (p == NULL) return;
  BasicTrieNode *current = this->pointerToWord(x);
  ULL *d = (ULL *) current->GetPtr2MS();
  d->printMax();
}

void Trie::PrintMin(string x){
  BasicTrieNode *p = pointerToWord(x);
  if (p == NULL) return;
  BasicTrieNode *current = this->pointerToWord(x);
  ULL *d = (ULL *) current->GetPtr2MS();
  d->printMin();
}

void Trie::PrintNum(string x){
  BasicTrieNode *p = pointerToWord(x);
  if (p == NULL) return;
  BasicTrieNode *current = this->pointerToWord(x);
  ULL *d = (ULL *) current->GetPtr2MS();
  cout << d->getNumber() << endl;
}

void Trie::Dist(string x, int k){
  BasicTrieNode *p = pointerToWord(x);
  if (p == NULL) return;
  BasicTrieNode *current = this->pointerToWord(x);
  ULL *d = (ULL *) current->GetPtr2MS();
  d->distance(k);
}

void Trie::CountN(){
  int counter = 0;
  if (root->WhoAmI() == 0){
    cout << "0" << endl;
    return;
  }
  for (int i = 0; i < TrieMaxElem; i++){
    if (root->GetPtr(i) != 0){
      counter += CountN(root->GetPtr(i));
    }
  }
  cout << counter << endl;
}
int Trie::CountN(BasicTrieNode *current){
  int counter = 0;
  if (current == NULL) return counter;
  if (current->GetPtr2MS() != 0) counter++;
  if (current->WhoAmI() == 0){
    return counter;
  } 
  for (int i = 0; i < TrieMaxElem; i++){
      if (current->GetPtr(i) != 0)
        counter += CountN(current->GetPtr(i));
  }
  return counter;
}

void Trie::CountNT(){
  int counter = 0;
  if (root->WhoAmI() == 0){
    cout << "0" << endl;
    return;
  }
  for (int i = 0; i < TrieMaxElem; i++){
    if (root->GetPtr(i) != 0){
      counter += CountNT(root->GetPtr(i));
    }
  }
  cout << counter << endl;
}

int Trie::CountNT(BasicTrieNode *current){
  int counter = 0;
  if (current == NULL) return counter;
  if (current->GetPtr2MS() != 0){
    MultiSet *p = current->GetPtr2MS();
    counter++;
    while (p->getptr2prev() != NULL){
      p = p->getptr2prev();
      counter++;
    }
  }
  if (current->WhoAmI() == 0){
    return counter;
  }
  for (int i = 0; i < TrieMaxElem; i++){
      if (current->GetPtr(i) != 0)
        counter += CountNT(current->GetPtr(i));
  }
  return counter;
}

void Trie::PrintNumGT(string x){
  int counter = 0;
  BasicTrieNode *current = pointerToWord(x);
  if (current == NULL) return;

  for (int i = 0; i < TrieMaxElem; i++){
    if (current->GetPtr(i) != 0)
      counter += PrintNumGT(x, current->GetPtr(i));
  }  
}

int Trie::PrintNumGT(string x, BasicTrieNode* current){
  int counter = 0;
  if (current == NULL) return counter;
  if (current->GetPtr2MS() != 0) counter ++;
  if (current->WhoAmI() == 0){
    return counter;
  } 
  for (int i = 0; i < TrieMaxElem; i++){
    if (current->GetPtr(i) != 0)
      counter += PrintNumGT(x, current->GetPtr(i));
  }
  return counter;
}

void Trie::Delete(string x){
  
  int length = x.size();
  BasicTrieNode *p = this->root;
  
  if (length == 1){
    MultiSet *pMS = p->GetPtr2MS();
    MultiSet *pMSprev = pMS->getptr2prev();
    ULL *pMS_ULL= (ULL *) pMS;
    ULL *pMSprev_ULL = (ULL *) pMSprev;
    
    // if pMS exists, delete it!.
    // if prevULL exists, p->SetPtr2MS = prevULL
    // if prevULL does not exist, return; you're done.

    if (pMS != NULL) delete pMS_ULL;
    if (pMSprev != NULL) p->SetPtr2MS(pMSprev);
    else {
      root = new BasicTrieNode();
      return;
    }

  }

  root->deleteRec(x.erase(0,1));
  // check whether ROOT has any valid TN* or BTN* after this deletion; you may have deleted the only one.

  if (root == NULL){
    root = new BasicTrieNode();
  }

}



void Trie::DeleteAll(string x){
  if (!Member(x)) return;

  MultiSet *toDelete;
  MultiSet *newMS;
  BasicTrieNode *p = pointerToWord(x);

  if (p->containsMultiSet()){
    while (p->GetPtr2MS() != NULL){
      toDelete = p->GetPtr2MS();
      newMS = toDelete->getptr2prev();
      p->SetPtr2MS(newMS);
      delete toDelete;
      p->numberMinus();
    }
  }
  deleteAllRec(x.substr(0, x.size()-1), false, NULL, 0);
}

void Trie::deleteAllRec(string x, bool isBTN, BasicTrieNode *connectTo, int j){
  /*
  BasicTrieNode *p = pointerToWord(x);
  if (p == NULL) return;

  if (isBTN == true){
    p->SetPtr(j, connectTo);
    p = p->GetPtr(j);
    //cout << "type of node" << p->WhoAmI() << endl;
    return;
  }

  if (p->containsMultiSet()) {
    if (p->WhoAmI() == 1){
      TrieNode *pTN = (TrieNode *) p;
      if (pTN->isOnlyMS()){
        BasicTrieNode *newBTN = new BasicTrieNode();
        MultiSet *msPtr = p->GetPtr2MS();
        newBTN->SetPtr2MS(msPtr);
        delete p;
        int j = x.at(x.size()-1) - 'a';
        deleteAllRec(x.substr(0, x.size()-1), true, newBTN, j);
      }
      else return;
    }
    else return;
  }
  else{
      delete p;
      deleteAllRec(x.substr(0, x.size()-1), false, NULL, 'z');
  }
  */
} 

bool Trie::Member(string x) {
  
  BasicTrieNode *current = root;
  int i = 0;
  while (x[i] != '\0'){
    int j = x[i] - 'a';
    if ( current->GetPtr(j) == 0 )
        return false ;
    else 
        current = current->GetPtr(j);
    i = i+1;
  }
  if (current->GetPtr2MS() != 0)
    return true;
  else return false;
}

void Trie::printAllElements(string x){
  if (!Member(x)) return;
  ULL *p = (ULL *) this->pointerToWord(x)->GetPtr2MS();
  p->printAll();
}

BasicTrieNode* Trie::pointerToWord(string x) {
  
  BasicTrieNode *current = root;
  int i = 0;
  while (x[i] != '\0'){
    int j = x[i] - 'a';
    if ( current->GetPtr(j) == 0 )
        return NULL;
    else 
        current = current->GetPtr(j);
    i = i+1;
  }
  return current;
}


bool Trie::CheckTrie(int* count)                                   //*****
      { // USE THIS PROCEDURE DIRECTLY IN YOUR CODE                //*****
        // IF YOU HAVE DIFFERENT CLASS NAMES, FUNCTIONS OR VALUES  //*****
        // YOU NEED TO CHANGE THEM HERE TOO.                       //*****
        int countl;                                                //*****
        countl=0;                                          // ADDED
        bool result;                                               //*****
        result = root->CheckTrie(&countl);                         //*****
        *count=countl;                                             //*****
        return result;                                             //*****
      } 