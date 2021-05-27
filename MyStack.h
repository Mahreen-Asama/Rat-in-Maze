#pragma once
template <class T>
class MyStack
{
	/*
	  size->   no. of memory cells allocated for stack
	 *stack-> pointer to point dynamic memory allocated for stack
	  top->    stack pointer containing index of cell
	*/
	int size;
	T* stack;
	int top;
	void resize(int);	//private function to check limit of stack to increase/decrease
public:
	MyStack();
	MyStack(int);
	MyStack(const MyStack&);
	void operator=(MyStack&);
	void push(T);
	T pop();
	bool isFull();
	bool isEmpty();
	void print();
	int getSize();
	T Top();			//==T peak()
	~MyStack();
};

