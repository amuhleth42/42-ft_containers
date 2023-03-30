#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <memory>
# include "RBNode.hpp"
# include "map_iterator.hpp"
# include "algorithm.hpp"

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

	//typedef	enum {BLACK, RED}	color_type;
	typedef	ft::color	color_type;

private:
	allocator_type	_alloc;
	node_allocator	_node;
	key_compare		_comp;
	
	node_ptr	_root;
	node_ptr	_first;
	node_ptr	_last;
	size_type	_size;

private:
	node_ptr	_newNode(const_reference content)
	{
		node_ptr	n = _node.allocate(1);
		_node.construct(n, node_type(content));
		return n;
	}

	void	_clearNode(node_ptr n)
	{
		_node.destroy(n);
		_node.deallocate(n, 1);
	}

	node_ptr	_getRoot() const			{ return _root; }
	
	void	_leftRotate(node_ptr n)
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

	void	_rightRotate(node_ptr n)
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

	void	_insertFix(node_ptr newNode);
	void	_deleteFix(node_ptr x);

	void	_transplant(node_ptr x, node_ptr y)
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

	void	_clearFrom(node_ptr n)
	{
		if (!n)
			return ;
		if (n->left)
			_clearFrom(n->left);
		if (n->right)
			_clearFrom(n->right);
		_clearNode(n);
	}

	node_ptr	_findNode(const_reference k) const
	{
		node_ptr	ptr = _root;

		while (ptr)
		{
			if (!_comp(k, ptr->content) && !_comp(ptr->content, k))
				return ptr;
			if (_comp(k, ptr->content))
				ptr = ptr->left;
			else
				ptr = ptr->right;
		}
		return ptr;
	}

	iterator	_insertNode(const_reference k)
	{
		if (_findNode(k))
			return iterator(NULL, _root);

		node_ptr	ptr = _root;
		node_ptr	parent = NULL;
		node_ptr	n = _newNode(k);

		_size++;
		//newNode->color = RED;
		if (_size == 1 || _comp(n->content, _first->content))
			_first = n;
		if (_size == 1 || _comp(_last->content, n->content))
			_last = n;
		while (ptr)
		{
			parent = ptr;
			if (_comp(k, ptr->content))
				ptr = ptr->left;
			else
				ptr = ptr->right;
		}
		n->p = parent;
		if (!parent)
			_root = n;
		else if (_comp(n->content, parent->content))
			parent->left = n;
		else
			parent->right = n;

		if (!parent)
			n->color = BLACK;
		//else if (parent->p)
			//_insertFixup(n);
		return iterator(n, _root);
	}

	int	_deleteNode(const node_ptr del)
	{
		color_type	color;
		node_ptr	x;
		node_ptr	y;

		if (!del)
			return 0;
		if (del == _first)
			_first = del->next();
		if (del == _last)
			_last = del->previous();
		color = del->color;
		if (!del->left)			// case 1
		{
			x = del->right;
			_transplant(del, x);
		}
		else if (!del->right)	// case 2
		{
			x = del->left;
			_transplant(del, x);
		}
		else					// case 3
		{
			y = del->right->min();
			color = y->color;
			x = y->right;
			if (x && y->p == del)
				x->p = y;
			else
			{
				_transplant(y, y->right);
				y->right = del->right;
				if (y->right)
					y->right->p = y;
			}
			_transplant(del, y);
			y->left = del->left;
			y->left->p = y;
			y->color = del->color;
		}
		_clearNode(del);
		if (color == BLACK)
			color = RED;
		//	_deleteFix(x);*/
		_size--;
		return 1;
	}

