// Prototypes

template < typename T, typename Alloc = std::allocator<T> >
class vector
{
	// constructors
	explicit	vector(const allocator_type& alloc = allocator_type());
	explicit	vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());

	template <typename InputIterator>
	vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

	vector(const vector& x);

	~vector(void);

	vector& operator=(const vector& x);

	// iterators

	iterator		begin();
	const_iterator	begin() const;
	iterator		end();
	const_iterator	end() const;

	reverse_iterator		rbegin();
	const_reverse_iterator	rbegin() const;
	reverse_iterator		rend();
	const_reverse_iterator	rend() const;
}
