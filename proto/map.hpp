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

	// iterators

	iterator		begin();
	const_iterator	begin() const
	iterator		end();
	const_iterator	end() const

	reverse_iterator		rbegin();
	const_reverse_iterator	rbegin() const;
	reverse_iterator		rend();
	const_reverse_iterator	rend() const;

	//	capacity

	bool		empty() const;
	size_type	size() const;
	size_type	max_size() const;

	// element access

	mapped_type&	operator[](const key_type& k);

	mapped_type*		at(const key_type& k);
	const mapped_type&	at(const key_type& k) const;

	//	modifiers

	pair<iterator, bool>	insert(const value_type& val);
	iterator	insert(iterator position, const value_type& val);

	template< class InputIterator >
	void	insert(InputIterator first, InputIterator last);

	void		erase(iterator position);
	size_type	erase(const key_type& k);
	void		erase(iterator fist, iterator last);

	void	swap(map& x);
	void	clear();

	//	observers

	key_compare		key_comp() const;
	value_compare	value_comp() const;

	//	operations

	iterator		find(const key_type& k);
	const_iterator	find(const key_type& k) const;

	size_type	count(const key_type* k) const;

	iterator		lower_bound(const key_type& k);
	const_iterator	lower_bound(const key_type& k) const;

	iterator		upper_bound(const key_type& k);
	const_iterator	upper_bound(const key_type& k) const;

	pair<iterator, iterator>				equal_range(const key_type& k);
	pair<const_iterator, const_iterator>	equal_range(const key_type& k);

	//	allocator getter

	allocator_type	get_allocator() const;

};
