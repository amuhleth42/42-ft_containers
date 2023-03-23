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



};



template< class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
class	RBTree
{




};











}	// namespace ft

#endif
