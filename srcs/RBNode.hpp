#ifndef RB_NODE_HPP
# define RB_NODE_HPP

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
	bool	operator!=(const RBNode& rhs)
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


}		//	namespace ft

#endif
