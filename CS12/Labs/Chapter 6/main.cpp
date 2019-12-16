#include "IntVector.h"
using namespace std;
int main() {
	/*auto vec = new IntVector();
	cout << "Vector 1" << endl;
	cout << "Capacity: " << vec->capacity() << endl;
	cout << "Size: " << vec->size() << endl;
	cout << "Empty: " << boolalpha << vec->empty() << endl;
	cout << "Resize" << endl;
	vec->resize(10, 5);
	cout << "Capacity: " << vec->capacity() << endl;
	cout << "Size: " << vec->size() << endl;
	cout << "Empty: " << boolalpha << vec->empty() << endl;
	for (unsigned i = 0; i < vec->size(); i++) {
		cout << "index: " << i << "\t" << "value: " << vec->at(i) << endl;
	}

	cout << "assigned" << endl;
	vec->assign(3, 9);
	for (unsigned i = 0; i < vec->size(); i++) {
		cout << "index: " << i << "\t" << "value: " << vec->at(i) << endl;
	}

	cout << "Capacity: " << vec->capacity() << endl;
	vec->reserve(25);
	cout << "Capacity: " << vec->capacity() << endl;
	int i = 0;
	delete vec;
	vec = nullptr;*/
	/*while (i < 100) {
		auto vec = new IntVector(i, i);
		cout << "Vector " << i << endl;
		for (unsigned i = 0; i < vec->size(); i++) {
			cout << "index: " << i << "\t" << "value: " << vec->at(i) << endl;
		}
		delete vec;
		i++;
	}*/
	//cout << "Front: " << vec->front() << endl;
	//cout << "Back: " << vec->back() << endl;
	//cout << "At Ind 0: " << vec->at(0) << endl;
	//cout << "At Ind 1: " << vec->at(1) << endl;
	//delete vec;
	//cout << endl;

	cout << "Vector 2" << endl;
	auto vec2 = new IntVector(5, 10);
	cout << "Capacity: " << vec2->capacity() << endl;
	cout << "Size: " << vec2->size() << endl;
	cout << "Empty: " << boolalpha << vec2->empty() << endl;
	cout << "Front: " << vec2->front() << endl;
	cout << "Back: " << vec2->back() << endl;
	cout << "At Ind 0: " << vec2->at(0) << endl;
	cout << "At Ind 1: " << vec2->at(1) << endl;
	cout << endl;

	//cout << "Vector 2 = Vector 1" << endl;
	//vec2 = vec;
	//cout << "Capacity: " << vec->capacity() << endl;
	//cout << "Size: " << vec->size() << endl;
	//cout << "Empty: " << boolalpha << vec->empty() << endl;
	//delete vec2;

	//cout << endl;
	/*cout << "Vector 3" << endl;
	auto vec3 = new IntVector(10, 3);
	vec3->insert(3, 5);
	for (unsigned i = 0; i < vec3->size(); i++) {
		cout << "index: " << i << "\t" << "value: " << vec3->at(i) << endl;
	}
	cout << "Size: " << vec3->size() << endl;
	cout << endl;
	vec3->erase(3);
	for (unsigned i = 0; i < vec3->size(); i++) {
		cout << "index: " << i << "\t" << "value: " << vec3->at(i) << endl;
	}
	cout << "Size: " << vec3->size() << endl;

	cout << "Push_back" << endl;
	vec3->push_back(20);
	cout << "Size: " << vec3->size() << endl;
	cout << endl;
	for (unsigned i = 0; i < vec3->size(); i++) {
		cout << "index: " << i << "\t" << "value: " << vec3->at(i) << endl;
	}

	cout << "Pop_back" << endl;
	vec3->pop_back();
	cout << "Size: " << vec3->size() << endl;
	cout << endl;
	for (unsigned i = 0; i < vec3->size(); i++) {
		cout << "index: " << i << "\t" << "value: " << vec3->at(i) << endl;
	}

	cout << "Capacity: " << vec3->capacity() << endl;
	cout << "Size: " << vec3->size() << endl;*/
	return 0;
}