#ifndef VECTOR_HPP
# define VECTOR_HPP

template <typename T, typename Alloc = allocator<T>>
class	vector {

public:


	vector(void);


	//begin()
	//end();
	//rbegin();
	//rend();
	//cbegin();
	//cend();
	//crbegin();
	//crend();
	
	size_t	size(void) const;
	size_t	max_size(void) const;
	//resize();
	//capacity();
	bool	empty(void) const;
	void	reserve(size_t newCap);
	//shrink_to_fit();

	//operator[]();
	//at();
	//front();
	//back();
	//data();

	//assign();
	//push_back();
	//pop_back();
	//insert();
	//erase();
	//swap();
	void	clear(void);
	//emplace();
	//emplace_back();

	//get_allocator();

private:


};

#endif
