#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace	ft
{

template< class T, class Container = ft::vector<T> >
class stack {

public:
	typedef	Container							container_type;
	typedef	typename Container::value_type		value_type;
	typedef	typename Container::size_type		size_type;
	typedef	typename Container::reference		reference;
	typedef	typename Container::const_reference	const_reference;

protected:
	container_type	_c;

public:
	explicit	stack(const container_type& cont = container_type()) : _c(cont) {}

	stack(const stack& other) : _c(other._c) {}

	template< class InputIterator >
	stack(InputIterator first, InputIterator last) : _c(first, last) {}	// cause I'm nice

	~stack() {}

	stack&	operator=(const stack& other)
	{
		_c = other._c;
		return *this;
	}

	bool		empty() const 		{ return _c.empty(); }
	size_type	size() const 		{ return _c.size(); }

	reference			top()			{ return _c.back(); }
	const_reference		top() const		{ return _c.back(); }

	void	push(const value_type& val)
	{
		_c.push_back(val);
	}

	void	pop()
	{
		_c.pop_back();
	}

	template< class T1, class Container1 >
	friend bool	operator==(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);
	
	template< class T1, class Container1 >
	friend bool	operator<(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);
};

template< class T, class Container >
bool	operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (lhs._c == rhs._c);
}

template< class T, class Container >
bool	operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return !(lhs == rhs);
}

template< class T, class Container >
bool	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (lhs._c < rhs._c);
}

template< class T, class Container >
bool	operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return !(rhs < lhs);
}

template< class T, class Container >
bool	operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (rhs < lhs);
}

template< class T, class Container >
bool	operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return !(lhs < rhs);
}


}		// namespace ft

#endif
