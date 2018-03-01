#pragma once
#include "IStack.h"

template<typename T>
class ArrayStack : public IStack<T>
{
public:
	ArrayStack(size_t capacity = 10);
	virtual ~ArrayStack();

	void push(const T& element) override;
	T pop() override;
	T peek() const override;
	bool isEmpty() const override;

private:
	T * elements;
	size_t count;
	size_t capacity;

	void expand();
};

template<typename T>
ArrayStack<T>::ArrayStack(size_t capacity)
{
	this->count = 0;
	this->capacity = capacity;
	this->elements = new T[capacity];
}

template<typename T>
ArrayStack<T>::~ArrayStack()
{
	delete[] elements;
}

template<typename T>
void ArrayStack<T>::push(const T & element)
{
	if (count == capacity) expand();
	elements[count++] = element;
}

template<typename T>
T ArrayStack<T>::pop()
{
	if (count == 0) throw "Stack is empty.";
	return elements[--count];
}

template<typename T>
T ArrayStack<T>::peek() const
{
	if (count == 0) throw "Stack is empty.";
	return elements[count - 1];
}

template<typename T>
bool ArrayStack<T>::isEmpty() const
{
	return count == 0;
}

template<typename T>
void ArrayStack<T>::expand()
{
	throw "TODO: Expand";
}
