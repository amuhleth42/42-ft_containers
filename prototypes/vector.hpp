#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
//# include <iterator> // tmp
# include "utility.hpp"

# include "type_traits.hpp"
# include "algorithm.hpp"
# include "vector_iterator.hpp"
# include "reverse_iterator.hpp"

namespace	ft
{

template < class T, class Alloc = std::allocator<T> >
class vector {

public:
	// constructors
	explicit	vector(const allocator_type& alloc = allocator_type());

	explicit	vector(size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type());

	template <class InputIterator>
	vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
			InputIterator last,
			const allocator_type& alloc = allocator_type());

	vector(const vector& x);

	~vector();

	vector& operator=(const vector& x);

	// iterators

	iterator		begin()				{ return iterator(_data); }
	const_iterator	begin() const		{ return const_iterator(_data); }
	iterator		end()				{ return iterator(_data + _size); }
	const_iterator	end() const			{ return const_iterator(_data + _size); }

	reverse_iterator		rbegin()			{ return reverse_iterator(end()); }
	const_reverse_iterator	rbegin() const		{ return const_reverse_iterator(end()); }
	reverse_iterator		rend()				{ return reverse_iterator(begin()); }
	const_reverse_iterator	rend() const		{ return const_reverse_iterator(begin()); }

	// capacity

	size_type	size() const 			{ return _size; }
	size_type	max_size() const		{ return _alloc.max_size(); }

	void		resize(size_type n, value_type val = value_type());
	

	size_type	capacity() const 		{ return _capacity; }
	bool		empty() const 			{ return (_size == 0); }

	void		reserve(size_type n);

	// element access

	reference		operator[](size_type n)			{ return (_data[n]); }
	const_reference	operator[](size_type n) const	{ return (_data[n]); }

	reference		at(size_type n);
	const_reference	at(size_type n) const;

	reference		front()				{ return (_data[0]); }
	const_reference	front() const		{ return (_data[0]); }
	reference		back()				{ return (_data[_size - 1]); }
	const_reference	back() const		{ return (_data[_size - 1]); }

	value_type*			data()			{ return _data; }
	const value_type*	data() const	{ return _data; }

	// modifiers 

	template< class InputIt >
	void	assign(InputIt first,
					typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last);
	void	assign(size_type n, const value_type& val);

	void	push_back(const value_type& val);

	void	pop_back();

	iterator	insert(iterator position, const value_type& val);

	void		insert(iterator position, size_type n, const value_type& val);

	template< class InputIterator>
	void	insert(iterator position,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
		InputIterator last);

	iterator	erase(iterator position);

	iterator	erase(iterator first, iterator last);

	void	swap(vector& x);

	void	clear();
	
	//	allocator getter

	allocator_type	get_allocator() const		{ return _alloc; }
};

template< class T, class Alloc>
bool	operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

template< class T, class Alloc>
bool	operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

template< class T, class Alloc>
bool	operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

template< class T, class Alloc>
bool	operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

template< class T, class Alloc>
bool	operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

template< class T, class Alloc>
bool	operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

template< class T, class Alloc>
void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y);

}
#endif
