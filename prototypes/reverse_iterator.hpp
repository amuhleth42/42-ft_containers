#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator.hpp"

namespace	ft
{

template< class Iter >
class	reverse_iterator {

public:

	reverse_iterator();
	explicit reverse_iterator(iterator_type it);
	reverse_iterator(const reverse_iterator& rev_it);
	~reverse_iterator();

	reverse_iterator&	operator=(const reverse_iterator& rhs);

	iterator_type	base() const;

	reference	operator*(void) const;
	pointer		operator->(void) const;

	reference	operator[](difference_type n) const;

	operator	reverse_iterator<const_iterator>() const;

	reverse_iterator&	operator++();
	reverse_iterator	operator++(int);

	reverse_iterator&	operator--();
	reverse_iterator	operator--(int);

	reverse_iterator	operator+(difference_type n) const;
	reverse_iterator	operator-(difference_type n) const;
	difference_type		operator-(reverse_iterator rhs) const;

	reverse_iterator&	operator+=(difference_type n);
	reverse_iterator&	operator-=(difference_type n);
};

template< class Iter >
reverse_iterator<Iter>	operator+(typename reverse_iterator<Iter>::difference_type n,
									const reverse_iterator<Iter>& rhs);

template< class ItL, class ItR >
bool	operator==(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs);

template< class ItL, class ItR >
bool	operator!=(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs);

template< class ItL, class ItR >
bool	operator<(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs);

template< class ItL, class ItR >
bool	operator<=(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs);

template< class ItL, class ItR >
bool	operator>(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs);

template< class ItL, class ItR >
bool	operator>=(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs);

}	//	namespace ft

#endif
