#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

template <typename T>
class	Vector {

public:

	Vector(void);

	void	push_back(T const & value);

	size_t	size(void) const;


	T const &	operator[](size_t i) const;
	T&			operator[](size_t i);
	

private:

	T*		_data;
	size_t	_size;
	size_t	_capacity;

	

	void	ReAlloc(size_t newCapacity);
};

#include "Vector.tpp"

#endif
