#ifndef SET_HPP
# define SET_HPP

# include <memory>
# include "RBTree.hpp"
# include "utility.hpp"
# include "type_traits.hpp"
# include "functional.hpp"
# include "iterator.hpp"

namespace	ft
{

template<
	class Key,
	class Compare = ft::less<Key>,
	class Alloc = std::allocator<Key> >
class	set : public ft::RBTree<Key, Compare, Alloc> {

public:
	typedef	Compare	key_compare;
	typedef	Key		key_type;

	typedef typename ft::RBTree<Key, Compare, Alloc>::const_iterator iterator;
	typedef typename ft::RBTree<Key, Compare, Alloc>::const_reverse_iterator reverse_iterator;

private:
	typedef	ft::RBTree<Key, Compare, Alloc>	tree;

public:

	set() : tree() {}

	explicit set(const key_compare& comp, const Alloc& alloc = Alloc()) :
		tree(key_compare(comp), alloc)
	{}

	template< class InputIt >
	set(InputIt first, InputIt last,
		const key_compare& comp = key_compare(),
		const Alloc& alloc = Alloc()) :
		tree(first, last, comp, alloc)
	{}

	set(const set& src) : tree(src) {}

	~set(void) {}

	key_compare	value_comp() const		{ return this->key_comp(); }

};

template< class K, class C, class A >
bool	operator==(const set<K, C, A>& lhs, const set<K, C, A>& rhs)
{
	return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template< class K, class C, class A >
bool	operator!=(const set<K, C, A>& lhs, const set<K, C, A>& rhs)
{
	return !(lhs == rhs);
}

template< class K, class C, class A >
bool	operator<(const set<K, C, A>& lhs, const set<K, C, A>& rhs)
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template< class K, class C, class A >
bool	operator<=(const set<K, C, A>& lhs, const set<K, C, A>& rhs)
{
	return !(rhs < lhs);
}

template< class K, class C, class A >
bool	operator>(const set<K, C, A>& lhs, const set<K, C, A>& rhs)
{
	return rhs < lhs;
}

template< class K, class C, class A >
bool	operator>=(const set<K, C, A>& lhs, const set<K, C, A>& rhs)
{
	return !(lhs < rhs);
}

template< class K, class C, class A >
void	swap(set<K, C, A>& lhs, set<K, C, A>& rhs)
{
	lhs.swap(rhs);
}







}	//	namespace ft

#endif
