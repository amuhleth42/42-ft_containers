#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "RBNode.hpp"
# include "iterator.hpp"

namespace	ft
{

template< class Node, class T >
class	map_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {

public:
	typedef	ft::iterator<ft::bidirectional_iterator_tag, T>	parent;

	typedef	typename parent::difference_type		difference_type;
	typedef	typename parent::value_type			value_type;
	typedef	typename parent::pointer				pointer;
	typedef	typename parent::reference			reference;
	typedef	typename parent::iterator_category	iterator_category;

	typedef	Node*			node_ptr;
	typedef map_iterator<Node, const T>		const_iterator;

private:
	node_ptr	_p;
	node_ptr	_root;

public:
	map_iterator() :							_p(NULL), _root(NULL)	{}
	map_iterator(node_ptr p, node_ptr root) :	_p(p), _root(root)		{}
	map_iterator(const map_iterator& src)								{ *this = src; }
	~map_iterator() 													{}

	map_iterator&	operator=(const map_iterator& rhs)
	{
		_p = rhs._p;
		_root = rhs._root;
		return *this;
	}
	
	operator	map_iterator<Node, const T>() const
	{
		return map_iterator<Node, const T>(_p, _root);
	}


	node_ptr	getPtr() const			{ return _p; }

	reference	operator*() const		{ return _p->content; }
	pointer		operator->() const		{ return &(_p->content); }

	map_iterator&	operator++()
	{
		if (_p)
			_p = _p->next();
		else
			_p = _root->min();
		return *this;
	}

	map_iterator	operator++(int)
	{
		map_iterator	tmp(_p, _root);
		if (_p)
			_p = _p->next();
		else
			_p = _root->min();
		return tmp;
	}

	map_iterator&	operator--()
	{
		if (_p)
			_p = _p->previous();
		else
			_p = _root->max();
		return *this;
	}

	map_iterator	operator--(int)
	{
		map_iterator	tmp(_p, _root);
		if (_p)
			_p = _p->previous();
		else
			_p = _root->max();
		return tmp;
	}

	bool	operator==(const map_iterator& rhs) const		{ return _p == rhs._p; }
	bool	operator!=(const map_iterator& rhs) const		{ return _p != rhs._p; }

};

}	// namespace ft

#endif
