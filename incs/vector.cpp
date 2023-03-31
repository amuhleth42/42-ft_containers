//#include "vector.hpp"
#include <iostream>
#include <vector>
#include "vector.hpp"

// Vector Tests


int	main(void)
{
	/*ft::vector<int>	v1;
	ft::vector<int>	v2(100, 42);
	ft::vector<char>	v3(100, 'c');

	std::vector<int>	lib(100, 42);

	std::cout << "size: " << v1.size() << std::endl;
	std::cout << "capacity: " << v1.capacity() << std::endl;
	std::cout << "data: " << v1.data() << std::endl;
	std::cout << std::endl;
	std::cout << "size: " << v2.size() << std::endl;
	std::cout << "capacity: " << v2.capacity() << std::endl;
	std::cout << "data: " << v2.data() << std::endl;
	std::cout << "front: " << v2.front() << std::endl;
	std::cout << std::endl;
	std::cout << "size: " << v3.size() << std::endl;
	std::cout << "capacity: " << v3.capacity() << std::endl;
	std::cout << "data: " << v3.data() << std::endl;
	std::cout << "front: " << v3.front() << std::endl;*/

	//ft::vector_iterator<ft::random_access_iterator_tag, int>	it;
	//ft::iterator<ft::random_access_iterator_tag, int>:: difference_type	diff = 12;
	
	ft::vector<int>	v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	ft::vector<int>	v2;

	v2.assign(v1.begin(), v1.end());

	std::cout << v2[0] << std::endl;
	std::cout << v2[1] << std::endl;
	std::cout << v2[2] << std::endl;


}
