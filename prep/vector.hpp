#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

/*template< typename Vector >
class	VectorIterator {

public:

	typedef typename Vector<T> VecType;
	VectorIterator(VecType* ptr) : _ptr(ptr) {}

private:

	VecType*	_ptr;

};*/

//typedef VectorIterator<Vector<T> > Iterator;

template <typename T>
class	Vector {

public:

	//typedef VectorIterator<Vector<T> > Iterator;

	Vector(void);

	void	push_back(T const & value);

	size_t	size(void) const;

	Iterator	begin(void);
	Iterator	end(void);


	T const &	operator[](size_t i) const;
	T&			operator[](size_t i);

	// iterators
	

	template< typename Vector >
	class	VectorIterator {

	public:

		//typedef typename Vector<T> VecType;
		VectorIterator(VecType* ptr) : _ptr(ptr) {}

	private:

		VecType*	_ptr;

	};
		

	private:

		T*		_data;
		size_t	_size;
		size_t	_capacity;

		

		void	ReAlloc(size_t newCapacity);
	};

#include "Vector.tpp"

#endif
