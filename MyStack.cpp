#include "MyStack.h"
#include<iostream>
using namespace std;

template <class T>
void MyStack<T>::resize(int s)
{
	/*
	function increase stack size by *2 / decrease size by 1/2 upon specific conditions
	arguments: newsize of stack
	return: nothing
	*/
	//cout << "resize func\n";
	size = s;							//argument receiving half OR double size
	T* temp = stack;				//storing previous stack elements
	stack = new T[size];			//updated size of stack
	for (int i = 0; i <= top; i++)
	{
		stack[i] = temp[i];
	}
	delete[]temp;
}

template <class T>
MyStack<T>::MyStack()
{
	/*
	Default Constructor automatically calls when stack object is created without mentioning size of stack
	arguments: no
	return: nothing
	*/
	//cout << "default constructor\n";

	size = 10;						//by default stack of size 10 is making
	top = -1;						//by default top of stack 
	stack = new T[size];			//creating stack of mentioned size
}

template <class T>
MyStack<T>::MyStack(int s)
{
	/*
	Parametized Constructor automatically calls when stack object is created by mentioning size of stack
	arguments: no
	return: nothing
	*/
	//cout << "parametized constructor\n";

	size = s;
	top = -1;
	stack = new T[size];
}

template <class T>
MyStack<T>::MyStack(const MyStack& obj)
{
	cout << "copy constructor\n";

	size = obj.size;
	top = obj.top;
	stack = new T[size];
	for (int i = 0; i <= top; i++)
	{
		stack[i] = obj.stack[i];
	}
}

template <class T>
void MyStack<T>::operator=(MyStack& obj)
{
	cout << "assignemnt opeartor\n";

	delete[] stack;     //previous array made

	size = obj.size;
	top = obj.top;
	stack = new T[size];
	for (int i = 0; i <= top; i++)
	{
		stack[i] = obj.stack[i];
	}
}

template <class T>
void MyStack<T>::push(T value)
{
	/*
	function updates stack pointer and pushes passes "value" on top of stack, it also increases size of stack when
	stack is full.
	arguments: value to be placed/pushed
	return: nothing
	*/
	//cout << "push func\n";
	if (!isFull())						//if stack not full, simply push value
		stack[++top] = value;
	else
	{
		resize(size * 2);				//assigning new stack size by *2
		stack[++top] = value;			//inserting value after increasing capacity
	}
}

template <class T>
T MyStack<T>::pop()
{
	/*
	function returns top most element and removrs it from stack, it also decreases size of stack if no. of
	elemets in stack are less than 1/4 of size.
	arguments: no
	return: value on top of stack
	*/
	//cout << "pop func\n";

	if (!isEmpty())
	{
		if (top < (size / 4) - 1)			//if curent stack is <1/4 of size, then reduce the size by half
			resize(size / 2);
		return stack[top--];
	}
	else
	{
		T var;
		//cout << "Error! stack is empty\n";
		return var;
	}
}

template <class T>
T MyStack<T>::Top()
{
	/*
	function returns top element of stack without removing it from stack
	arguments: no
	return: top most element
	*/
	//cout << "peak func\n";

	if (!isEmpty())
		return stack[top];
	else
		cout << "Stack is empty\n";
}

template <class T>
bool MyStack<T>::isFull()
{
	/*
	function returns true(1) if stack is full and false(0) otherwise
	arguments: no
	return: 1 OR 0
	*/
	//cout << "isFull func\n";

	return top == size - 1;
}

template <class T>
bool MyStack<T>::isEmpty()
{
	/*
	function returns true(1) if stack is empty and false(0) otherwise
	arguments: no
	return: 1 OR 0
	*/
	//cout << "isEmpty func\n";

	return top == -1;
}

template <class T>
void MyStack<T>::print()
{
	/*
	function prints the whole stack from top to bottom
	arguments: no
	return: nothing
	*/
	//cout << "print func\n";

	for (int i = top; i >= 0; i--)
		cout << stack[i] << endl;
}

template <class T>
int MyStack<T>::getSize()
{
	//cout << "getSize func\n";

	return top + 1;
}

template <class T>
MyStack<T>::~MyStack()
{
	/*
	Destructor function deletes dynamic memory allocated to make stack
	arguments: no
	return: nothing
	*/
	//cout << "destructor\n";

	delete[]stack;
}