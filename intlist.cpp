// intlist.cpp
// Implements class IntList
//Albert Yu (6603104) - 1/30/2022
#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
	
	if(source.first == NULL) {
		return;
	}
	Node *itr = source.first;
	Node *cCpy = new Node;
	this->first = cCpy;
	cCpy->info = itr->info;
	while(itr->next != NULL) {
		itr = itr->next;
		cCpy->next = new Node;
		cCpy = cCpy->next;
		cCpy->info = itr->info;
	}
	cCpy->next = NULL;
}

// destructor deletes all nodes
IntList::~IntList() {
	if(this->first == NULL) {
		return;
	}
	Node *delP = this->first;
        if(delP->next != NULL) {
                Node *nextP = this->first->next;
                while(nextP->next != NULL) {
                        delete delP;
                        delP = nextP;
                        nextP = nextP->next;
                }
		delete delP;
                delete nextP;
        } else {
                delete delP;
        }	
    //IMPLEMENT THIS
}


// return sum of values in list
int IntList::sum() const {
	if(this->first == NULL) {
		return 0;
	}
	Node *itr = this->first;
	int cSum = itr->info;
	while(itr->next != NULL) {
		itr = itr->next;
		cSum += itr->info;
	}
	return cSum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
	if(this->first == NULL) {
		return false;
	}
	Node *itr = this->first;
	while(itr != NULL) {
		if(itr->info == value) {
			return true;
		}
		if(itr->next == NULL) {
			break;
		}
		itr = itr->next;
	}
	return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
	if(this->first == NULL) {
		return 0;
	}
	Node *itr = this->first;
	int maxValue = itr->info;
	while(itr != NULL) {
		if(itr->info > maxValue) {
			maxValue = itr->info;
		}
		if(itr->next == NULL) {
			break;
		} 
		itr = itr->next;
	}
	return maxValue;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
	int cSum = this->sum();
	Node *itr = this->first;
	double nodeC = 1;
	while(itr->next != NULL) {
		nodeC++;
		itr = itr->next;
	}
	return cSum / nodeC;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
	Node *newNode = new Node;
	newNode->info = value;
	if(this->first == NULL) {
		this->first = newNode;
	} else {
		newNode->next = this->first;
		this->first = newNode;
	}
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
       	if(this->first != NULL) {
        	Node *delP = this->first;
        	if(delP->next != NULL) {
        	        Node *nextP = this->first->next;
        	        while(nextP->next != NULL) {
        	                delete delP;
        	                delP = nextP;
        	                nextP = nextP->next;
        	        }
        	        delete delP;
        	        delete nextP;
        	} else {
        	        delete delP;
	        }
	}
	Node *itr = source.first;
	while(itr != NULL) {
		this->append(itr->info);
		if(itr->next == NULL) {
			break;
		}
		itr = itr->next;
	}	
	return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
