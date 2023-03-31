#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "set.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <list>

template< typename T >
void	printVector(ft::vector<T> const& v)
{
	std::cout << "size: " << v.size() << std::endl;
	std::cout << "max_size: " << v.max_size() << std::endl;
	for (typename ft::vector<T>::const_iterator	it = v.begin() ; it != v.end() ; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template< class K, class V >
void	printMap(ft::map<K, V> const& m)
{
	std::cout << "size: " << m.size() << std::endl;
	std::cout << "max_size: " << m.max_size() << std::endl;
	for (typename ft::map<K, V>::const_iterator	it = m.begin() ; it != m.end() ; it++)
		std::cout << '(' << it->first << ',' << it->second << ')' << " ";
	std::cout << std::endl;
}

template< typename T, class Cont>
void	printStack(ft::stack<T, Cont> const& s)
{
	std::cout << "size: " << s.size() << std::endl;
	if (s.size())		// to avoid undefined behavior
		std::cout << "top: " << s.top() << std::endl;
}

template< typename K >
void	printSet(ft::set<K> const& s)
{
	std::cout << "size: " << s.size() << std::endl;
	std::cout << "max_size: " << s.max_size() << std::endl;
	for (typename ft::set<K>::const_iterator	it = s.begin() ; it != s.end() ; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int	main(void)
{
	{
		std::cout << "-----------  VECTOR -----------" << std::endl;
		ft::vector<int>	v1;
		printVector(v1);
		ft::vector<int>	v2(20, 42);
		printVector(v2);

		v2.push_back(555);

		ft::vector<int>	v3(v2);
		printVector(v3);

		v3.pop_back();

		ft::vector<int>	v4(v3.begin(), v3.end());
		printVector(v4);

		v3.insert((v3.begin() + 2), 6, 888);
		v3.insert((v3.begin() + 1), 777);

		v3.erase(v3.begin());
		
		printVector(v3);

		ft::vector<int>	v5(14, 999);

		v3.assign(v5.begin(), v5.end());
		printVector(v3);

		std::cout << "swap test" << std::endl;
		printVector(v1);
		printVector(v5);
		swap(v1, v5);
		printVector(v1);
		printVector(v5);

	}

	{
		std::cout << "-----------  MAP  -----------" << std::endl;
		ft::map<int, int>	m1;
		printMap(m1);

		m1.insert(ft::make_pair(2, 4));
		m1.insert(ft::make_pair(3, 9));
		
		printMap(m1);
		
		m1.insert(ft::make_pair(3, 10));
		
		printMap(m1);

		ft::map<int, int>	m2(m1);
		printMap(m2);

		ft::map<int, int>	m3;

		m3.insert(m2.begin(), m2.end());
		printMap(m3);

		std::cout << "m2 == m3: " << (m2 == m3) << std::endl;

		ft::map<int, int>::iterator	it = m3.lower_bound(2);
		std::cout << "lb: " << it->second << std::endl;
		it = m3.upper_bound(2);
		std::cout << "ub: " << it->second << std::endl;
		m3.erase(2);
		printMap(m3);
		m3.clear();
		printMap(m3);

	}

	{
		std::cout << "-----------  STACK  -----------" << std::endl;

		ft::stack<int>	s1;
		printStack(s1);

		std::cout << "empty? " << s1.empty() << std::endl;

		s1.push(1);
		s1.push(14);
		s1.push(12);
		s1.push(42);
		
		printStack(s1);
		std::cout << "empty? " << s1.empty() << std::endl;
		
		s1.pop();
		printStack(s1);

		std::cout << "----------------" << std::endl;
		
		ft::stack<int, std::list<int> >	s2;
		printStack(s2);

		std::cout << "empty? " << s2.empty() << std::endl;

		s2.push(1);
		s2.push(14);
		s2.push(12);
		s2.push(42);
		
		printStack(s2);
		std::cout << "empty? " << s2.empty() << std::endl;
		
		s2.pop();
		printStack(s2);

	}
	
	{
		std::cout << "-----------  SET  -----------" << std::endl;
		ft::set<int>	s1;
		printSet(s1);

		s1.insert(2);
		s1.insert(3);
		
		printSet(s1);

		ft::set<int>	s2(s1);
		printSet(s2);

		ft::set<int>	s3;

		s3.insert(s2.begin(), s2.end());
		printSet(s3);

		std::cout << "s2 != s3: " << (s2 != s3) << std::endl;

		ft::set<int>::iterator	it = s3.lower_bound(2);
		std::cout << "lb: " << *it << std::endl;
		it = s3.upper_bound(2);
		std::cout << "ub: " << *it << std::endl;
		s3.erase(2);
		printSet(s3);
		s3.clear();
		printSet(s3);

	}
}
