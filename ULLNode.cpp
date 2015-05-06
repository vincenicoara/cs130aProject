#include <iostream>
#include "ULLNode.h"

ULLNode::ULLNode(){
	this->data = 0;
	this->next = NULL;
}
ULLNode::ULLNode(int i){
	this->data = i;
	this->next = NULL;
}
ULLNode* ULLNode::getNext(){
	return this->next;
}
int ULLNode::getData(){
	return this->data;
}
void ULLNode::setNext(ULLNode* j){
	this->next = j;
}
void ULLNode::setData(int j){
	this->data = j;
}

bool ULLNode::Check(int* pcount)                                  //*****
      { int countl;                                               //*****
        if(getData() < 1) return false;                           //*****
        if(getNext() == 0) {*pcount=1; return true;}              //*****
        if(!getNext()->Check(&countl)) return false;              //*****
        *pcount=countl+1;                                         //*****
        return true;                                              //*****
    } 
