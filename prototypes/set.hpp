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

private:
	typedef	ft::RBTree<Key, Compare, Alloc>	tree;

public:

	set();

	explicit set(const key_compare& comp, const Alloc& alloc = Alloc());

	template< class InputIt >
	set(InputIt first, InputIt last,
		const key_compare& comp = key_compare(),
		const Alloc& alloc = Alloc())

	set(const set& src);

	~set(void);

	key_compare	value_comp() const;

};

template< class K, class C, class A >
bool	operator==(const set<K, C, A>& lhs, const set<K, C, A>& rhs);

template< class K, class C, class A >
bool	operator!=(const set<K, C, A>& lhs, const set<K, C, A>& rhs);

template< class K, class C, class A >
bool	operator<(const set<K, C, A>& lhs, const set<K, C, A>& rhs);

template< class K, class C, class A >
bool	operator<=(const set<K, C, A>& lhs, const set<K, C, A>& rhs);

template< class K, class C, class A >
bool	operator>(const set<K, C, A>& lhs, const set<K, C, A>& rhs);

template< class K, class C, class A >
bool	operator>=(const set<K, C, A>& lhs, const set<K, C, A>& rhs);

template< class K, class C, class A >
void	swap(set<K, C, A>& lhs, set<K, C, A>& rhs);

}	//	namespace ft

#endif
