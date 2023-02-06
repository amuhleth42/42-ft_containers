#include "Vector.hpp"

// public
typedef VectorIterator<Vector<T> > Iterator;

template <typename T>
Vector<T>::Vector(void) : _data(NULL), _size(0), _capacity(0)
{
	ReAlloc(2);
}

template <typename T>
void	Vector<T>::push_back(T const & value)
{
	if (_size >= _capacity)
		ReAlloc(_capacity * 2);

	_data[_size] = value;
	_size++;
}

//  ajsdkffla

template <typename T>
size_t	Vector<T>::size(void) const
{
	return (_size);
}

// iterators

template< typename T >
VectorIterator<Vector<T> >	Vector<T>::begin()
{
	return (Iterator(_data));
}

template< typename T >
Iterator	Vector<T>::end()
{
	return (Iterator(_data + _size));
}

// operators

template <typename T>
T const&	Vector<T>::operator[](size_t i) const
{
	return (_data[i]);
}

template <typename T>
T&	Vector<T>::operator[](size_t i)
{
	return (_data[i]);
}

// private

template <typename T>
void	Vector<T>::ReAlloc(size_t newCapacity)
{
	std::cout << "ReAlloc to " << newCapacity << std::endl;
	T*	newBlock = new T[newCapacity];

	if (newCapacity < _size)
		_size = newCapacity;
	for (size_t i = 0 ; i < _size ; i++)
		newBlock[i] = _data[i];
	delete _data;
	_data = newBlock;
	_capacity = newCapacity;
}
