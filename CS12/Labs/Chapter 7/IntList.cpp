#include "IntList.h"

IntList::IntList() {
	head = nullptr;
	tail = nullptr;
}

IntList::IntList(const IntList& cpy) {
	head = nullptr;
	tail = nullptr;
	IntNode* bread = cpy.head;
	while (bread) {
		push_back(bread->data);
		bread = bread->next;
	}
}

IntList::~IntList() {
	IntNode* bread = head;
	while (bread) {
		IntNode* alright = bread->next;
		delete bread;
		bread = alright;
	}
}

void IntList::push_front(int val) {
	IntNode* newVal = new IntNode(val);
	if (head == nullptr) {
		head = newVal;
		tail = newVal;
	}
	else {
		newVal->next = head;
		head = newVal;
	}
}

void IntList::push_back(int val) {
	IntNode* newVal = new IntNode(val);
	if (head == nullptr) {
		head = newVal;
		tail = newVal;
	}
	else if (!empty()) {
		tail->next = newVal;
		tail = newVal;
	}
}

void IntList::pop_front() {
	if (head != nullptr) {
		IntNode* bread = head;
		head = head->next;	
		delete bread;
	}
	if (head == nullptr) {
		tail = nullptr;
	}
}

void IntList::clear() {
	IntNode* bread = head;
	while (bread) {
		IntNode* alright = bread->next;
		delete bread;
		bread = alright;
	}
	head = nullptr;
	tail = nullptr;
}

bool IntList::empty() const {
	return (head == nullptr);
}

const int& IntList::front() const {
	return head->data;
}

const int& IntList::back() const {
	return tail->data;
}

void IntList::selection_sort() {
	IntNode* bread = head;
	while (bread) {
		IntNode* min = bread;
		IntNode* next = bread->next;

		while (next) {
			if (next->data < min->data) {
				min = next;
			}
			next = next->next;
		}
		int toastValue = min->data;
		min->data = bread->data;
		bread->data = toastValue;

		bread = bread->next;
	}
}

void IntList::insert_ordered(int value) {
	IntNode* bread = new IntNode(value);
	
	IntNode* toast = head;
	if (head == nullptr) {
		push_front(value);
	}
	else {
		while (toast) {
			IntNode* burger = toast->next;
			if (toast == head && bread->data < toast->data) {
				push_front(value);
				break;
			}
			else if (value >= toast->data && toast == tail) {
				push_back(value);
				break;
			}
			else if (value >= toast->data && value <= burger->data) {
				bread->next = toast->next;
				toast->next = bread;
				break;
			}

			toast = toast->next;
		}
	}
}

void IntList::remove_duplicates() {
	IntNode* bread = head;
	while (bread) {
		IntNode* next = bread->next;
		IntNode* prev = bread;
		int sled = bread->data;
		while (next) {
			IntNode* bagel = next->next;
			bool inc = false;
			if (next->data == sled) {
				prev->next = bagel;
				delete next;	
				if (prev->next == nullptr)
					tail = prev;
				inc = true;
			}
			if (!inc)
				prev = prev->next;
			next = bagel;
		}

		bread = bread->next;
	}
}

ostream& operator<<(ostream& o, const IntList& list) {
	IntNode* bread = list.head;
	while (bread) {
		if (bread->next == nullptr)
			o << bread->data;
		else
			o << bread->data << " ";

		bread = bread->next;
	}
	return o;
}

IntList& IntList::operator=(const IntList& rhs) {
	if (this != &rhs) {
		IntNode* bread = head;
		while (bread) {
			IntNode* alright = bread->next;
			delete bread;
			bread = alright;
		}

		head = nullptr;
		tail = nullptr;
		IntNode* donut = rhs.head;
		while (donut) {
			push_back(donut->data);
			donut = donut->next;
		}
	}

	return *this;
}
