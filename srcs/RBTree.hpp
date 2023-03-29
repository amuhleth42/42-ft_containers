#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <memory>
# include "RBNode.hpp"
# include "map_iterator.hpp"

namespace	ft
{

template< class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
class	RBTree
{

public:
	typedef	RBNode<T>	node_type;
	typedef	RBNode<T>*	node_ptr;

	typedef	T			value_type;

	typedef	Compare		key_compare;
	typedef	Alloc		allocator_type;

	typedef	typename Alloc::template rebind<node_type>::other	node_allocator;

	typedef	typename allocator_type::reference			reference;
	typedef	typename allocator_type::const_reference	const_reference;
	typedef	typename allocator_type::pointer			pointer;
	typedef	typename allocator_type::const_pointer		const_pointer;

	typedef	ft::map_iterator<node_type, value_type>			iterator;
	typedef	ft::map_iterator<node_type, const value_type>	const_iterator;

	typedef std::reverse_iterator<iterator>			reverse_iterator;
	typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

	typedef	size_t		size_type;
	typedef	ptrdiff_t	difference_type;

private:
	allocator_type	_alloc;
	node_allocator	_node;
	key_compare		_comp;
	
	node_ptr	_root;
	node_ptr	_first;
	node_ptr	_last;
	size_type	_size;

private:
	node_ptr	newNode(const_reference content)
	{
		node_ptr	n = _node.allocate(1);
		_node.construct(n, node_type(content));
		return n;
	}

	void	deleteNode(node_ptr n)
	{
		_node.destroy(n);
		_node.deallocate(n, 1);
	}

	node_ptr	getRoot() const			{ return _root; }
	
	void	leftRotate(node_ptr n)
	{
		node_ptr	x = n;
		node_ptr	y = n->right;
		node_ptr	p = x->p;
		node_ptr	b = y->left;

		n->right = b;
		if (b)
			b->p = x;
		y->p = p;
		if (!p)
			_root = y;
		else if (x == p->left)
			p->left = y;
		else
			p->right = y;
		y->left = x;
		x->p = y;
	}

	void	rightRotate(node_ptr n)
	{
		node_ptr	x = n->left;
		node_ptr	y = n;
		node_ptr	p = y->p;
		node_ptr	b = x->right;

		x->right = y;
		if (b)
			b->p = y;
		x->p = p;
		if (!p)
			_root = x;
		else if (p->right == y)
			p->right = x;
		else
			p->left = x;
		y->left = b;
		y->p = x;
	}

	void	insertFix(node_ptr newNode);
	void	deleteFix(node_ptr x);

	void	transplant(node_ptr x, node_ptr y)
	{
		if (x->p == NULL)
			_root = y;
		else if (x->p->left == x)
			x->p->left = y;
		else
			x->p->right = y;

		if (y)
			y->p = x->p;
	}

	void	clearFrom(node_ptr n) const
	{
		if (!n)
			return ;
		if (n->left)
			clearFrom(n->left);
		if (n->right)
			clearFrom(n->right);
		deleteNode(n);
	}

	node_ptr	_getNode(const_reference k) const;

	iterator	insertNode(const_reference k, node_ptr hint = NULL);

	//int	deleteNode(const node_ptr toDelete);

public:
	RBTree();

	explicit RBTree(...);

	template< class InputIterator >
	RBTree(...);

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
