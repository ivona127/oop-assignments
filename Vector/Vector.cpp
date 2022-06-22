#include "Vector.h"
#include <stdexcept>

using namespace std;

// private
void Vector::resize(int new_size){
	this->capacity = capacity*2; 
	int* newVector = new int[capacity];
	memcpy(newVector, data, size * sizeof(int));
	delete[] data;
			
	size = new_size;
	data = newVector;		
}


Vector::iterator::iterator(const Vector *vector){
	this->vector = vector;
	index = 0;
}

Vector::iterator::iterator(const Vector *vector, int index){
	this->vector = vector;
	this->index = index;
}

Vector::iterator &Vector::iterator::operator++(){
	if (index < vector->size){
		++index;
	}
					
	return *this;
}

Vector::iterator &Vector::iterator::operator++(int){
	if (index < vector->size){
		index++;
	}
					
	return *this;
}
Vector::iterator &Vector::iterator::operator--(int){
	if (index > 0){
		index--;
	}
					
	return *this;
}

int Vector::iterator::operator*(){
	return vector->at(index);
}

bool Vector::iterator::operator>=(iterator other){
	if (vector >= other.vector){
		return true;
	}
					
	return false;
}
bool Vector::iterator::operator<=(iterator other){
	if (vector >= other.vector){
		return true;
	}
					
	return false;
}
		
bool Vector::iterator::operator>(iterator other){
	if (vector > other.vector){
		return true;
	}
					
	return false;
}			
bool Vector::iterator::operator<(iterator other){
	if (vector < other.vector){
		return true;
	}
					
	return false;
}

// public	
Vector::Vector(){
	capacity = 4;
	size = 0;
	data = new int[capacity];
}

Vector::Vector(const Vector &other){
	this->capacity = other.capacity;
	this->size = other.size;
	data = new int[capacity];
	memcpy(this->data, other.data, capacity * sizeof(capacity));
}
		
Vector &Vector::operator=(const Vector &other){
	if(this->data){
		delete[] data;
	}
			
	this->size = other.size;
	data = new int[this->size];
			
	for(int idx = 0; idx < this->size; idx++){
		this->data[idx] = other.data[idx];
	}
			
	return *this;
}

Vector::~Vector(){
	delete[] data;
}
int Vector::get_size() const{
	return this->size;	
}

int Vector::get_capacity() const{
	return this->capacity;
}

bool Vector::is_empty() const{
	if (size == 0){
		return true;
	}
			
	return false;
}
	
void Vector::reserve(int reserve_capacity){
	if (reserve_capacity <= capacity){
		throw range_error("Index out of bounds");
	}
	
	capacity = reserve_capacity;
}

void Vector::shrink_to_fit(){
	capacity = size;
}
		
int Vector::at(int index) const{
	if (index < 0 || index >= size){
		throw range_error("Index out of bounds");
	}
			
	return data[index];
}

int Vector::operator[](int index) const{
	return data[index];
}
		
void Vector::push_back(int value){
	if(size == capacity){
		resize(size++);
	}
			
	data[size] = value;
	size++;
}

void Vector::pop_back(){
	if(is_empty()){
		throw range_error("Index out of bounds");
	}
			
	--size;	
}

int Vector::front() const{
	if(is_empty()){
		throw range_error("Index out of bounds");
	}
	return *data;   
}

int Vector::back() const{
	if(is_empty()){
		throw range_error("Index out of bounds");
	}
			
	return data[size-1];
}
	
Vector::iterator Vector::begin() const{
	return iterator(this);
}

Vector::iterator Vector::end() const{
	return iterator(this, size);
}


