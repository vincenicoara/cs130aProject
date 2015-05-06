#include "BasicTrieNode.h"

const int StrMaxElem = 81;
const int TrieMaxElem = 26;


bool BasicTrieNode::CheckTrie(int* pcount)                         //*****
      {if(ptr2ms == 0) {return false;}                             //*****
       *pcount++;                                                  //*****
       return true;                                                //*****
      } 

bool BasicTrieNode::checkTN(){
  BasicTrieNode *p = this;
  if (p == NULL) return false;
  for (int i = 0; i < TrieMaxElem; i++){
    if (p->GetPtr(i) != NULL) return true;
  }
  return false;
}


void BasicTrieNode::deleteRec(string x){
  /*
  BasicTrieNode *p = this;
  int length = x.size();
  int j = x[0] - 'a';
  if (p == NULL) return;
  if (p->GetPtr(j)== NULL) return;

  // If we are on the last word and it is a BTN, we are going to:
  // -delete the lastest version of its MS
  // -if it has multiple MS, we return after deleteing that ONE.
  // -if it has multiple, we delete the latest version and point to the prev

  if (length == 1 & p->GetPtr(j)->WhoAmI() == 0){
    MultiSet *toDelete = p->GetPtr2MS();
    MultiSet *temp = toDelete->getptr2prev();

    if (temp != NULL){
      p->SetPtr2MS(temp);
      delete toDelete;
      return;                     //return here
    }
    else {
      delete toDelete;   
      p->SetPtr(j, NULL);
      delete p->GetPtr(j); // don't forget to delete last node, you may have to add this to other parts as well!!
    
    }
  return;
  }

  if (p->GetPtr(j) == NULL) return;
  if (p->GetPtr(j) != NULL) {
    // other important conditions
    // to keep looking, p->GetPtr(j) must be a TN.
    

    // next node was TN, and its getPtr of the next letter got deleted.
    // if that next node has NO OTHER valid getPtr entries (it's not the middle of any name of a set) AND it has a valid MS data object, then it needs to become a BTN.
    // if this next node further has no continuations, AND NO MS data object associated with, delete it!
      // if you delete, make the TN parent that called it NULL.
      // p->setPtr(j, NULL);


    if (!p->GetPtr(j)->checkTN()){
      delete p->GetPtr(j);
      p->SetPtr(j, NULL);
    }
    else if (!p->GetPtr(j)->checkTN()){
      MultiSet *msP = p->GetPtr(j)->GetPtr2MS();
      delete p->GetPtr(j);
      BasicTrieNode * newBTN = new BasicTrieNode();
      newBTN->SetPtr2MS(msP);
      p->SetPtr(j, newBTN);
      return;
    }

    if (p->GetPtr(j)->WhoAmI() == 1){
      p->GetPtr(j)->deleteRec(x.erase(0,1));
    }

  } 
  */
}