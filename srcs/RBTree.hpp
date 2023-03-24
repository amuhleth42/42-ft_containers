#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <memory>

namespace	ft
{

template< class T >
struct	RBNode {

public:
	typedef	T		value_type;
	typedef	T&		reference;
	typedef	T*		pointer;
	typedef	RBNode*	node_ptr;
	typedef	enum {BLACK, RED}	color_type;

	value_type	content;
	color_type	color;
	node_ptr		parent;
	node_ptr		left;
	node_ptr		right;

	RBNode(const value_type& content = value_type(),
			color_type color = BLACK,
			node_ptr parent = NULL,
			node_ptr left = NULL,
			node_ptr right = NULL) :
		content(content),
		parent(parent),
		color(color),
		left(left),
		right(right)
	{}

	~RBNode() {}

	reference	operator*(void) const	{ return content; }
	pointer		operator->(void) const	{ return &content; }

	// todo ?
	
	bool	operator==(const RBNode& rhs)
	{
		return (parent == rhs.parent && left == rhs.left && right == rhs.right);
	}
	bool	operator!=(const RBNode& rhs);
	{
		return !(*this == rhs);
	}

	node_ptr	min(void)
	{
		if (left)
			return left->min();
		return this;
	}
	node_ptr	max(void)
	{
		if (right)
			return right->max();
		return this;
	}
	node_ptr	previous(void)
	{
		if (left)
			return left->max();

		node_ptr	n = this;
		node_ptr	p = n->parent;

		while (p && n == p->left)
		{
			n = p;
			p = p->parent;
		}
		return p;

	}
	node_ptr	next(void)
	{
		if (right)
			return right->min();

		node_ptr	n = this;
		node_ptr	p = n->parent;

		while (p && n == p->right)
		{
			n = p;
			p = p->parent;
		}
		return p;
	}

};



template< class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
class	RBTree
{

public:
	typedef	struct	RBNode	node_type;
	typedef	struct	RBNode*	node_ptr;

private:
	node_ptr	newNode(const_reference content);
	node_ptr	getRoot() const;
	
	void	leftRotate(node_ptr n);
	void	rightRotate(node_ptr n);

	void	insertFix(note_ptr newNode);
	void	deleteFix(node_ptr x);

	void	transplant(node_ptr x, node_ptr y);

	void	clearNode(RBNodeAllocator& alloc, node_ptr n) const;

	node_ptr	_getNode(const_reference k) const;

	iterator	insertNode(const_reference k, node_ptr hint = NULL);

	int	deleteNode(const node_ptr toDelete);

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
