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

	RBNode(const value_type& content = value_type()
	~RBNode();

	reference	operator*(void) const;
	pointer		operator->(void) const;

	bool	operator==(const RBNode& rhs);
	bool	operator!=(const RBNode& rhs);
	
	node_ptr	min(void);
	node_ptr	max(void);

	node_ptr	previous(void);
	node_ptr	next(void);

};


}		//	namespace ft

#endif
