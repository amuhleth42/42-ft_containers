// Functions Prototypes

// :s j'ai l'impression qu'il manque des choses dans cplusplus.com :s

template< class T, class Container = ft::vector<T> >
class stack {

	explicit	stack(const container_type& ctnr = container_type());

	bool		empty() const;
	size_type	size() const;

	value_type&			top();
	const value_type&	top() const;

	void	push(const value_type& val);
	void	pop();
};
