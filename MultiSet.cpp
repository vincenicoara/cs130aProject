#include "MultiSet.h"



MultiSet::MultiSet(){
	number = 0; 
	ptr2previousVersion = 0;
}
MultiSet *MultiSet::getptr2prev(){
	return ptr2previousVersion;
}
void MultiSet::setptr2prev(MultiSet *p){
	ptr2previousVersion = p;
}

int MultiSet::getNumber(){
	return number;
}

void MultiSet::setNumber(int i){
	number = i;
}

void MultiSet::numberPlus(){
	number++;
}

void MultiSet::numberMinus(){
	number--;
}