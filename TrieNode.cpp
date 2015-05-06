#include "TrieNode.h"

bool TrieNode::CheckTrie(int* pcount)                              //*****
      { // USE THIS PROCEDURE DIRECTLY IN YOUR CODE                //*****
        // IF YOU HAVE DIFFERENT CLASS NAMES, FUNCTIONS OR VALUES  //*****
        // YOU NEED TO CHANGE THEM HERE TOO.                       //*****
        bool           result;                                     //*****
        int            i,countl,countll;                           //*****
        countl= *pcount;                                           //*****
        result=true;                                               //*****
        if (GetPtr2MS() != 0) (*pcount)++;            // Changed               //*****
        for(i=0; i<TrieMaxElem; i++)                               //*****
           {if(GetPtr(i)!=0)                                       //*****
             if(!GetPtr(i)->CheckTrie(pcount)) {return false;}     //*****
           }                                                       //*****
        if(countl == *pcount) return false;                        //*****
        return true;                                               //*****
      }  