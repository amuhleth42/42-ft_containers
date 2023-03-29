#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator.hpp"

namespace	ft
{

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
		reverse_iterator	tmp = *this;
		--_current;
		return tmp;
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

	/*bool	operator==(const reverse_iterator& rhs) const	{ return _current == rhs._current; }
	bool	operator!=(const reverse_iterator& rhs) const	{ return _current != rhs._current; }
	bool	operator>(const reverse_iterator& rhs) const	{ return _current > rhs._current; }
	bool	operator>=(const reverse_iterator& rhs) const	{ return _current >= rhs._current; }
	bool	operator<(const reverse_iterator& rhs) const	{ return _current < rhs._current; }
	bool	operator<=(const reverse_iterator& rhs) const	{ return _current <= rhs._current; }*/

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

template< class ItL, class ItR >
bool	operator==(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
{
	return lhs.base() == rhs.base();
}

template< class ItL, class ItR >
bool	operator!=(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
{
	return lhs.base() != rhs.base();
}

template< class ItL, class ItR >
bool	operator<(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
{
	return lhs.base() > rhs.base();
}

template< class ItL, class ItR >
bool	operator<=(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
{
	return lhs.base() >= rhs.base();
}

template< class ItL, class ItR >
bool	operator>(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
{
	return lhs.base() < rhs.base();
}

template< class ItL, class ItR >
bool	operator>=(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
{
	return lhs.base() <= rhs.base();
}

}	//	namespace ft

#endif
