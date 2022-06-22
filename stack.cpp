#include <iostream>
#include<cstring>

using std::cout;
using std::endl;

class Stack
{
	private:
		int* arr;
		int top;
		int capacity;
	
	public:
		Stack()
		{
			capacity = 4;
			arr = new int[capacity];
			top = -1;
		}
		
		Stack(int capacity)
		{
			this->capacity = capacity;
			arr = new int[capacity];
			top = -1;
		}
		
		Stack(const Stack& st)
		{
			this->capacity = st.capacity;
			arr = new int[capacity];
			this->top = st.top;
			memcpy(this->arr, st.arr, capacity * sizeof(capacity));
		}

		~Stack()
		{
			delete[] arr;
		}
		
		int* peek()
		{
			if(!isEmpty())
			{
				return &arr[top];
			}
			return nullptr;
		}
		
		int* pop()
		{
			if(!isEmpty())
			{
				return &arr[top--];
			}
			return nullptr;
		}
		
		bool push(int n)
		{
			if(isFull())
			{
				int* newArr = new int[capacity * 2];
				memcpy(newArr, arr, capacity * sizeof(capacity));
				delete[] arr;
				
				capacity = capacity * 2;
				arr = newArr;
			}
			arr[++top] = n;
			return true;
		}
	
		bool isEmpty() { return top == -1; }
		bool isFull()  { return top == capacity - 1; }
		int size()     { return top + 1; }
		
		/*
		friend istream& operator>>(istream& in, Stack& s)
		{
			
		}
		*/
};

int main()
{

	bool check = false;
	
	Stack st;
	Stack st2(st);
	
	check = st2.push(1);
	cout << "result is " << check << endl;
	
	check = st2.push(2);
	cout << "result is " << check << endl;
	
	check = st2.push(3);
	cout << "result is " << check << endl;
	
	check = st2.push(4);
	cout << "result is " << check << endl;
	
	check = st2.push(5);
	cout << "result is " << check << endl;
	
	cout << "just check what last element is " << *(st2.peek()) << endl;
	cout << "size is " << st2.size() << endl;
	
	cout << "Now remove element!" << endl;
	
	cout << "just check what last element is " << *(st2.pop()) << endl;
	cout << "just check what last element is " << *(st2.pop()) << endl;
	cout << "just check what last element is " << *(st2.pop()) << endl;
	cout << "just check what last element is " << *(st2.pop()) << endl;
	cout << "just check what last element is " << *(st2.pop()) << endl;
	
	int* intCheck = st.pop();
	
	if (intCheck == nullptr)
	{
		cout << "No more elements" << endl;
	}
	else
	{
		cout << "just check what last element is " << *intCheck << endl;
	}
	
	return 0;
}
