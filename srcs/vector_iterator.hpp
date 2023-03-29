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

template< class Iter >
class	reverse_iterator {
public:
	typedef	Iter								iterator_type;
	typedef	typename Iter::iterator_category	iterator_category;
	typedef	typename Iter::value_type			value_type;
	typedef	typename Iter::difference_type		difference_type;
	typedef	typename Iter::pointer				pointer;
	typedef	typename Iter::reference			reference;

	typedef	typename Iter::const_iterator		const_iterator;

private:
	iterator_type	_current;

public:

	reverse_iterator() :					_current(Iter()) {}
	
	explicit
	reverse_iterator(iterator_type it) :	_current(it) {}

	reverse_iterator(const reverse_iterator& rev_it)	{ *this = rev_it; }

	~reverse_iterator()	{}

	reverse_iterator&	operator=(const reverse_iterator& rhs)
	{
		_current = rhs._current;
		return *this;
	}

	pointer	base() const		{ return _current.getPtr(); }

	reference	operator*(void) const
	{
		iterator_type	tmp = _current;
		return *--tmp;
	}
	pointer		operator->(void) const		{ return &(operator*()); }

	reference	operator[](difference_type n) const		{ return *(*this + n); }

	operator	reverse_iterator<const_iterator>() const
	{
		return reverse_iterator<const_iterator>(_current);
	}

	reverse_iterator&	operator++()
	{
		--_current;
		return *this;
	}
	
	reverse_iterator	operator++(int)
	{
		return reverse_iterator(_current--);
	}
	
	reverse_iterator&	operator--()
	{
		++_current;
		return *this;
	}
	
	reverse_iterator	operator--(int)
	{
		return reverse_iterator(_current++);
	}

	reverse_iterator	operator+(difference_type n) const
	{
		return reverse_iterator(_current - n);
	}
	
	reverse_iterator	operator-(difference_type n) const
	{
		return reverse_iterator(_current + n);
	}
	
	difference_type		operator-(reverse_iterator rhs) const
	{
		return rhs.base() - base();
	}

	bool	operator==(const reverse_iterator& rhs) const	{ return _current == rhs._current; }
	bool	operator!=(const reverse_iterator& rhs) const	{ return _current != rhs._current; }
	bool	operator>(const reverse_iterator& rhs) const	{ return _current > rhs._current; }
	bool	operator>=(const reverse_iterator& rhs) const	{ return _current >= rhs._current; }
	bool	operator<(const reverse_iterator& rhs) const	{ return _current < rhs._current; }
	bool	operator<=(const reverse_iterator& rhs) const	{ return _current <= rhs._current; }

	reverse_iterator&	operator+=(difference_type n)
	{
		_current -= n;
		return *this;
	}

	reverse_iterator&	operator-=(difference_type n)
	{
		_current += n;
		return *this;
	}
};

template< class Iter >
reverse_iterator<Iter>	operator+(typename reverse_iterator<Iter>::difference_type n,
									const reverse_iterator<Iter>& rhs)
{
	return reverse_iterator<Iter>(rhs.base() - n);
}


}		// namespace ft

#endif
