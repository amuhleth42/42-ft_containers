#ifndef FUNCTIONAL_HPP
# define FUNCTIONAL_HPP

// TODO : binary_function

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

#endif
