#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "iterator.hpp"

namespace	ft
{

template< typename T >
class	vector_iterator : public ft::iterator<ft::random_access_iterator_tag, T> {

public:
	typedef	ft::iterator<ft::random_access_iterator_tag, T>	parent;

	typedef	typename parent::difference_type		difference_type;
	typedef	typename parent::value_type			value_type;
	typedef	typename parent::pointer				pointer;
	typedef	typename parent::reference			reference;
	typedef	typename parent::iterator_category	iterator_category;

	typedef	vector_iterator<const T>	const_iterator;


private:
	pointer	_p;

public:

	vector_iterator() :				_p(NULL) {}
	vector_iterator(pointer p) :	_p(p) {}

	vector_iterator(const vector_iterator& src) { *this = src; }
	
	~vector_iterator() {}

	vector_iterator&	operator=(const vector_iterator& rhs)
	{
		_p = rhs._p;
		return *this;
	}

	operator	vector_iterator<const T>() const
	{
		return vector_iterator<const T>(_p);
	}

	pointer	getPtr() const			{ return _p; }

	reference	operator*() const		{ return *_p; }
	pointer		operator->() const		{ return _p; }

	reference	operator[](size_t i) const		{ return _p[i]; }

	vector_iterator&	operator++()
	{
		++_p;
		return *this;
	}

	vector_iterator		operator++(int)
	{
		return vector_iterator(_p++);
	}

	vector_iterator&	operator--()
	{
		--_p;
		return *this;
	}

	vector_iterator		operator--(int)
	{
		return vector_iterator(_p--);
	}

	vector_iterator	operator+(const difference_type n) const
	{
		return vector_iterator(_p + n);
	}

	vector_iterator	operator-(const difference_type n) const
	{
		return vector_iterator(_p - n);
	}

	difference_type	operator-(vector_iterator rhs) const
	{
		return (_p - rhs._p);
	}
	

	bool	operator==(const vector_iterator& rhs) const	{ return _p == rhs._p; }
	bool	operator!=(const vector_iterator& rhs) const	{ return _p != rhs._p; }
	bool	operator<(const vector_iterator& rhs) const		{ return _p < rhs._p; }
	bool	operator<=(const vector_iterator& rhs) const	{ return _p <= rhs._p; }
	bool	operator>(const vector_iterator& rhs) const		{ return _p > rhs._p; }
	bool	operator>=(const vector_iterator& rhs) const	{ return _p >= rhs._p; }

	vector_iterator	operator+=(difference_type n)
	{
		_p += n;
		return *this;
	}

	vector_iterator	operator-=(difference_type n)
	{
		_p -= n;
		return *this;
	}

};

template< typename T >
vector_iterator<T>	operator+(typename vector_iterator<T>::difference_type n,
								const vector_iterator<T>& rhs)
{
	return vector_iterator<T>(rhs.getPtr() + n);
}

}		// namespace ft

#endif
