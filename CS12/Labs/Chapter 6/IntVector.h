#ifndef INT_VECTOR_H
#define INT_VECTOR_H

#include <stdexcept>
#include <iostream>

using namespace std;
class IntVector {
private:
	unsigned sz;
	unsigned cap;
	int* data;
	void expand();
	void expand(unsigned amount);
public:
	IntVector();
	//IntVector(unsigned size);
	IntVector(unsigned size, int value = 0);
	~IntVector();
	const unsigned size() const;
	const unsigned capacity() const;
	const bool empty() const;
	const int& at(unsigned index) const;
	const int& front() const;
	const int& back() const;

	void insert(unsigned index, int value);
	void erase(unsigned index);
	int& front();
	int& back();
	int& at(unsigned index);
	void assign(unsigned n, int value);
	void push_back(int value);
	void pop_back();
	void clear();
	void resize(unsigned size, int value = 0);
	void reserve(unsigned n);

};

#endif 