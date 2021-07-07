#include <map>
#include <iomanip>
#include <list>
#include "map.hpp"

#define red "\x1b[31m"
#define green "\x1b[32m"
#define yellow "\x1b[33m"
#define blue "\x1b[34m"
#define cend "\x1b[0m"

using namespace ft;

void	test_equal_element_and_insert_simple_element()
{
	std::cout << blue << "TEST EQUAL ELEMENT AND INSERT SIMPLE ELEMENT" << cend << std::endl;

	int	my_array_a[5] = {1, 1, 1, 1, 1};

	ft::map<int, int>	my_map_a;
	std::map<int, int>	std_map_a;

	for (int i = 0; i < 5; i++)
	{
		my_map_a.insert(std::pair<int, int>(my_array_a[i], my_array_a[i] * my_array_a[i]));
		std_map_a.insert(std::pair<int, int>(my_array_a[i], my_array_a[i] * my_array_a[i]));
	}

	ft::map<int, int>::iterator	my_map_ia = my_map_a.begin();
	std::map<int, int>::iterator	std_map_ia = std_map_a.begin();
	
	std::cout << "Test 1: ";
	if (my_map_a.size() != std_map_a.size())
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}
	for (; my_map_ia != my_map_a.end() || std_map_ia != std_map_a.end(); my_map_ia++, std_map_ia++)
	{
		if (my_map_ia->first != std_map_ia->first || my_map_ia->second != std_map_ia->second)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_range_constructor_and_iterators()
{
	std::cout << blue << "TEST RANGE CONSTRUCTOR AND ITERATOR" << cend << std::endl;

	std::map<int, int>	std_a;

	for (int i = 1; i < 20; i++)
		std_a.insert(std::pair<int, int>(i, i * i));

	ft::map<int, int>	my_a(std_a.begin(), std_a.end());

	ft::map<int, int>::iterator	my_ia = my_a.begin();
	std::map<int, int>::iterator	std_ia = std_a.begin();
	
	std::cout << "Test 1: ";
	if (my_a.size() != std_a.size())
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (my_ia->first != std_ia->first || my_ia->second != std_ia->second)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	ft::map<int, int>::reverse_iterator	my_ria = my_a.rbegin();
	std::map<int, int>::reverse_iterator	std_ria = std_a.rbegin();

	std::cout << "Test 2: ";
	for (; my_ria != my_a.rend() || std_ria != std_a.rend(); my_ria++, std_ria++)
	{
		if (my_ria->first != std_ria->first || my_ria->second != std_ria->second)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_capacity_and_insert_range()
{
	std::cout << blue << "TEST CAPACITY AND INSERT RANGE" << cend << std::endl;

	std::map<int, int>	std_test;
	ft::map<int, int>	my_test;

	for (int i = 1; i <= 20; i++)
	{
		std_test.insert(std::pair<int, int>(i, i * i));
		my_test.insert(std::pair<int, int>(i, i * i));
	}

	ft::map<int, int>	my_a;
	std::map<int, int>	std_a;

	std::cout << "Test 1: ";
	if (!(my_a.empty() && std_a.empty()))
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}
	std::cout << green << "OK" << cend << std::endl;

	my_a.insert(my_test.begin(), my_test.end());
	std_a.insert(std_test.begin(), std_test.end());

	ft::map<int, int>::iterator	my_ia = my_a.begin();
	std::map<int, int>::iterator	std_ia = std_a.begin();

	std::cout << "Test 2: ";
	if (my_a.size() != std_a.size())
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (my_ia->first != std_ia->first || my_ia->second != std_ia->second)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	std::cout << "Test 3: ";
	if (my_a.max_size() != std_a.max_size())
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_ellement_access()
{
	std::cout << blue << "TEST ELLEMENT_ACCESS" << cend << std::endl;

	ft::map<int, int>	my_a;
	std::map<int, int>	std_a;

	for (int i = 1; i <= 20; i++)
	{
		my_a[i] = i * i;
		std_a[i] = i * i;
	}

	ft::map<int, int>::iterator	my_ia;
	std::map<int, int>::iterator	std_ia;

	std::cout << "Test 1: ";
	for (int i = 1; i <= 25; i++)
	{
		my_ia = my_a.find(i);
		std_ia = std_a.find(i);

		if (i > 20 && my_ia != my_a.end() && std_ia != std_a.end())
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
		else if (i > 20 && my_ia == my_a.end() && std_ia == std_a.end())
			continue ;
		if (my_ia->first != std_ia->first || my_ia->second != std_ia->second)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;	
}

void	test_simple_erase()
{
	std::cout << blue << "TEST SIMPLE ERASE" << cend << std::endl;

	ft::map<int, int>	my_a;
	std::map<int, int>	std_a;

	for (int i = 1; i <= 20; i++)
	{
		my_a[i] = i * i;
		std_a[i] = i * i;
	}

	std::cout << "Test 1: ";
	for (int i = 1; i < 5; i++)
	{
		my_a.erase(i * 2);
		std_a.erase(i * 2);
	}
	if (my_a.size() != std_a.size())
	{
			std::cout << red << "False" << cend << std::endl;
			return ;
	}
	std::cout << green << "OK" << cend << std::endl;

	std::cout << "Test 2: ";

	ft::map<int, int>::iterator	my_ia;
	std::map<int, int>::iterator	std_ia;

	my_ia = my_a.begin();
	std_ia = std_a.begin();
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (my_ia->first != std_ia->first && my_ia->second != std_ia->second)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_swap()
{
	std::cout << blue << "TEST SWAP" << cend << std::endl;
	
	ft::map<int, int>	my_a;
	std::map<int, int>	std_a;

	for (int i = 0; i < 10; i += 2)
	{
		my_a[i] = i;
		std_a[i] = i;
	}

	ft::map<int, int>	my_a2;
	std::map<int, int>	std_a2;

	for (int i = 0; i <= 10; i += 3)
	{
		my_a2[i] = i;
		std_a2[i] = i;
	}

	my_a.swap(my_a2);
	std_a.swap(std_a2);

	ft::map<int, int>::reverse_iterator	my_cria = my_a.rbegin();
	std::map<int, int>::reverse_iterator	std_cria = std_a.rbegin();

	std::cout << "Test 1: ";
	for (; my_cria != my_a.rend() || std_cria != std_a.rend(); my_cria++, std_cria++)
	{
		if (my_cria->first != std_cria->first && my_cria->second != std_cria->second)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_clear_and_assign_operator()
{
	std::cout << blue << "TEST CLEAR AND ASSING OPERATOR" << cend << std::endl;

	ft::map<int, int>	my_a;
	std::map<int, int>	std_a;

	for (int i = 0; i < 1; i++)
	{
		my_a[i] = i;
		std_a[i] = i;
	}

	my_a.clear();
	std_a.clear();

	std::cout << "Test 1: ";
	if (my_a.size() != std_a.size())
		std::cout << red << "False" << cend << std::endl;
	else
		std::cout << green << "OK" << cend << std::endl;
	
	std::map<int, int>	std_test;
	ft::map<int, int>	my_test;

	for (int i = 0; i < 35; i++)
	{
		my_test[i] = i;
		std_test[i] = i;
	}

	my_a = my_test;
	std_a = std_test;

	ft::map<int, int>::iterator	my_ia = my_a.begin();
	std::map<int, int>::iterator	std_ia = std_a.begin();

	std::cout << "Test 2: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (my_ia->first != std_ia->first && my_ia->second != std_ia->second)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_find_and_const_iterators_and_count()
{
	std::cout << blue << "TEST FIND AND CONST ITERATORS AND COUNT" << cend << std::endl;

	std::map<int, int>	std_test;

	for (int i = 1; i <= 20; i++)
		std_test.insert(std::pair<int, int>(i, i * i));

	const ft::map<int, int>	my_a(std_test.begin(), std_test.end());
	const std::map<int, int>	std_a(std_test.begin(), std_test.end());

	ft::map<int, int>::const_iterator	my_ia;
	std::map<int, int>::const_iterator	std_ia;

	std::cout << "Test 1: ";
	for (int i = 1; i <= 25; i++)
	{
		my_ia = my_a.find(i);
		std_ia = std_a.find(i);

		if (i > 20 && my_ia != my_a.end() && std_ia != std_a.end())
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
		else if (i > 20 && my_ia == my_a.end() && std_ia == std_a.end())
			continue ;
		if (my_ia->first != std_ia->first || my_ia->second != std_ia->second)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	std::cout << "Test 3: ";
	if (my_a.count(2) != std_a.count(2))
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}
	std::cout << green << "OK" << cend << std::endl;

	std::cout << "Test 4: ";
	if (my_a.count(200) != std_a.count(200))
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_lower_bound_and_upper_bound_and_range_erase_and_equal_range()
{
	std::cout << blue << "TEST LOWER BOUND AND UPPER BOUND AND RANGE ERASE AND EQUAL RANGE" << cend << std::endl;

	ft::map<char, int>	my_a;
	std::map<char, int>	std_a;

	for (char c = 'a'; c != 'f'; c++)
	{
		my_a[c] = c - '0';
		std_a[c] = c - '0';
	}

	ft::map<char, int>::iterator	my_ia_low = my_a.lower_bound('b');
	std::map<char, int>::iterator	std_ia_low = std_a.lower_bound('b');

	ft::map<char, int>::iterator	my_ia_up = my_a.upper_bound('d');
	std::map<char, int>::iterator	std_ia_up = std_a.upper_bound('d');

	my_a.erase(my_ia_low, my_ia_up);
	std_a.erase(std_ia_low, std_ia_up);

	ft::map<char, int>::iterator	my_ia = my_a.begin();
	std::map<char, int>::iterator	std_ia = std_a.begin();

	std::cout << "Test 1: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (my_ia->first != std_ia->first && my_ia->second != std_ia->second)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	for (char c = 'b'; c != 'e'; c++)
	{
		my_a[c] = c - '0';
		std_a[c] = c - '0';
	}

	std::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> my_ia_e;
	std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> std_ia_e;

	my_ia_e = my_a.equal_range('b');
	std_ia_e = std_a.equal_range('b');

	
	std::cout << "Test 2: ";
	if (my_ia_e.first->first != std_ia_e.first->first || my_ia_e.second->first != std_ia_e.second->first)
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}
	std::cout << green << "OK" << cend << std::endl;
}

int	main()
{
	test_equal_element_and_insert_simple_element();
	test_range_constructor_and_iterators();
	test_capacity_and_insert_range();
	test_ellement_access();
	test_simple_erase();
	test_swap();
	test_clear_and_assign_operator();
	test_find_and_const_iterators_and_count();
	test_lower_bound_and_upper_bound_and_range_erase_and_equal_range();

	getchar();

	return (0);
}