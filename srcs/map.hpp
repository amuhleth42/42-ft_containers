#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include "utility.hpp"
#include "type_traits.hpp"
#include "functional.hpp"
#include "RBTree.hpp"

#include <iterator>	// tmp

namespace	ft
{


template<
	class Key,
	class T,
	class Compare = ft::less<Key>,
	class Alloc = std::allocator< ft::pair<const Key, T> > >
class map {

public:
	typedef	Key						key_type;
	typedef	T						mapped_type;
	typedef	ft::pair<const Key, T>	value_type;
	typedef	Compare					key_compare;
	typedef	Alloc					allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;

	typedef	typename tree::iterator					iterator;
	typedef	typename tree::const_iterator			const_iterator;
	typedef	typename tree::reverse_iterator			reverse_iterator;
	typedef	typename tree::const_reverse_iterator	const_reverse_iterator;

	typedef	typename iterator_traits<iterator>::difference_type	difference_type;
	typedef	size_t												size_type;

	class	value_compare : public binary_function<value_type, value_type, bool>
	{
		friend class map;
	protected:
		Compare	comp;
		value_compare(Compare c) : comp(c) {}

	public:
		typedef bool	result_type;
		typedef	value_type	first_argument_type;
		typedef	value_type	second_argument_type;

		bool	operator()(const value_type& x, const value_type& y) const
		{	
			return comp(x.first, y.first);
		}

	}







public:
	//constructors
	explicit	map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

	template< class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare comp = key_compare(), const allocator_type& alloc = allocator_type());

	map(const map& x);
	
	~map();

	map&	operator=(const map& x);

	// iterators

	iterator		begin();
	const_iterator	begin() const
	iterator		end();
	const_iterator	end() const

	reverse_iterator		rbegin();
	const_reverse_iterator	rbegin() const;
	reverse_iterator		rend();
	const_reverse_iterator	rend() const;

	//	capacity

	bool		empty() const;
	size_type	size() const;
	size_type	max_size() const;

	// element access

	mapped_type&	operator[](const key_type& k);

	mapped_type*		at(const key_type& k);
	const mapped_type&	at(const key_type& k) const;

	//	modifiers

	pair<iterator, bool>	insert(const value_type& val);
	iterator	insert(iterator position, const value_type& val);

	template< class InputIterator >
	void	insert(InputIterator first, InputIterator last);

	void		erase(iterator position);
	size_type	erase(const key_type& k);
	void		erase(iterator fist, iterator last);

	void	swap(map& x);
	void	clear();

	//	observers

	key_compare		key_comp() const;
	value_compare	value_comp() const;

	//	operations

	iterator		find(const key_type& k);
	const_iterator	find(const key_type& k) const;

	size_type	count(const key_type* k) const;

	iterator		lower_bound(const key_type& k);
	const_iterator	lower_bound(const key_type& k) const;

	iterator		upper_bound(const key_type& k);
	const_iterator	upper_bound(const key_type& k) const;

	pair<iterator, iterator>				equal_range(const key_type& k);
	pair<const_iterator, const_iterator>	equal_range(const key_type& k);

	//	allocator getter

	allocator_type	get_allocator() const;

};


}	// namespace ft

#endif
