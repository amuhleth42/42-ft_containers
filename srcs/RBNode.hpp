#ifndef RB_NODE_HPP
# define RB_NODE_HPP

# include "RBTree.hpp"
# include <iostream>

namespace	ft
{

enum	color {BLACK, RED};

template< class T >
struct	RBNode {

public:
	typedef	T		value_type;
	typedef	T&		reference;
	typedef	T*		pointer;
	typedef	RBNode*	node_ptr;
	typedef	ft::color	color_type;

	value_type	content;
	color_type	color;
	node_ptr		p;
	node_ptr		left;
	node_ptr		right;

	RBNode(const value_type& content = value_type(),
			color_type color = BLACK,
			node_ptr p = NULL,
			node_ptr left = NULL,
			node_ptr right = NULL) :
		content(content),
		color(color),
		p(p),
		left(left),
		right(right)
	{}

	~RBNode() {}

	reference	operator*(void) const	{ return content; }
	pointer		operator->(void) const	{ return &content; }

	// todo ?

	bool	operator==(const RBNode& rhs)
	{
		return (p == rhs.p && left == rhs.left && right == rhs.right);
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
		node_ptr	p = n->p;

		while (p && n == p->left)
		{
			n = p;
			p = p->p;
		}
		return p;

	}
	node_ptr	next(void)
	{
		if (right)
			return right->min();

		node_ptr	n = this;
		node_ptr	p = n->p;

		while (p && n == p->right)
		{
			n = p;
			p = p->p;
		}
		return p;
	}

};


}		//	namespace ft

#endif
