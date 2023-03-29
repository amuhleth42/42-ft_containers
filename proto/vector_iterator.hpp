#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

template< typename T >
class	vector_iterator {

	vector_iterator();
	vector_iterator(pointer p);
	vector_iterator(const vector_iterator& src);
	
	~vector_iterator();

	vector_iterator&	operator=(const vector_iterator& rhs);

	operator	vector_iterator<const T>() const;

	pointer	getPtr() const;

	reference	operator*() const;
	pointer		operator->() const;

	vector_iterator&	operator++();
	vector_iterator		operator++(int);
	vector_iterator&	operator--();
	vector_iterator		operator--(int);

	vector_iterator	operator+(const difference_type n) const;
	vector_iterator	operator-(const difference_type n) const;
	difference_type	operator-(vector_iterator rhs const;

	bool	operator==(const vector_iterator& rhs) const;
	bool	operator!=(const vector_iterator& rhs) const;
	bool	operator<(const vector_iterator& rhs) const;
	bool	operator<=(const vector_iterator& rhs) const;
	bool	operator>(const vector_iterator& rhs) const;
	bool	operator>=(const vector_iterator& rhs) const;

	vector_iterator	operator+=(difference_type n);
	vector_iterator	operator-=(difference_type n);

};

#endif
