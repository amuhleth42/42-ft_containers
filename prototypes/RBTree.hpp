#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <memory>
# include "RBNode.hpp"
# include "map_iterator.hpp"
# include "reverse_iterator.hpp"
# include "algorithm.hpp"
# include "functional.hpp"
# include "utility.hpp"

namespace	ft
{

template< class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
class	RBTree
{

private:
	node_ptr	_newNode(const_reference content);
	void		_clearNode(node_ptr n);
	node_ptr	_getRoot() const;
	
	void	_leftRotate(node_ptr n);
	void	_rightRotate(node_ptr n);

	void	_insertFixup(node_ptr n);
	void	_deleteFixup(node_ptr x);

	void	_transplant(node_ptr x, node_ptr y);

	void	_clearFrom(node_ptr n);

	node_ptr	_findNode(const_reference k) const;

	iterator	_insertNode(const_reference k);
	int			_deleteNode(const node_ptr del);

public:
	RBTree()

	explicit RBTree(const key_compare& comp, const allocator_type alloc = allocator_type());

	template< class InputIt >
	RBTree(InputIt first, InputIt last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type());
	
	RBTree(const RBTree& src);

	~RBTree();

	RBTree&	operator=(const RBTree& rhs);

	allocator_type	get_allocator() const;

	//	capacity
	
	bool	empty() const;
	size_type	size() const;
	size_type	max_size() const;

	//	modifiers

	void	clear();

	ft::pair<iterator, bool>	insert(const_reference value);

	iterator	insert(iterator hint, const_reference value);

	template< class InputIt >
	void	insert(InputIt first, InputIt last);

	void	erase(iterator pos);
	void	erase(iterator first, iterator last);
	size_type	erase(const_reference key);
	
	void	swap(RBTree& other);

	//	lookup

	size_type	count( const_reference key) const;

	iterator	find(const_reference key);

	const_iterator	find(const_reference key) const;
	
	iterator	lower_bound(const_reference key);
	const_iterator	lower_bound(const_reference key) const;

	iterator	upper_bound(const_reference key);
	const_iterator	upper_bound(const_reference key) const;

	ft::pair<iterator, iterator>	equal_range(const_reference key);
	ft::pair<const_iterator, const_iterator>	equal_range(const_reference key) const;
	
	key_compare	key_comp() const;

	iterator		begin();
	const_iterator	begin() const;

	iterator		end();
	const_iterator	end() const;

	reverse_iterator		rbegin();
	const_reverse_iterator	rbegin() const;
	reverse_iterator		rend();
	const_reverse_iterator	rend() const;

};



}	// namespace ft

#endif
