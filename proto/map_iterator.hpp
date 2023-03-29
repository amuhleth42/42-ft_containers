//	proto


template< class Node, class T >
class	map_iterator {

	map_iterator();
	map_iterator(node_ptr p, node_ptr root);
	map_iterator(const map_iterator& src);
	~map_iterator();

	map_iterator&	operator=(const map_iterator& rhs);

	node_ptr	getPtr() const;

	reference	operator*() const;
	pointer		operator->() const;

	map_iterator&	operator++();
	map_iterator	operator++(int);
	map_iterator&	operator--();
	map_iterator	operator--(int);

	bool	operator==(const map_iterator& rhs) const;
	bool	operator!=(const map_iterator& rhs) const;

};
