#ifndef ITERATORS_HPP
# define ITERATORS_HPP

namespace ft
{

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template< class Iter >
class iterator_traits {

public:
	typedef typename Iter::difference_type		difference_type;
	typedef typename Iter::value_type 			value_type;
	typedef typename Iter::pointer				pointer;
	typedef typename Iter::reference			reference;
	typedef typename Iter::iterator_category	iterator_category;
};

template< typename T >
class RandomAccessIterator {

public:
	typedef ptrdiff_t	difference_type;
	typedef T			value_type;
	typedef T*			pointer;
	typedef T&			reference;

	typedef RandomAccessIterator<const T>	const_iterator;
	typedef	ft::random_access_iterator_tag	iterator_category;

public:
	
	RandomAccessIterator(void) : _p(NULL) {}
	RandomAccessIterator(pointer p) : _p(p) {}
	RandomAccessIterator(const RandomAccessIterator& src) { *this = src; }
	~RandomAccessIterator(void) {}

	RandomAccessIterator&	operator=(RandomAccessIterator const & rhs)
	{
		_p = rhs._p;
		return (*this);
	}

	// truc tres chelou, je comprends pas
	operator RandomAccessIterator<const T>(void) const
	{
		return (RandomAccessIterator<const T>(_p);
	}

	pointer base(void) const { return (_p); }

	reference	operator*(void) const { return *_p; }
	pointer		operator->(void) const { return _p }

	RandomAccessIterator&	operator++(void)
	{
		++_p;
		return (*this);
	}
	RandomAccessIterator	operator++(int)
	{
		return (RandomAccessIterator(_p++);
	}

	RandomAccessIterator&	operator--(void)
	{
		--_p;
		return (*this);
	}
	RandomAccessIterator	operator--(int)
	{
		return (RandomAccessIterator(_p--);
	}

	RandomAccessIterator	operator+(difference_type const n) const
	{
		return (RandomAccessIterator(_p + n);
	}

	RandomAccessIterator	operator-(difference_type const n) const
	{
		return (RandomAccessIterator(_p - n);
	}

	difference_type		operator-(RandomAccessIterator rhs) const
	{
		return (_p - rhs._p);
	}

	bool	operator==(RandomAccessIterator const & rhs) const { return (_p == rhs._p); }
	bool	operator!=(RandomAccessIterator const & rhs) const { return (_p != rhs._p); }
	bool	operator<(RandomAccessIterator const & rhs) const { return (_p < rhs._p); }
	bool	operator>(RandomAccessIterator const & rhs) const { return (_p > rhs._p); }
	bool	operator<=(RandomAccessIterator const & rhs) const { return (_p <= rhs._p); }
	bool	operator>=(RandomAccessIterator const & rhs) const { return (_p >= rhs._p); }




private:
	pointer	_p;



}







}

#endif
