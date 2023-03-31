#ifndef FUNCTIONAL_HPP
# define FUNCTIONAL_HPP

// TODO : binary_function
namespace	ft
{


template< class Arg1, class Arg2, class Result >
struct	binary_function
{
	typedef	Arg1	first_argument_type;
	typedef	Arg2	second_argument_type;
	typedef	Result	result_type;
};

template< class T >
struct	less : binary_function<T, T, bool>
{
	typedef	T		first_argument_type;
	typedef	T		second_argument_type;
	typedef	bool	result_type;


	bool	operator()(const T& x, const T& y) const
	{
		return x < y;
	}
};


}	// namespace ft

#endif
