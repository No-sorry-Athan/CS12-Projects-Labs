#include "IntVector.h"

IntVector::IntVector() {
	sz = 0;
	cap = 0;
	data = nullptr;
}

IntVector::IntVector(unsigned size, int value) {
	sz = size;
	cap = size;
	data = new int[cap];
	for (unsigned i = 0; i < sz; i++) {
		data[i] = value;
	}
}

void IntVector::expand() {
	auto oldCap = cap;
	cap *= 2;
	if (cap == 0) {
		cap = 1;
	}
	int* temp = new int[cap];
	for (unsigned i = 0; i < oldCap; i++) {
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
	
}

void IntVector::expand(unsigned amount) {
	auto oldCap = cap;
	cap += amount;
	int* temp = new int[cap];
	for (unsigned i = 0; i < oldCap; i++) {
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
}

IntVector::~IntVector() {
	delete[] data;
	sz = 0;
	cap = 0;
	cout << "Deconstructed" << endl;
}

const unsigned IntVector::size() const {
	return sz;
}

const unsigned IntVector::capacity() const {
	return cap;
}

const bool IntVector::empty() const {
	return sz == 0;
}

const int& IntVector::at(unsigned index) const {
	if (index >= sz) 
		throw out_of_range("IntVector::at_range_check"); 
	else
		return data[index];
}

const int& IntVector::front() const {
	return data[0];
}

int& IntVector::front() {
	return data[0];
}

const int& IntVector::back() const {
	return data[sz-1];
}

int& IntVector::back() {
	return data[sz - 1];
}

int& IntVector::at(unsigned index) {
	if (index >= sz)
		throw out_of_range("IntVector::at_range_check");
	else
		return data[index];
}

void IntVector::insert(unsigned index, int value) {
	if (++sz > cap)
		expand();
	if (index >= sz)
		throw out_of_range("IntVector::insert_range_check");
	else {
		for (unsigned i = sz; i > index; i--) {
			data[i] = data[i - 1];
		}
		data[index] = value;
	}
}

void IntVector::erase(unsigned index) {
	if (index >= sz)
		throw out_of_range("IntVector::erase_range_check");
	else {
		for (unsigned i = index; i < sz - 1; i++) {
			data[i] = data[i + 1];
		}
		sz--;
	}
}

void IntVector::push_back(int value) {
	if (++sz > cap)
		expand();
	data[sz-1] = value;

	/*if (sz == cap)
		expand();
	
	
	data[sz] = value;
	sz++;*/
}

void IntVector::pop_back() {
	sz--;
}

void IntVector::clear() {
	sz = 0;
}

void IntVector::resize(unsigned size, int value) {
	if (size < sz)
		sz = size;
	else if (size > sz) {
		auto oldSz = sz;
		if (size > cap) {
			if (cap * 2 > cap + (size - cap))
				expand();
			else
				expand(size - cap);
		}
		sz = size;
		for (unsigned i = oldSz; i < size; i++) {
			data[i] = value;
		}
		
	}
}

void IntVector::reserve(unsigned n) {
	if (cap < n)
		expand(n - cap);
}

void IntVector::assign(unsigned n, int value) {
	if ((sz = n) > cap) {
		if (cap * 2 > cap + (n - cap))
			expand();
		else
			expand(n - cap);

	}
	for (unsigned i = 0; i < sz;  i++) {
		data[i] = value;
	}
}