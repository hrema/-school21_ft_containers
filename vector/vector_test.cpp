#include <vector>
#include <iostream>
#include "vector.hpp"

#define red "\x1b[31m"
#define green "\x1b[32m"
#define yellow "\x1b[33m"
#define blue "\x1b[34m"
#define cend "\x1b[0m"

using namespace ft;

void	test_constructors_and_capacity_and_assign_operator()
{
	std::cout << blue << "TEST CONSTRUCTORS AND CAPACITY AND ASSIGN OPERATOR" << cend << std::endl;

	ft::vector<int>	my_a;
	std::vector<int>	std_a;

	ft::vector<int>	my_a2(5, 15);
	std::vector<int>	std_a2(5, 15);

	std::cout << "Test 1: ";
	if (my_a.empty() && std_a.empty())
		std::cout << green << "OK" << cend << std::endl;
	else
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}

	std::cout << "Test 2: ";
	if (my_a2.size() != std_a2.size())
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}
	std::cout << green << "OK" << cend << std::endl;

	my_a = my_a2;
	std_a = std_a2;

	std::cout << "Test 3: ";
	if (my_a != my_a2 && std_a != std_a2)
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_assign_and_iterators_and_element_access()
{
	std::cout << blue << "TEST ASSIGN AND ITERATORS AND ELEMENT ACCESS" << cend << std::endl;
	ft::vector<int>	my_a;
	std::vector<int>	std_a;

	my_a.assign(10, 5);
	std_a.assign(10, 5);

	ft::vector<int>::iterator	my_ia = my_a.begin();
	std::vector<int>::iterator	std_ia = std_a.begin();

	std::cout << "Test 1: ";
	for (; my_ia != my_a.end() && std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	ft::vector<int>	my_a2;
	std::vector<int>	std_a2;

	my_a2.assign(my_a.begin(), my_a.end());
	std_a2.assign(std_a.begin(), std_a.end());

	std::cout << "Test 2: ";
	if (my_a2.size() != std_a2.size())
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}
	std::cout << green << "OK" << cend << std::endl;

	std::cout << "Test 3: ";
	for (size_t i = 0; i < std_a2.size(); i++)
	{
		if (my_a2[i] != std_a2[i])
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	std::cout << "Test 4: ";
	if (my_a2.front() == std_a2.front() && my_a.back() == std_a.back())
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;
}

void	test_constructors_and_insert_and_reverse_iterator_and_resize()
{
	std::cout << blue << "TEST CONSTRUCTORS AND INSERT AND REVERSE ITERATOR AND RESIZE" << cend << std::endl;

	ft::vector<int>	my_a;
	std::vector<int>	std_a;

	for (int i = 0; i < 5; i++)
	{
		my_a.insert(my_a.begin(), i);
		std_a.insert(std_a.begin(), i);
	}
	my_a.insert(my_a.begin(), 3, 2);
	std_a.insert(std_a.begin(), 3, 2);

	my_a.insert(my_a.end(), my_a.begin(), my_a.end());
	std_a.insert(std_a.end(), std_a.begin(), std_a.end());

	std::cout << "Test 1: ";
	if (my_a.size() != std_a.size())
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}
	std::cout << green << "OK" << cend << std::endl;

	std::cout << "Test 2: ";
	for (size_t i = 0; i < std_a.size(); i++)
	{
		if (my_a[i] != std_a[i])
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	ft::vector<int>	my_a2(my_a.begin(), my_a.end());
	std::vector<int>	std_a2(std_a.begin(), std_a.end());

	ft::vector<int>::reverse_iterator	my_ria = my_a2.rbegin();
	std::vector<int>::reverse_iterator	std_ria = std_a2.rbegin();

	std::cout << "Test 3: ";
	for (; my_ria != my_a2.rend() && std_ria != std_a2.rend(); my_ria++, std_ria++)
	{
		if (*my_ria != *std_ria)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	my_a2.resize(20, 15);
	std_a2.resize(20, 15);

	std::cout << "Test 4: ";
	if (my_a2.size() != std_a2.size())
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}
	std::cout << green << "OK" << cend << std::endl;

	std::cout << "Test 5: ";
	for (size_t i = 0; i < std_a2.size(); i++)
	{
		if (my_a2[i] != std_a2[i])
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}	

void	test_erase_and_swap()
{
	std::cout << blue << "TEST ERASE AND SWAP" << cend << std::endl;

	ft::vector<int>	my_a;
	std::vector<int>	std_a;

	for (size_t i = 0; i < 40; i++)
	{
		my_a.insert(my_a.begin(), i);
		std_a.insert(std_a.begin(), i);
	}

	for (size_t i = 0; i < 15; i++)
	{
		my_a.erase(my_a.begin());
		std_a.erase(std_a.begin());
	}

	std::cout << "Test 1: ";
	if (my_a.size() != std_a.size())
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}
	std::cout << green << "OK" << cend << std::endl;

	std::cout << "Test 2: ";
	for (size_t i = 0; i < std_a.size(); i++)
	{
		if (my_a[i] != std_a[i])
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	ft::vector<int>	my_a2(10, 5);
	std::vector<int>	std_a2(10, 5);

	my_a.swap(my_a2);
	std_a.swap(std_a2);

	std::cout << "Test 3: ";
	if (my_a.size() != std_a.size())
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}
	std::cout << green << "OK" << cend << std::endl;

	std::cout << "Test 4: ";
	for (size_t i = 0; i < std_a.size(); i++)
	{
		if (my_a[i] != std_a[i])
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	my_a.erase(my_a.begin(), my_a.end());
	std_a.erase(std_a.begin(), std_a.end());

	std::cout << "Test 5: ";
	if (my_a.empty() && std_a.empty())
		std::cout << green << "OK" << cend << std::endl;
	else
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}	
}


int	main()
{
	test_constructors_and_capacity_and_assign_operator();
	test_assign_and_iterators_and_element_access();
	test_constructors_and_insert_and_reverse_iterator_and_resize();
	test_erase_and_swap();

	getchar();
	return (0);
}
