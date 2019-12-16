#ifndef SORTEDSET_H
#define SORTEDSET_H
#include "IntList.h"
using namespace std;
class SortedSet : public IntList {
	bool in(IntNode*, int);
	bool in(IntNode*, int) const;
public:

	// Con/Decon
	SortedSet();
	SortedSet(const SortedSet&);
	SortedSet(const IntList&);
	~SortedSet();

	// Accessors
	bool in(int);
	bool in(int) const;
	const SortedSet& operator|(const SortedSet&) const;
	const SortedSet& operator&(const SortedSet&) const;

	// Mutators
	void add(int);
	void push_front(int);
	void push_back(int);
	void insert_ordered(int);
	SortedSet& operator|=(const SortedSet&);
	SortedSet& operator&=(const SortedSet&);

};
#endif
