#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "iterator_tags.hpp"

template< class Iterator >
struct	iterator_traits
{
	typedef	typename Iterator::difference_type		difference_type;
	typedef	typename Iterator::value_type			value_type;
	typedef	typename Iterator::pointer				pointer;
	typedef	typename Iterator::reference			reference;
	typedef	typename Iterator::iterator_category	iterator_cateory;
};

template< class T >
struct	iterator_traits< T* >
{
	typedef	ptrdiff_t	difference_type;
	typedef	T			value_type;
	typedef	T*			pointer;
	typedef	T&			reference;
	typedef	ft::random_access_iterator_tag	iterator_cateory;
};


template< class T >
struct	iterator_traits< const T* >
{
	typedef	ptrdiff_t	difference_type;
	typedef	T			value_type;
	typedef	T*			pointer;
	typedef	T&			reference;
	typedef	ft::random_access_iterator_tag	iterator_cateory;
};

#endif
