#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include "utility.hpp"
#include "type_traits.hpp"
#include "functional.hpp"
#include "RBTree.hpp"
#include "iterator.hpp"

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

	};	// class value_compare

	typedef	RBTree<value_type, value_compare, allocator_type>	btree;
	
	typedef	typename btree::iterator				iterator;
	typedef	typename btree::const_iterator			const_iterator;
	typedef	typename btree::reverse_iterator		reverse_iterator;
	typedef	typename btree::const_reverse_iterator	const_reverse_iterator;
	
	//typedef	typename ft::iterator_traits<iterator>::difference_type	difference_type;
	typedef	ptrdiff_t	difference_type;
	typedef	size_t													size_type;

private:

	btree	_tree;


public:
	//constructors

	explicit	map(const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()) :
		_tree(btree(value_compare(comp), alloc))
	{}

	template< class InputIterator>
	map(InputIterator first, InputIterator last,
			const key_compare comp = key_compare(),
			const allocator_type& alloc = allocator_type()) :
		_tree(btree(first, last, value_compare(comp), alloc))
	{}

	map(const map& x) :
		_tree(btree(x.begin(), x.end(), x.key_comp(), x.get_allocator()))
	{}
	
	~map()
	{
		_tree.clear();
	}

	map&	operator=(const map& x)
	{
		if (this != &x)
			_tree = x._tree;
		return *this;
	}

	// iterators

	iterator		begin()				{ return _tree.begin(); }
	const_iterator	begin() const		{ return _tree.begin(); }
	iterator		end()				{ return _tree.end(); }
	const_iterator	end() const			{ return _tree.end(); }

	reverse_iterator		rbegin()			{ return _tree.rbegin(); }
	const_reverse_iterator	rbegin() const		{ return _tree.rbegin(); }
	reverse_iterator		rend()				{ return _tree.rend(); }
	const_reverse_iterator	rend() const		{ return _tree.rend(); }

	//	capacity

	bool		empty() const		{ return _tree.size() == 0; }
	size_type	size() const		{ return _tree.size(); }
	size_type	max_size() const	{ return _tree.max_size(); }

	// element access

	mapped_type&	operator[](const key_type& k)
	{
		iterator	it = _tree.find(value_type(k, mapped_type()));

		if (!it.getPtr())
			_tree.insert(value_type(k, mapped_type())).first;
		return it->second;
	}

	mapped_type&		at(const key_type& k)
	{
		iterator	it = _tree.find(value_type(k, mapped_type()));

		if (it.getPtr())
			return it->second;
		throw std::out_of_range("ft::map::at out of range");
	}

	const mapped_type&	at(const key_type& k) const
	{
		iterator	it = _tree.find(value_type(k, mapped_type()));

		if (it.getPtr())
			return it->second;
		throw std::out_of_range("ft::map::at out of range");
	}

	//	modifiers

	pair<iterator, bool>	insert(const value_type& val)
	{
		return _tree.insert(val);
	}

	iterator	insert(iterator position, const value_type& val)
	{
		return _tree.insert(position, val);
	}

	template< class InputIterator >
	void	insert(InputIterator first, InputIterator last)
	{
		return _tree.insert(first, last);
	}

	void		erase(iterator position)
	{
		_tree.erase(position);
	}

	size_type	erase(const key_type& k)
	{
		return _tree.erase(value_type(k, mapped_type()));
	}

	void		erase(iterator first, iterator last)
	{
		return _tree.erase(first, last);
	}

	void	swap(map& x)
	{
		_tree.swap(x._tree);
	}

	void	clear()
	{
		_tree.clear();
	}

	//	observers

	key_compare		key_comp() const		{ return key_compare(); }
	value_compare	value_comp() const		{ return value_compare(); }

	//	operations

	iterator		find(const key_type& k)
	{
		return _tree.find(value_type(k, mapped_type()));
	}

	const_iterator	find(const key_type& k) const
	{
		return _tree.find(value_type(k, mapped_type()));
	}

	size_type	count(const key_type* k) const
	{
		return _tree.count(value_type(k, mapped_type()));
	}

	iterator		lower_bound(const key_type& k)
	{
		return _tree.lower_bound(value_type(k, mapped_type()));
	}
	const_iterator	lower_bound(const key_type& k) const
	{
		return _tree.lower_bound(value_type(k, mapped_type()));
	}

	iterator		upper_bound(const key_type& k)
	{
		return _tree.upper_bound(value_type(k, mapped_type()));
	}
	const_iterator	upper_bound(const key_type& k) const
	{
		return _tree.upper_bound(value_type(k, mapped_type()));
	}

	pair<iterator, iterator>				equal_range(const key_type& k)
	{
		return _tree.equal_range(value_type(k, mapped_type()));
	}
	pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
	{
		return _tree.equal_range(value_type(k, mapped_type()));
	}

	//	allocator getter

	allocator_type	get_allocator() const		{ return allocator_type(); }

};


}	// namespace ft

#endif
