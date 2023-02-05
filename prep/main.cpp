#include "Vector.hpp"

template <typename T>
void	printVector(Vector<T> const & v)
{
	for (size_t i = 0 ; i < v.size() ; i++)
		std::cout << v[i] << std::endl;
}

int	main(void)
{
	Vector<std::string>	v;

	v.push_back("amuhleth");
	v.push_back("c++");
	v.push_back("vector");
	v.push_back("amuhleth");
	v.push_back("c++");
	v.push_back("vector");

	printVector(v);

}
