//	Member Functions Prototypes

template<
	class Key,
	class T,
	class Compare = ft::less<Key>,
	class Alloc = std::allocator< ft::pair<const Key, T> > >
class map {

	//constructors
	explicit	map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

	template< class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare comp = key_compare(), const allocator_type& alloc = allocator_type());

	map(const map& x);
	
	~map();

	map&	operator=(const map& x);






};
