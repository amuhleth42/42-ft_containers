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
	typedef	RBNode*	link;
	typedef	enum {BLACK, RED}	color_type;

	value_type	content;
	color_type	color;
	link		parent;
	link		left;
	link		right;

	RBNode(const value_type& content = value_type(),
			color_type color = BLACK,
			link parent = NULL,
			link left = NULL,
			link right = NULL) :
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
	
	bool	operator==(const RBNode& rhs);
	bool	operator!=(const RBNode& rhs);

	RBNode*	mini(void);
	RBNode*	maxi(void);
	RBNode*	previous(void);
	RBNode*	next(void);

};



template< class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
class	RBTree
{

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




};











}	// namespace ft

#endif