public:
	RBTree() :
		_alloc(allocator_type()),
		_node(node_allocator()),
		_comp(key_compare()),
		_root(NULL),
		_first(NULL),
		_last(NULL),
		_size(0)
	{}

	explicit RBTree(const key_compare& comp, const allocator_type alloc = allocator_type()) :
		_alloc(alloc),
		_node(node_allocator(allocator_type())),
		_comp(comp),
		_root(NULL),
		_first(NULL),
		_last(NULL),
		_size(0)
	{}

	template< class InputIt >
	RBTree(InputIt first, InputIt last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type()) :
		_alloc(alloc),
		_node(node_allocator(allocator_type())),
		_comp(comp),
		_root(NULL),
		_first(NULL),
		_last(NULL),
		_size(0)
	{
		insert(first, last);
	}


	RBTree(const RBTree& src) :
		_alloc(src._alloc),
		_node(src._node),
		_comp(src._comp),
		_root(NULL),
		_first(NULL),
		_last(NULL),
		_size(0)
	{
		insert(src.begin(), src.end());
	}

	~RBTree()
	{
		clear();
	}

	RBTree&	operator=(const RBTree& rhs)
	{
		if (this == &rhs)
			return *this;

		clear();
		_alloc = rhs._alloc;
		_node = rhs._node;
		_comp = rhs._comp;
		insert(rhs.begin(), rhs.end());
		_first = _root ? _root->min() : NULL;
		_last = _root ? _root->max() : NULL;
		return *this;
	}

	allocator_type	get_allocator() const		{ return _alloc; }

	//	capacity
	
	bool	empty() const			{ return _size == 0; }
	size_type	size() const		{ return _size; }
	size_type	max_size() const	{ return _node.max_size(); }

	//	modifiers

	void	clear()
	{
		_size = 0;
		if (!_root)
			return ;
		_clearFrom(_root);
		_root = NULL;
	}

	ft::pair<iterator, bool>	insert(const_reference value)
	{
		iterator	it = _insertNode(value);

		if (!it.getPtr())
		{
			it = iterator(_findNode(value), _root);
			return ft::make_pair(it, false);
		}
		return ft::make_pair(it, true);
	}

	iterator	insert(iterator hint, const_reference value)
	{
		(void)hint;
		return _insertNode(value);
	}

	template< class InputIt >
	void	insert(InputIt first, InputIt last)
	{
		for (; first != last ; first++)
			_insertNode(*first);
	}

	void	erase(iterator pos)
	{
		_deleteNode(pos.getPtr());
	}

	void	erase(iterator first, iterator last)
	{
		for (; first != last ; first++)
			_deleteNode(first.getPtr());
	}

	size_type	erase(const_reference key)
	{
		return _deleteNode(_findNode(key));
	}

	void	swap(RBTree& other)
	{
		ft::swap(_alloc, other._alloc);
		ft::swap(_node, other._node);
		ft::swap(_comp, other._comp);
		ft::swap(_root, other._root);
		ft::swap(_first, other._first);
		ft::swap(_last, other._last);
		ft::swap(_size, other._size);
	}

	//	lookup

	size_type	count( const_reference key) const
	{
		if (findNode(key))
			return 1;
		else
			return 0;
	}

	iterator	find(const_reference key)
	{
		return iterator(_findNode(key), _root);
	}

	const_iterator	find(const_reference key) const
	{
		return const_iterator(_findNode(key), _root);
	}

	iterator	lower_bound(const_reference key);
	const_iterator	lower_bound(const_reference key) const;
	iterator	upper_bound(const_reference key);
	const_iterator	upper_bound(const_reference key) const;

	ft::pair<iterator, iterator>	equal_range(const_reference key);
	ft::pair<const_iterator, const_iterator>	equal_range(const_reference key) const;

	key_compare	key_comp() const	{ return _comp; }

	iterator		begin()			{ return iterator(_first, _root); }
	const_iterator	begin() const	{ return const_iterator(_first, _root); }
	iterator		end()			{ return iterator(_last, _root); }
	const_iterator	end() const		{ return const_iterator(_last, _root); }

	reverse_iterator		rbegin()		{ return reverse_iterator(_last, _root); }
	const_reverse_iterator	rbegin() const	{ return const_reverse_iterator(_last, _root); }
	reverse_iterator		rend()			{ return reverse_iterator(_first, _root); }
	const_reverse_iterator	rend() const	{ return const_reverse_iterator(_first, _root); }

};



}	// namespace ft

#endif
