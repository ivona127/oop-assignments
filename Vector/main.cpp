#include<iostream>
#include "Vector.h"

int main () {
	bool check = false;
	Vector vc;
	
	vc.push_back(1);
	vc.push_back(2);
	vc.push_back(3);
	vc.push_back(4);
	vc.push_back(5);
	vc.pop_back();
	vc.push_back(7);
	
	Vector vc1(vc);
	
	check = vc1.is_empty();
	cout << "Is empty? - " << check << endl;
	cout << "Size - " << vc1.get_size() << endl;
	cout << "Capacity - " << vc1.get_capacity() << endl;
	cout << "Front - " << vc1.front() << endl;
	cout << "Back - " << vc1.back() << endl;
	cout << "At - " << vc1.at(2) << endl;
	
	vc1.shrink_to_fit();
	cout << "\n"<< endl;
	cout << "Shrink to fit"<< endl;
	cout << "Capacity - " << vc1.get_capacity() << endl;
	
	vc1.reserve(10);
	cout << "\n"<< endl;
	cout << "Reserve capacity - " << vc1.get_capacity() << endl;	
	
	return 0;
}
