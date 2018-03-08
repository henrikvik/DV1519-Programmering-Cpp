#pragma once

template<typename T>
class Vector
{
public:
	Vector(size_t cap = 10);
	virtual ~Vector();

	Vector(Vector const& other);
	Vector& operator=(Vector const& other);

	void add(T const& element);
	void remove(size_t index);
	size_t size() const;

	T& operator[](size_t index);

private:
	T * elements;
	size_t num;
	size_t cap;

	void expand();
	void copy(Vector const& other);
	void free();
};

template<typename T>
Vector<T>::Vector(size_t cap)
{
	this->num = 0;
	this->cap = cap;
	this->elements = new T[cap];
}

template<typename T>
Vector<T>::~Vector()
{
	free();
}

template<typename T>
Vector<T>::Vector(Vector const & other)
{
	copy(other);
}

template<typename T>
Vector<T> & Vector<T>::operator=(Vector const & other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

template<typename T>
void Vector<T>::add(T const & element)
{
	if (cap == num) expand();
	elements[num++] = element;
}

template<typename T>
void Vector<T>::remove(size_t index)
{
	if (index >= num) throw "Out-of-bounds!";
	delete elements[index];
	elements[index] = elements[--num];
}

template<typename T>
size_t Vector<T>::size() const
{
	return num;
}

template<typename T>
T & Vector<T>::operator[](size_t index)
{
	if (index >= num) throw "Out-of-bounds!";
	return elements[index];
}
