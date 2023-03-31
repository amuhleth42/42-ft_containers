#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "RBNode.hpp"
# include "iterator.hpp"

namespace	ft
{

template< class Node, class T >
class	map_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {

public:
	map_iterator();
	map_iterator(node_ptr p, node_ptr root);
	map_iterator(const map_iterator& src);
	~map_iterator();

	map_iterator&	operator=(const map_iterator& rhs);
	
	operator	map_iterator<Node, const T>() const;

	node_ptr	getNodePtr() const;
	pointer		getPtr() const;

	reference	operator*() const;
	pointer		operator->() const;

	map_iterator&	operator++();

	map_iterator	operator++(int);

	map_iterator&	operator--();

	map_iterator	operator--(int);

	bool	operator==(const map_iterator& rhs) const;
	bool	operator!=(const map_iterator& rhs) const;

};

template< class Node, class T1, class T2 >
bool	operator==(const map_iterator<Node, T1>& lhs, const map_iterator<Node, T2>& rhs);

template< class Node, class T1, class T2 >
bool	operator!=(const map_iterator<Node, T1>& lhs, const map_iterator<Node, T2>& rhs);

}	// namespace ft

#endif
