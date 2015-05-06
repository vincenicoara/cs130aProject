#include <iostream>
#include "ULL.h"

using namespace std;

ULL::ULL(){
	this->first = NULL;
	this->setNumber(0);
}

ULL::~ULL(){
	this->deleteAll();
}


ULLNode* ULL::getFirst(){
	return this->first;
}

void ULL::setFirst(ULLNode *a){
	this->first = a;
}

void ULL::insert(int a){
	this->numberPlus();
	ULLNode* p = new ULLNode(a);
	if (this->first == NULL){
		this->first = p;
		return;
	}
	p->setNext(this->first);
	this->first = p;
}


void ULL::deleteMin(){
	ULLNode *p = this->first;
	ULLNode *temp;
	if (p == NULL) return;
	int min = p->getData();
	while (p != NULL){
		if (p->getData() < min)
			min = p->getData();
		p = p->getNext();
	}
	p = first;
	if (p->getData() == min){
		temp = p;
		first = p->getNext();
		delete temp;
		this->numberMinus();
		return;
	}
	while (p->getNext()->getData() != min){
		p = p->getNext();
	}
	temp = p->getNext();
	p->setNext(temp->getNext());
	delete temp;
	this->numberMinus();
}

int ULL::minElem(){
	ULLNode *p = this->first;
	if (p == NULL) return -999;

	int min = p->getData();
	while (p != NULL){
		if (p->getData() < min)
			min = p->getData();
		p = p->getNext();
	}
	return min;
}

void ULL::deleteMax(){
	ULLNode *p = this->first;
	ULLNode *temp;
	if (p == NULL) return;
	int max = p->getData();
	while (p != NULL){
		if (p->getData() > max)
			max = p->getData();
		p = p->getNext();
	}
	p = first;
	if (p->getData() == max){
		temp = p;
		first = p->getNext();
		delete temp;
		this->numberMinus();
		return;
	}
	while (p->getNext()->getData() != max){
		p = p->getNext();
	}
	temp = p->getNext();
	p->setNext(temp->getNext());
	delete temp;
	this->numberMinus();
}

int ULL::maxElem(){
	ULLNode *p = this->first;
	if (p == NULL) return -999;

	int max = p->getData();
	while (p != NULL){
		if (p->getData() > max)
			max = p->getData();
		p = p->getNext();
	}
	return max;
}

void ULL::deleteValue(int i){
	if (this->first == NULL) return;

	ULLNode *p = this->first;
	ULLNode *temp;
	if (p->getData() == i){
		temp = p;
		this->setFirst(p->getNext());
		this->numberMinus();
		delete temp;
		return;
	}

	while (p->getNext() != NULL){
		if (p->getNext()->getData() == i){
			temp = p->getNext();
			if (temp->getNext() == NULL){
				p->setNext(NULL);
				continue;	
			}
			else{
				p->setNext(temp->getNext());
				this->numberMinus();
				delete temp;
			}
		}
		p = p->getNext();
	}

}

void ULL::deleteAllValues(int i){
	ULLNode *p = this->first;
	ULLNode *toDelete;
	while (p != NULL){
		if (p->getData() == i){
			this->setFirst(p->getNext());
			delete p;
			p = this->first;
			continue;
		}
		if (p->getNext() == NULL) break;
		if (p->getNext()->getData() == i){
			toDelete = p->getNext();
			p->setNext(toDelete->getNext());
			delete toDelete;
			continue;
		}
		p = p->getNext();
	}
}

void ULL::deleteAll(){

	ULLNode *p = first;

	while (p != NULL){
		p = first;
		this->setFirst(p->getNext());
		delete p;
		p = first;
	}
	first = NULL;
}

void ULL::printAll(){
	ULLNode *p = this->first;
	while (p != NULL){
		cout << p->getData() << endl;
		p = p->getNext();
	}
}

void ULL::printNumberElements(){
	ULLNode *p = this->first;
	int i = 0;
	while (p != NULL){
		i++;
		p = p->getNext();
	}
	cout << i << endl;
}

void ULL::printMin(){
	ULLNode *p = this->first;
	if (p == NULL) return;
	int min = p->getData();
	while (p != NULL){
		if (p->getData() < min)
			min = p->getData();
		p = p->getNext();
	}
	cout << min << endl;
}

void ULL::printMax(){
	ULLNode *p = this->first;
	if (p == NULL) return;
	int max = p->getData();
	while (p != NULL){
		if (p->getData() > max)
			max = p->getData();
		p = p->getNext();
	}
	cout << max << endl;
}

int ULL::distance(int k){
	int upperBound = this->maxElem();
	int lowerBound = upperBound - k;

	ULLNode *p = this->first;
	int i = 0;
	while (p != NULL){
		if (p->getData() >= lowerBound && p->getData() <= upperBound )
			i++;
		p = p->getNext();
	}
	return i;
}

void ULL::append(ULLNode *node){
	ULLNode *p = this->first;
	if (p == NULL) return;
	while (p->getNext() != NULL){
		p = p->getNext();
	}
	p->setNext(node);
}

bool ULL::Check(int* pcount)                                      //*****
      {int countl;                                                //*****
       *pcount=getNumber();                                       //*****
       if(*pcount == 0 && getFirst()== 0) return true;            //*****
       if(!getFirst()->Check(&countl)) return false;              //*****
       if(getNumber() != countl) return false;                    //*****
       return true;                                               //*****
      } 