#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace	ft
{

template< class T, class Container = ft::vector<T> >
class stack {

public:
	explicit	stack(const container_type& cont = container_type());

	stack(const stack& other);

	template< class InputIterator >
	stack(InputIterator first, InputIterator last);

	~stack();

	stack&	operator=(const stack& other);

	bool		empty() const;
	size_type	size() const;

	reference			top();
	const_reference		top() const;

	void	push(const value_type& val);

	void	pop();

	template< class T1, class Container1 >
	friend bool	operator==(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);
	
	template< class T1, class Container1 >
	friend bool	operator<(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);
};

template< class T, class Container >
bool	operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

template< class T, class Container >
bool	operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

template< class T, class Container >
bool	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

template< class T, class Container >
bool	operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

template< class T, class Container >
bool	operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

template< class T, class Container >
bool	operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);


}		// namespace ft

#endif
