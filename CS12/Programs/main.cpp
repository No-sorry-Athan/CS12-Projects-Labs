#include "SortedSet.h"
#include <iostream>
int main() {

	IntList list1;
	cout << "pushfront 10" << endl;
	list1.push_front(10);
	cout << "pushfront 20" << endl;
	list1.push_front(20);
	cout << "pushfront 30" << endl;
	list1.push_front(30);
	cout << "list1: " << list1 << endl;
	cout << "pop" << endl;
	//list1.pop_front();
	cout << "list1: " << list1 << endl;
	cout << "pop" << endl;
	//list1.pop_front();
	cout << "list1: " << list1 << endl;
	cout << "pop" << endl;
	//list1.pop_front();

	SortedSet* ss = new SortedSet();
	ss->add(1);
	ss->add(3);
	ss->add(6);
	ss->add(7);
	cout << ss->in(3) << endl;

	cout << *ss << endl;
	
	SortedSet ss2 = list1;

	cout << *ss << endl;

	*ss |= ss2;

	cout << ss2 << endl;

	SortedSet ss3 = SortedSet();
	ss3.push_front(10);

	ss3.push_back(30);

	ss3.pop_front();

	cout << ss3 << endl;

	ss3 &= ss2;

	IntList list4;
	cout << "insert 20" << endl;
	list4.insert_ordered(20);
	cout << "insert 10" << endl;
	list4.insert_ordered(10);
	cout << "insert 30" << endl;
	list4.insert_ordered(30);
	cout << "list4: " << list4 << endl;
	cout << "insert 50" << endl;
	list4.insert_ordered(50);
	cout << "list4: " << list4 << endl;
	cout << "insert 40" << endl;
	list4.insert_ordered(40);
	cout << "list4: " << list4 << endl;
	cout << "insert 11" << endl;
	list4.insert_ordered(11);
	cout << "list4: " << list4 << endl;
	cout << "insert 10" << endl;
	list4.insert_ordered(10);
	cout << "list4: " << list4 << endl;
	cout << "insert 11" << endl;
	list4.insert_ordered(11);
	cout << "list4: " << list4 << endl;
	cout << "insert 9" << endl;
	list4.insert_ordered(9);
	cout << "list4: " << list4 << endl;
	cout << "insert 50" << endl;
	list4.insert_ordered(50);
	cout << "list4: " << list4 << endl;
	cout << "insert 51" << endl;
	list4.insert_ordered(51);

	SortedSet s4 = list4;
	cout << s4;

	cout << endl;
	cout << "New Test" << endl;
	cout << endl;

	IntList list5;
	list5.push_front(10);
	list5.push_front(20);
	list5.push_front(30);
	cout << list5 << endl;
	cout << list1 << endl;
	list5.concat(list1);
	cout << list5;
	return 0;
}