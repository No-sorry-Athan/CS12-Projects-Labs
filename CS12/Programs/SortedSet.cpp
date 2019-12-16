#include "SortedSet.h"

// Con & Decon

SortedSet::SortedSet() : IntList() {}

SortedSet::SortedSet(const SortedSet& set) : IntList(set) {
	/*IntNode* temp = set.head;
	while (temp) {
		add(temp->data);
		temp = temp->next;
	}*/
}

SortedSet::SortedSet(const IntList& list) : IntList(list){
	selection_sort();
	remove_duplicates();
}

SortedSet::~SortedSet() {
	while (head) {
		IntNode* temp = head->next;
		delete head;
		head = temp;
	}
	tail = nullptr;
}

// Accessors

bool SortedSet::in(IntNode* n, int val) const {
	if (n) {
		if (n->data == val)
			return true;
		else
			return in(n->next, val);
	}
	return false;
}

bool SortedSet::in(int val) const {
	return in(head, val);
}

bool SortedSet::in(IntNode* n, int val) {
	if (n) {
		if (n->data == val)
			return true;
		else
			return in(n->next, val);
	}
	return false;
}

bool SortedSet::in(int val) {
	return in(head, val);
}

const SortedSet& SortedSet::operator|(const SortedSet& set) const {
	SortedSet* placeAndSet = new SortedSet();
	IntNode* temp = head;
	while (temp) {
		placeAndSet->add(temp->data);
		temp = temp->next;
	}

	temp = set.head;
	while (temp) {
		placeAndSet->add(temp->data);
		temp = temp->next;
	}
	return *placeAndSet;
}

const SortedSet& SortedSet::operator&(const SortedSet& set) const {
	SortedSet* placeAndSet = new SortedSet();
	IntNode* temp = head;
	while (temp) {
		if (in(temp->data) && set.in(temp->data)) {
			placeAndSet->add(temp->data);
		}
		temp = temp->next;
	}

	return *placeAndSet;
}

// Mutators

void SortedSet::add(int val) {
	if (!in(val)) {
		/*IntNode* node = new IntNode(val);
		if (head == nullptr) {
			head = node;
			tail = node;
		}
		else if (val < head->data) {
			node->next = head;
			head = node;
		}
		else if (val > tail->data) {
			tail->next = node;
			tail = node;
		}
		else {
			IntNode* temp = head;
			while (temp) {
				if (val > temp->data && val < temp->next->data) {
					node->next = temp->next;
					temp->next = node;
					break;
				}
				temp = temp->next;
			}
		}*/
		IntList::insert_ordered(val);
	}
}

void SortedSet::push_front(int val) {
	if (!in(val)) 
		add(val);
}

void SortedSet::push_back(int val) {
	if (!in(val)) 
		add(val);
}

void SortedSet::insert_ordered(int val) {
	if (!in(val)) 
		add(val);
}

SortedSet& SortedSet::operator|=(const SortedSet& set) {
	if (this != &set) {
		SortedSet* placeAndSet = new SortedSet();
		IntNode* temp = head;

		while (temp) {
			placeAndSet->add(temp->data);
			temp = temp->next;
		}

		while (head) {
			IntNode* temp = head->next;
			delete head;
			head = temp;
		}
		tail = nullptr;

		temp = set.head;
		while (temp) {
			placeAndSet->add(temp->data);
			temp = temp->next;
		}

		temp = placeAndSet->head;
		while (temp) {
			add(temp->data);
			temp = temp->next;
		}

		while (placeAndSet->head) {
			IntNode* next = placeAndSet->head->next;
			delete placeAndSet->head;
			placeAndSet->head = next;
		}
	}
	return *this;
}

SortedSet& SortedSet::operator&=(const SortedSet& set) {
	if (this != &set) {
		SortedSet* placeAndSet = new SortedSet();
		IntNode* temp = head;
		while (temp) {
			if (in(temp->data) && set.in(temp->data)) {
				placeAndSet->add(temp->data);
			}
			temp = temp->next;
		}

		while (head) {
			IntNode* next = head->next;
			delete head;
			head = next;
		}
		tail = nullptr;
	
		temp = placeAndSet->head;
		while (temp) {
			add(temp->data);
			temp = temp->next;
		}

		while (placeAndSet->head) {
			IntNode* next = placeAndSet->head->next;
			delete placeAndSet->head;
			placeAndSet->head = next;
		}
	}

	return *this;
}