#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

struct IntNode {
	int data;
	IntNode *next;
	IntNode(int data) : data(data), next(nullptr) { }
};

class IntList {
 private:
	IntNode *head;
	IntNode *tail;
 public:
	IntList();
	IntList(const IntList& cpy);
	~IntList();
	void push_front(int);
	void push_back(int);
	void pop_front();
	void clear();
	bool empty() const;
	const int & front() const;
	const int & back() const;

	void selection_sort();
	void insert_ordered(int value);
	void remove_duplicates();

	friend ostream& operator<<(ostream&, const IntList&);	
	IntList& operator=(const IntList&);
};

#endif

