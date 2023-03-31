#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "iterator.hpp"

namespace	ft
{

template< typename T >
class	vector_iterator : public ft::iterator<ft::random_access_iterator_tag, T> {

public:

	vector_iterator();
	vector_iterator(pointer p);

	vector_iterator(const vector_iterator& src);
	
	~vector_iterator();

	vector_iterator&	operator=(const vector_iterator& rhs);

	operator	vector_iterator<const T>() const;

	pointer	getPtr() const;

	reference	operator*() const;
	pointer		operator->() const;

	reference	operator[](size_t i) const;

	vector_iterator&	operator++();
	vector_iterator		operator++(int);

	vector_iterator&	operator--();
	vector_iterator		operator--(int);

	vector_iterator	operator+(const difference_type n) const;
	vector_iterator	operator-(const difference_type n) const;
	difference_type	operator-(vector_iterator rhs) const;
	

	bool	operator==(const vector_iterator& rhs) const	{ return _p == rhs._p; }
	bool	operator!=(const vector_iterator& rhs) const	{ return _p != rhs._p; }
	bool	operator<(const vector_iterator& rhs) const		{ return _p < rhs._p; }
	bool	operator<=(const vector_iterator& rhs) const	{ return _p <= rhs._p; }
	bool	operator>(const vector_iterator& rhs) const		{ return _p > rhs._p; }
	bool	operator>=(const vector_iterator& rhs) const	{ return _p >= rhs._p; }

	vector_iterator	operator+=(difference_type n);

	vector_iterator	operator-=(difference_type n);

};

template< typename T >
vector_iterator<T>	operator+(typename vector_iterator<T>::difference_type n,
								const vector_iterator<T>& rhs);
template< class T1, class T2 >
bool	operator==(const vector_iterator<T1>& lhs, const vector_iterator<T2>& rhs);

template< class T1, class T2 >
bool	operator!=(const vector_iterator<T1>& lhs, const vector_iterator<T2>& rhs);

template< class T1, class T2 >
bool	operator<(const vector_iterator<T1>& lhs, const vector_iterator<T2>& rhs);

template< class T1, class T2 >
bool	operator<=(const vector_iterator<T1>& lhs, const vector_iterator<T2>& rhs);

template< class T1, class T2 >
bool	operator>(const vector_iterator<T1>& lhs, const vector_iterator<T2>& rhs);

template< class T1, class T2 >
bool	operator>=(const vector_iterator<T1>& lhs, const vector_iterator<T2>& rhs);

}		// namespace ft

#endif
