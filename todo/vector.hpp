// Still left TODO in srcs/vector.hpp

template < class T, class Alloc = std::allocator<T> >
class vector {
	// constructors

	//template <class InputIterator>
	//vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

	//vector& operator=(const vector& x);

	// capacity

	//void		resize(size_type n, value_type val = value_type());
	//void		reserve(size_type n);

	// element access

	/*reference		front();
	const_reference	front() const;
	reference		back();
	const_reference	back() const;*/

	// modifiers 

	//template< class InputIterator >
	//void	assign(InputIterator first, InputIterator last);

	//void	assign(size_type n, const value_type& val);

	//void	push_back(const value_type& val);
	//void	pop_back();

	//iterator	insert(iterator position, const value_type& val);
	//void		insert(iterator position, size_type n, const value_type& val);

	//template< class InputIterator>
	//void	insert(iterator position, InputIterator first, InputIterator last);

	//iterator	erase(iterator position);
	//iterator	erase(iterator first, iterator last);

	//void	swap(vector& x);
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
