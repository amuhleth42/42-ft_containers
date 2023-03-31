#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace	ft
{

//	enable_if

template< bool Cond, class T = void >
struct	enable_if {};

template< class T >
struct	enable_if<true, T>
{
	typedef T type;
};

//	true_type and false_type

template< class T, T v >
struct	integral_constant
{
	typedef	T	value_type;
	typedef	integral_constant<T, v>	type;

	static const T	value = v;
	operator	value_type(void) const { return value; } // implicit conversion operator !
};

typedef	integral_constant<bool, true>	true_type;
typedef	integral_constant<bool, false>	false_type;

//	is_integral

template< typename T >							// general case
struct	is_integral : public false_type {};

template<>
struct	is_integral<bool> : public true_type {};

template<>
struct	is_integral<char> : public true_type {};

template<>
struct	is_integral<short> : public true_type {};

template<>
struct	is_integral<int> : public true_type {};

template<>
struct	is_integral<long> : public true_type {};

template<>
struct	is_integral<long long> : public true_type {};

template<>
struct	is_integral<unsigned char> : public true_type {};

template<>
struct	is_integral<unsigned short> : public true_type {};

template<>
struct	is_integral<unsigned int> : public true_type {};

template<>
struct	is_integral<unsigned long> : public true_type {};

template<>
struct	is_integral<unsigned long long> : public true_type {};


}

#endif
