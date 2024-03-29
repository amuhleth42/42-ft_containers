#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace	ft
{

struct	input_iterator_tag	{};
struct	output_iterator_tag	{};
struct	forward_iterator_tag		: public input_iterator_tag			{};
struct	bidirectional_iterator_tag	: public forward_iterator_tag		{};
struct	random_access_iterator_tag	: public bidirectional_iterator_tag	{};

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

template< class Category,
			class T,
			class Distance = ptrdiff_t,
			class Pointer = T*,
			class Reference = T& >

class	iterator {
public :
	typedef	T			value_type;
	typedef	Distance	difference_type;
	typedef	Pointer		pointer;
	typedef	Reference	reference;
	typedef	Category	iterator_category;
};

template< class InputIt >
typename InputIt::difference_type	distance(InputIt first, InputIt last)
{
	typename InputIt::difference_type	n = 0;

	for (; first != last ; n++, first++);

	return n;
}

}		//	namespace ft

#endif
