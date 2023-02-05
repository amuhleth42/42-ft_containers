#include "Vector.hpp"

// public

template <typename T>
Vector<T>::Vector(void) : _data(NULL), _size(0), _capacity(0)
{
	ReAlloc(2);
}

template <typename T>
void	Vector<T>::push_back(T const & value)
{
	if (_size >= _capacity)
		_capacity = _capacity * 2;

	_data[_size] = value;
	_size++;
}

template <typename T>
size_t	Vector<T>::size(void) const
{
	return (_size);
}

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
	T*	newBlock = new T[newCapacity];

	if (newCapacity < _size)
		_size = newCapacity;
	for (size_t i = 0 ; i < _size ; i++)
		newBlock[i] = std::move(_data[i]);
	delete _data;
	_data = newBlock;
	_capacity = newCapacity;
}
