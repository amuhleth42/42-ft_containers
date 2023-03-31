#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

namespace	ft
{

template< class InputIt1, class InputIt2 >
bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
{
	for (; first1 != last1 ; first1++, first2++)
	{
		if (!(*first1 == *first2))
			return false;
	}
	return true;
}


template< class InputIt1, class InputIt2, class BinaryPredicate >
bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate pred)
{
	for (; first1 != last1 ; first1++, first2++)
	{
		if (!pred(*first1, *first2))
			return false;
	}
	return true;
}

//	true if 2 is less than 1

template< class InIt1, class InIt2 >
bool	lexicographical_compare(InIt1 first1, InIt1 last1, InIt2 first2, InIt2 last2)
{
	for (; first1 != last1 ; first1++, first2++)
	{
		if (first2 == last2 || *first2 < *first1)
			return false;
		else if (*first1 < *first2)
			return true;
	}
	return (first2 != last2);
}

template< class InIt1, class InIt2, class Comp>
bool	lexicographical_compare(InIt1 first1, InIt1 last1, InIt2 first2, InIt2 last2, Comp comp)
{
	for (; first1 != last1 ; first1++, first2++)
	{
		if (first2 == last2 || comp(*first2, *first1))
			return false;
		else if (*first1 < *first2)
			return true;
	}
	return (first2 != last2);
}

template< class T >
void	swap(T& a, T& b)
{
	T	c(a);
	a = b;
	b = c;
}

}		// namespace ft


#endif
