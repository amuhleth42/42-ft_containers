#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iterator> // tmp

# include "iterator_tags.hpp"

namespace	ft
{

template < class T, class Alloc = std::allocator<T> >
class vector {

public:
	typedef T	value_type;
	typedef Alloc	allocator_type;
	typedef typename allocator_type::reference	reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer		pointer;
	typedef typename allocator_type::const_pointer	const_pointer;

	typedef	std::iterator<ft::random_access_iterator_tag, T>		iterator;
	typedef	std::iterator<ft::random_access_iterator_tag, const T>	const_iterator;
	typedef	std::reverse_iterator<iterator>	reverse_iterator;
	typedef	std::reverse_iterator<const_iterator>	const_reverse_iterator;

	typedef	ptrdiff_t	difference_type;
	//typedef	iterator_traits<iterator>::difference_type	difference_type;
	typedef	size_t	size_type;

private:

	allocator_type	_alloc;
	size_type		_size;
	size_type		_capacity;
	pointer			_data;
	
public:
	// constructors
	explicit	vector(const allocator_type& alloc = allocator_type()) :
		_alloc(alloc),
		_size(0),
		_capacity(0),
		_data(NULL)
	{}

	explicit	vector(size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type()) :
		_alloc(alloc),
		_size(n),
		_capacity(n),
		_data(_alloc.allocate(_capacity))
	{
		for (size_type i = 0 ; i < _size ; i++)
			_alloc.construct(_data + i, val);
	}

	//template <class InputIterator>
	//vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

	vector(const vector& x) :
		_alloc(x._alloc),
		_size(x._size),
		_capacity(x._capacity),
		_data(_alloc.allocate(_capacity))
	{
		for (size_type i = 0 ; i < _size ; i++)
			_alloc.construct(_data + i, x._data[i]);
	}

	~vector()
	{
		clear();
		_alloc.deallocate(_data, _capacity);
	}

	vector& operator=(const vector& x);

	// iterators

	iterator		begin()				{ return iterator(_data); }
	const_iterator	begin() const		{ return const_iterator(_data); }
	iterator		end()				{ return iterator(_data + _size); }
	const_iterator	end() const			{ return const_iterator(_data + _size); }

	reverse_iterator		rbegin()			{ return reverse_iterator(end() - 1); }
	const_reverse_iterator	rbegin() const		{ return const_reverse_iterator(end() - 1); }
	reverse_iterator		rend()				{ return reverse_iterator(begin() - 1); }
	const_reverse_iterator	rend() const		{ return const_reverse_iterator(begin() - 1); }

	// capacity

	size_type	size() const 			{ return _size; }
	size_type	max_size() const		{ return _alloc.max_size(); }

	void		resize(size_type n, value_type val = value_type());
	size_type	capacity() const 		{ return _capacity; }
	bool		empty() const 			{ return (_size == 0); }

	void		reserve(size_type n)
	{
		if (n >= max_size())
			throw std::length_error("impossible to allocate more than max_size()");
		if (n < _capacity)
			return ;

		pointer	newData = _alloc.allocate(n);
		
		for (size_type i = 0 ; i < _size ; i++)
		{
			_alloc.construct(newData + i, _data[i]);
			_alloc.destroy(_data + i);
		}
		_alloc.deallocate(_data, _capacity);
		_capacity = n;
		_data = newData;
	}

	// element access

	reference		operator[](size_type n)			{ return (_data[n]); }
	const_reference	operator[](size_type n) const	{ return (_data[n]); }

	reference		at(size_type n)
	{
		if (n < _size)
			return (_data[n]);
		else
			throw std::out_of_range("vector: index out of range");
	}
	const_reference	at(size_type n) const
	{
		if (n < _size)
			return (_data[n]);
		else
			throw std::out_of_range("vector: index out of range");
	}

	reference		front()				{ return (_data[0]); }
	const_reference	front() const		{ return (_data[0]); }
	reference		back()				{ return (_data[_size]); }
	const_reference	back() const		{ return (_data[_size]); }

	value_type*			data()			{ return _data; }
	const value_type*	data() const	{ return _data; }

	// modifiers 

	template< class InputIterator >
	void	assign(InputIterator first, InputIterator last);

	void	assign(size_type n, const value_type& val);

	void	push_back(const value_type& val)
	{
		if (_size == _capacity)
			reserve(_capacity == 0 ? 1 : _capacity * 2);

		_alloc.construct(_data + _size, val);
		_size++;
	}

	void	pop_back()
	{
		if (_size == 0)
			return ;
		_alloc.destroy(_data + _size - 1);
		_size--;
	}

	iterator	insert(iterator position, const value_type& val);
	void		insert(iterator position, size_type n, const value_type& val);

	template< class InputIterator>
	void	insert(iterator position, InputIterator first, InputIterator last);

	iterator	erase(iterator position);
	iterator	erase(iterator first, iterator last);

	void	swap(vector& x);

	void	clear()
	{
		for (size_type i = 0 ; i < _size ; i++)
			_alloc.destroy(_data + i);
		_size = 0;
	}

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
