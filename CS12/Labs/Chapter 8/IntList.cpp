#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(0) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

bool IntList::exists(int val) const {
	return exists(head, val);
}


bool IntList::exists(IntNode* node, int val) const {
	bool thing = false;
	if (node) {
		thing = exists(node->next, val);
		if (node->data == val)
			return true;
	}
	return thing;
}

ostream& operator<<(ostream& os, const IntList& list) {
	if (list.head == nullptr)
		return os;
	else {
		os << list.head;
		return os;
	}
}

ostream& operator<<(ostream& os, IntNode* n) {
	if (n == nullptr)
		return os;
	else if (n->next == nullptr) {
		os << n->data;
		return os;
	}
	else {
		os << n->data << " ";
		os << n->next;
	}
	return os;
}
