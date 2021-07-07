#include <list>
#include "list.hpp"

#define red "\x1b[31m"
#define green "\x1b[32m"
#define yellow "\x1b[33m"
#define blue "\x1b[34m"
#define cend "\x1b[0m"

using namespace ft;

void	test_iterator()
{
	std::cout << blue << "TEST ITERATOR" << cend << std::endl;

	ft::list<int>	my_a;
	std::list<int>	std_a;

	my_a.push_back(4);
	my_a.push_back(10);
	my_a.push_back(15);

	std_a.push_back(4);
	std_a.push_back(10);
	std_a.push_back(15);

	ft::list<int>::iterator	my_b;
	ft::list<int>::iterator	my_b2;
	std::list<int>::iterator	std_b;
	std::list<int>::iterator	std_b2;

	my_b = my_a.begin();
	my_b2 = my_a.begin();
	std_b = std_a.begin();
	std_b2 = std_a.begin();

	std::cout << "Test 1: ";
	if (my_b == my_b2 && std_b == std_b2)
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;

	std::cout << "Test 2: ";
	my_b2++;
	std_b2++;
	if (my_b2 == my_b2 && std_b2 == std_b2)
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;

	std::cout << "Test 3: ";
	if (my_b != my_b2 && std_b != std_b2)
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;

	std::cout << "Test 4: ";
	if ( *--my_b2 == *--std_b2 )
		std::cout << green << "OK" << cend  << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;


	my_b++;
	std_b++;

	std::cout << "Test 5: ";
	if ( *++my_b == *++std_b )
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;

	std::cout << "Test 6: ";
	if ( *my_b == *std_b )
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;

	std::cout << "Test 7: ";
	if (*my_b-- == *std_b--)
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;

	--my_b;
	--std_b;

	std::cout << "Test 8: ";
	if (*my_b == *std_b)
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;

	my_b++;
	my_b++;
	std_b++;
	std_b++;

	ft::list<int>::iterator	my_b3(my_b);
	std::list<int>::iterator	std_b3(std_b);

	std::cout << "Test 9: ";
	if (*my_b3 == *std_b3)
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;
}

void	test_fill_constructor()
{
	std::cout << blue << "TEST FILL CONSTRUCTOR" << cend << std::endl;

	ft::list<int>	my_a(4, 10);
	std::list<int>	std_a(4, 10);

	ft::list<int>::iterator	my_i = my_a.begin();
	std::list<int>::iterator	std_i = std_a.begin();

	std::cout << "Test 1: ";
	if (my_a.size() == std_a.size())
		std::cout << green << "OK" << cend << std::endl;
	else
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}

	std::cout << "Test 2: ";
	for (; my_i != my_a.end() || std_i != std_a.end(); my_i++, std_i++)
	{
		if (*my_i != *std_i)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_range_constructor()
{
	std::cout << blue << "TEST RANGE CONSTRUCTOR" << cend << std::endl;

	ft::list<int>	my_a(10, 3);
	std::list<int>	std_a(10, 3);

	ft::list<int>::iterator	my_beg = my_a.begin();
	ft::list<int>::iterator	my_en = my_a.end();
	std::list<int>::iterator	std_beg = std_a.begin();
	std::list<int>::iterator	std_en = std_a.end();

	ft::list<int>	my_b(my_beg, my_en);
	std::list<int>	std_b(std_beg, std_en);

	std::cout << "Test 1: ";
	if (my_b.size() == std_b.size())
		std::cout << green << "OK" << cend << std::endl;
	else
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}

	ft::list<int>::iterator	my_ib;
	std::list<int>::iterator	std_ib;

	my_ib = my_b.begin();
	std_ib = std_b.begin();

	std::cout << "Test 2: ";
	for (; my_ib != my_b.end() || std_ib != std_b.end(); my_ib++, std_ib++)
	{
		if (*my_ib != *std_ib)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_copy_constructor()
{
	std::cout << blue << "TEST COPY CONSTRUCTOR" << cend << std::endl;

	ft::list<int>	my_a;
	std::list<int>	std_a;

	my_a.push_back(1);
	my_a.push_back(2);
	my_a.push_back(3);
	my_a.push_back(4);
	my_a.push_back(5);

	std_a.push_back(1);
	std_a.push_back(2);
	std_a.push_back(3);
	std_a.push_back(4);
	std_a.push_back(5);

	ft::list<int>	my_b(my_a);
	std::list<int>	std_b(std_a);

	ft::list<int>::iterator	my_ia = my_a.begin();
	ft::list<int>::iterator	my_ib = my_b.begin();
	std::list<int>::iterator	std_ia = std_a.begin();
	std::list<int>::iterator	std_ib = std_b.begin();

	*my_ib = 5;
	*std_ib = 5;

	for (int i = 1; i < 4; i++)
	{
		std::cout << "Test " << i << ": ";
		if (*std_ib++ == *my_ib++)
			std::cout << green << "OK" << cend << std::endl;
		else
			std::cout << red << "False" << cend << std::endl;
	}

	for (int i = 4; i < 7; i++)
	{
		std::cout << "Test " << i << ": ";
		if (*std_ia++ == *my_ia++)
			std::cout << green << "OK" << cend << std::endl;
		else
			std::cout << red << "False" << cend << std::endl;
	}

	std::cout << "Test 7: ";
	if (my_b.begin() != my_a.begin() && std_a.begin() != std_b.begin())
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;
}

void	test_assign_content()
{
	std::cout << blue << "TEST ASSING CONTENT" << cend << std::endl;

	ft::list<int>	my_a;
	std::list<int>	std_a;

	my_a.push_back(1);
	my_a.push_back(2);
	my_a.push_back(3);
	my_a.push_back(4);
	my_a.push_back(5);

	std_a.push_back(1);
	std_a.push_back(2);
	std_a.push_back(3);
	std_a.push_back(4);
	std_a.push_back(5);

	ft::list<int>::iterator	my_ia;
	std::list<int>::iterator	std_ia;

	std::cout << "Test 1: ";
	if (my_a.size() == std_a.size())
		std::cout << green << "OK" << cend << std::endl;
	else
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}

	my_ia = my_a.begin();
	std_ia = std_a.begin();

	std::cout << "Test 2: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	ft::list<int>	my_b;
	std::list<int>	std_b;

	my_b.push_back(6);
	my_b.push_back(7);
	my_b.push_back(8);
	my_b.push_back(9);
	my_b.push_back(10);

	std_b.push_back(6);
	std_b.push_back(7);
	std_b.push_back(8);
	std_b.push_back(9);
	std_b.push_back(10);

	my_a = my_b;
	std_a = std_b;

	std::cout << "Test 3: ";
	if (my_a.size() == std_a.size())
		std::cout << green << "OK" << cend << std::endl;
	else
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}

	my_ia = my_a.begin();
	std_ia = std_a.begin();

	std::cout << "Test 4: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_reverse_iter()
{
	std::cout << blue << "TEST REVERSE ITERATOR" << cend << std::endl;

	ft::list<int>	my_a;
	std::list<int>	std_a;

	ft::list<int>::reverse_iterator	my_ria;
	std::list<int>::reverse_iterator	std_ria;

	my_a.push_back(1);
	my_a.push_back(2);
	my_a.push_back(3);
	my_a.push_back(4);

	std_a.push_back(1);
	std_a.push_back(2);
	std_a.push_back(3);
	std_a.push_back(4);

	my_ria = my_a.rbegin();
	std_ria = std_a.rbegin();

	std::cout << "Test 1: ";
	if (*my_ria == *std_ria)
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;

	std::cout << "Test 2: ";
	if (*++my_ria == *++std_ria)
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;

	my_ria++;
	std_ria++;

	std::cout << "Test 3: ";
	if (*--my_ria == *--std_ria)
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;

	my_ria--;
	std_ria--;

	std::cout << "Test 4: ";
	if (*my_ria == *std_ria)
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;

	my_ria = my_a.rbegin();
	std_ria = std_a.rbegin();

	std::cout << "Test 5: ";
	for (; my_ria != my_a.rend() || std_ria != std_a.rend(); my_ria++, std_ria++)
	{
		if (*my_ria != *std_ria)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_const_iterator()
{
	std::cout << blue << "TEST CONST ITERATOR" << cend << std::endl;

	const ft::list<int>	my_a(4, 10);
	const std::list<int>	std_a(4, 10);

	ft::list<int>::const_iterator	my_cia = my_a.begin();
	std::list<int>::const_iterator	std_cia = std_a.begin();
	
	std::cout << "Test 1: ";
	if (my_cia != my_a.end() && std_cia != std_a.end())
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;
	
	std::cout << "Test 2: ";
	if (*my_cia == *std_cia)
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;
}

void	test_capacity()
{
	std::cout << blue << "TEST CAPACITY" << cend << std::endl;

	ft::list<int>	my_a;
	std::list<int>	std_a;

	std::cout << "Test 1: ";
	if (my_a.empty() && std_a.empty())
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;
	
	ft::list<int>	my_b(3, 16);
	std::list<int>	std_b(3, 16);

	std::cout << "Test 2: ";
	if (!my_b.empty() && !std_b.empty())
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;

	std::cout << "Test 3: ";
	if (my_b.size() == std_b.size())
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;
	
	std::cout << "Test 4: ";
	if (my_b.max_size() == std_b.max_size())
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;
}

void	test_element_access()
{
	std::cout << blue << "TEST ELEMENT ACCESS" << cend << std::endl;

	ft::list<int>	my_a(10, 2);
	std::list<int>	std_a(10, 2);

	std::cout << "Test 1: ";
	if (my_a.max_size() == std_a.max_size())
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;

	ft::list<int>::iterator	my_ia = my_a.end();
	std::list<int>::iterator	std_ia = std_a.end();

	my_ia--;
	std_ia--;

	*my_ia = 1;
	*std_ia = 1;

	std::cout << "Test 2: ";
	if (my_a.back() == std_a.back())
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;
}

void	test_assign()
{
	std::cout << blue << "TEST ASSIGN" << cend << std::endl;

	ft::list<int>	my_a(10, 5);
	std::list<int>	std_a(10, 5);

	ft::list<int>::iterator my_ia = my_a.begin();
	std::list<int>::iterator std_ia = std_a.begin();

	std::cout << "Test 1: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	my_a.assign(5, 1);
	std_a.assign(5, 1);

	std::cout << "Test 2: ";
	if (my_a.size() == std_a.size())
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;

	my_ia = my_a.begin();
	std_ia = std_a.begin();

	std::cout << "Test 3: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_push_front()
{
	std::cout << blue << "TEST PUSH FRONT" << cend << std::endl;

	ft::list<int>	my_a(4, 2);
	std::list<int>	std_a(4, 2);

	ft::list<int>::iterator my_ia = my_a.begin();
	std::list<int>::iterator std_ia = std_a.begin();

	std::cout << "Test 1: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	my_a.push_front(1);
	my_a.push_front(2);
	my_a.push_front(3);

	std_a.push_front(1);
	std_a.push_front(2);
	std_a.push_front(3);

	std::cout << "Test 2: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_pop_front()
{
	std::cout << blue << "TEST POP FRONT" << cend << std::endl;

	ft::list<int>	my_a;
	std::list<int>	std_a;

	for (int i = 0; i < 5; i++)
	{
		my_a.push_back(i);
		std_a.push_back(i);
	}
	for (int i = 0; i < 5; i++)
	{
		my_a.push_front(i);
		std_a.push_front(i);
	}

	ft::list<int>::iterator my_ia = my_a.begin();
	std::list<int>::iterator std_ia = std_a.begin();

	std::cout << "Test 1: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	my_a.pop_front();
	my_a.pop_front();

	std_a.pop_front();
	std_a.pop_front();

	std::cout << "Test 2: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	std::cout << "Test 3: ";
	if (my_a.size() == std_a.size())
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;
}

void	test_pop_back()
{
	std::cout << blue << "TEST POP BACK" << cend << std::endl;

	ft::list<int>	my_a;
	std::list<int>	std_a;

	my_a.push_back(1);
	my_a.push_back(2);
	my_a.push_back(3);

	std_a.push_back(1);
	std_a.push_back(2);
	std_a.push_back(3);

	ft::list<int>::iterator my_ia = my_a.begin();
	std::list<int>::iterator std_ia = std_a.begin();

	std::cout << "Test 1: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	my_a.pop_back();
	my_a.pop_back();

	std_a.pop_back();
	std_a.pop_back();

	std::cout << "Test 2: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	std::cout << "Test 3: ";
	if (my_a.size() == std_a.size())
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;
}

void	test_insert_and_erase()
{
	std::cout << blue << "TEST INSERT AND ERASE" << cend << std::endl;

	ft::list<int>	my_a;
	std::list<int>	std_a;

	my_a.insert(my_a.begin(), 1);
	my_a.insert(my_a.begin(), 2);
	my_a.insert(my_a.begin(), 3);

	std_a.insert(std_a.begin(), 1);
	std_a.insert(std_a.begin(), 2);
	std_a.insert(std_a.begin(), 3);

	ft::list<int>::iterator my_ia = my_a.begin();
	std::list<int>::iterator std_ia = std_a.begin();

	std::cout << "Test 1: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	my_a.insert(my_a.begin(), 3, 10);
	std_a.insert(std_a.begin(), 3, 10);

	std::cout << "Test 2: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	ft::list<int>	my_b(5, 3);
	std::list<int>	std_b(5, 3);

	my_a.insert(my_a.begin(), my_b.begin(), my_b.end());
	std_a.insert(std_a.begin(), std_b.begin(), std_b.end());

	std::cout << "Test 3: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	my_a.erase(my_a.begin());
	std_a.erase(std_a.begin());

	std::cout << "Test 4: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	my_ia = my_a.begin();
	std_ia = std_a.begin();

	my_ia++;
	my_ia++;

	std_ia++;
	std_ia++;

	my_a.erase(my_a.begin(), my_ia);
	std_a.erase(std_a.begin(), std_ia);

	std::cout << "Test 5: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
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

	ft::list<int>	my_a(5, 10);
	ft::list<int>	my_b(10, 5);
	std::list<int>	std_a(5, 10);
	std::list<int>	std_b(10, 5);

	my_a.swap(my_b);
	std_a.swap(std_b);

	ft::list<int>::iterator	my_i = my_a.begin();
	std::list<int>::iterator	std_i = std_a.begin();

	std::cout << "Test 1: ";
	if (my_a.size() == std_a.size() && my_b.size() == std_b.size())
		std::cout << green << "OK" << cend << std::endl;
	else
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}

	std::cout << "Test 2: ";
	for (; my_i != my_a.end() || std_i != std_a.end(); my_i++, std_i++)
	{
		if (*my_i != *std_i)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	std::cout << "Test 3: ";
	my_i = my_b.begin();
	std_i = std_b.begin();
	for (; my_i != my_b.end() || std_i != std_b.end(); my_i++, std_i++)
	{
		if (*my_i != *std_i)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_resize()
{
	std::cout << blue << "TEST RESIZE" << cend << std::endl;

	ft::list<int>	my_a(5, 1);
	std::list<int>	std_a(5, 1);

	my_a.resize(10, 2);
	std_a.resize(10, 2);

	std::cout << "Test 1: ";
	if (my_a.size() == std_a.size())
		std::cout << green << "OK" << cend << std::endl;
	else
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}

	ft::list<int>::iterator	my_ia = my_a.begin();
	std::list<int>::iterator	std_ia = std_a.begin();

	std::cout << "Test 2: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	my_a.resize(5, 3);
	std_a.resize(5, 3);

	std::cout << "Test 3: ";
	if (my_a.size() == std_a.size())
		std::cout << green << "OK" << cend << std::endl;
	else
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}

	my_ia = my_a.begin();
	std_ia = std_a.begin();

	std::cout << "Test 4: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_clear()
{
	std::cout << blue << "TEST CLEAR" << cend << std::endl;

	ft::list<int>	my_a(5, 6);
	std::list<int>	std_a(5, 6);

	my_a.clear();
	std_a.clear();

	std::cout << "Test 1: ";
	if (my_a.size() == std_a.size())
		std::cout << green << "OK" << cend << std::endl;
	else
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}

	my_a.assign(10, 2);
	std_a.assign(10, 2);

	std::cout << "Test 2: ";
	if (my_a.size() == std_a.size())
		std::cout << green << "OK" << cend << std::endl;
	else
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}

	ft::list<int>::iterator	my_ia = my_a.begin();
	std::list<int>::iterator	std_ia = std_a.begin();

	std::cout << "Test 3: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_splice()
{
	std::cout << blue << "TEST SPLICE" << cend << std::endl;

	ft::list<int>	my_a;
	ft::list<int>	my_a2;

	std::list<int>	std_a;
	std::list<int>	std_a2;

	for (int i = 1; i < 5; i++)
	{
		my_a.push_back(i);
		my_a2.push_back(i * 10);
	}

	for (int i = 1; i < 5; i++)
	{
		std_a.push_back(i);
		std_a2.push_back(i * 10);
	}

	ft::list<int>::iterator	my_ia = my_a.begin();
	std::list<int>::iterator	std_ia = std_a.begin();

	my_ia++;
	std_ia++;

	my_a.splice(my_ia, my_a2);
	std_a.splice(std_ia, std_a2);

	std::cout << "Test 1: ";
	if (my_a.size() == std_a.size() && my_a2.size() == std_a2.size())
		std::cout << green << "OK" << cend << std::endl;
	else
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}

	my_ia = my_a.begin();
	std_ia = std_a.begin();
	std::cout << "Test 2: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	my_a2.push_back(5);
	my_a2.push_back(10);
	my_a2.push_back(15);

	std_a2.push_back(5);
	std_a2.push_back(10);
	std_a2.push_back(15);

	my_a.splice(my_a.begin(), my_a2, my_a2.begin());
	std_a.splice(std_a.begin(), std_a2, std_a2.begin());

	std::cout << "Test 3: ";
	if (my_a.size() == std_a.size() && my_a2.size() == std_a2.size())
		std::cout << green << "OK" << cend << std::endl;
	else
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}

	my_ia = my_a.begin();
	std_ia = std_a.begin();
	std::cout << "Test 4: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	my_a2.push_back(50);
	my_a2.push_back(100);
	my_a2.push_back(150);

	std_a2.push_back(50);
	std_a2.push_back(100);
	std_a2.push_back(150);

	my_a.splice(++my_a.begin(), my_a2, my_a2.begin(), my_a2.end());
	std_a.splice(++std_a.begin(), std_a2, std_a2.begin(), std_a2.end());

	std::cout << "Test 5: ";
	if (my_a.size() == std_a.size() && my_a2.size() == std_a2.size())
		std::cout << green << "OK" << cend << std::endl;
	else
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}

	my_ia = my_a.begin();
	std_ia = std_a.begin();
	std::cout << "Test 6: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_remove()
{
	std::cout << blue << "TEST REMOVE" << cend << std::endl;

	ft::list<int>	my_a;

	my_a.push_back(1);
	my_a.push_back(2);
	my_a.push_back(3);
	my_a.push_back(4);
	my_a.insert(my_a.end(), 4, 1);

	my_a.remove(1);

	std::list<int>	std_a;

	std_a.push_back(1);
	std_a.push_back(2);
	std_a.push_back(3);
	std_a.push_back(4);
	std_a.insert(std_a.end(), 4, 1);
	
	std_a.remove(1);

	ft::list<int>::iterator	my_ia = my_a.begin();
	std::list<int>::iterator	std_ia = std_a.begin();

	std::cout << "Test 1: ";
	if (my_a.size() == std_a.size())
		std::cout << green << "OK" << cend << std::endl;
	else
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}

	std::cout << "Test 2: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

bool	is_odd (const int& value)
{
	return (value % 2 == 1);
}

void	test_remove_if()
{
	std::cout << blue << "TEST REMOVE_IF" << cend << std::endl;

	ft::list<int>	my_a;

	my_a.push_back(1);
	my_a.push_back(2);
	my_a.push_back(3);
	my_a.push_back(4);
	my_a.insert(my_a.end(), 3, 5);

	my_a.remove_if(is_odd);

	std::list<int>	std_a;

	std_a.push_back(1);
	std_a.push_back(2);
	std_a.push_back(3);
	std_a.push_back(4);
	std_a.insert(std_a.end(), 3, 5);
	
	std_a.remove_if(is_odd);

	ft::list<int>::iterator	my_ia = my_a.begin();
	std::list<int>::iterator	std_ia = std_a.begin();

	std::cout << "Test 1: ";
	if (my_a.size() == std_a.size())
		std::cout << green << "OK" << cend << std::endl;
	else
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}

	std::cout << "Test 2: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

bool	less(double a, double b)
{
	return (a < b);
}

void	test_unique()
{
	std::cout << blue << "TEST UNIQUE" << cend << std::endl;

	double mydoubles[]= { 12.15,  2.72, 73.0,  12.77,  3.14, 12.77, 73.35, 72.25, 15.3,  72.25 };
	
	ft::list<double>	my_a(mydoubles,mydoubles+10);
	std::list<double>	std_a(mydoubles,mydoubles+10);
	
	my_a.unique();
	std_a.unique();

	ft::list<double>::iterator	my_ia = my_a.begin();
	std::list<double>::iterator	std_ia = std_a.begin();

	std::cout << "Test 1: ";
	if (my_a.size() == std_a.size())
		std::cout << green << "OK" << cend << std::endl;
	else
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}

	std::cout << "Test 2: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	my_a.unique(less);
	std_a.unique(less);
	std::cout << "Test 3: ";
	if (my_a.size() == std_a.size())
		std::cout << green << "OK" << cend << std::endl;
	else
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}

	std::cout << "Test 4: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_reverse()
{
	std::cout << blue << "TEST REVERSE" << cend << std::endl;

	ft::list<int>	my_a;
	std::list<int>	std_a;

	for (int i = 0; i < 10; i++)
	{
		my_a.push_back(i);
		std_a.push_back(i);
	}

	ft::list<int>::iterator	my_ia = my_a.begin();
	std::list<int>::iterator	std_ia = std_a.begin();

	std::cout << "Test 1: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	my_a.reverse();
	std_a.reverse();

	my_ia = my_a.begin();
	std_ia = std_a.begin();

	std::cout << "Test 2: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_sort()
{
	std::cout << blue << "TEST SORT" << cend << std::endl;

	ft::list<int>	my_a;
	std::list<int>	std_a;

	for (int i = 0; i < 10; i++)
	{
		my_a.push_back(i * 2);
		std_a.push_back(i * 2);
	}
	for (int i = 0; i < 10; i++)
	{
		my_a.push_back(i);
		std_a.push_back(i);
	}
	for (int i = 9; i > 0; i--)
	{
		my_a.push_back(i * 10);
		std_a.push_back(i * 10);
	}

	my_a.sort();
	std_a.sort();

	ft::list<int>::iterator	my_ia = my_a.begin();
	std::list<int>::iterator	std_ia = std_a.begin();

	std::cout << "Test 1: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_merge()
{
	std::cout << blue << "TEST MERGE" << cend << std::endl;

	ft::list<int>	my_a;
	std::list<int>	std_a;

	for (int i = 0; i < 10; i++)
	{
		my_a.push_back(i * 2);
		std_a.push_back(i * 2);
	}
	for (int i = 9; i > 0; i--)
	{
		my_a.push_back(i * 10);
		std_a.push_back(i * 10);
	}

	ft::list<int>	my_b;
	std::list<int>	std_b;

	for (int i = 0; i < 10; i++)
	{
		my_b.push_back(i);
		std_b.push_back(i);
	}

	my_a.sort();
	my_b.sort();
	std_a.sort();
	std_b.sort();

	my_a.merge(my_b);
	std_a.merge(std_b);

	ft::list<int>::iterator	my_ia = my_a.begin();
	std::list<int>::iterator	std_ia = std_a.begin();

	std::cout << "Test 1: ";
	for (; my_ia != my_a.end() || std_ia != std_a.end(); my_ia++, std_ia++)
	{
		if (*my_ia != *std_ia)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;
}

void	test_non_member_swap()
{
	std::cout << blue << "TEST NON MEMBER SWAP" << cend << std::endl;

	ft::list<int>	my_a(5, 10);
	ft::list<int>	my_b(10, 5);
	std::list<int>	std_a(5, 10);
	std::list<int>	std_b(10, 5);

	ft::swap(my_a, my_b);
	std::swap(std_a, std_b);

	ft::list<int>::iterator	my_i = my_a.begin();
	std::list<int>::iterator	std_i = std_a.begin();

	std::cout << "Test 1: ";
	if (my_a.size() == std_a.size() && my_b.size() == std_b.size())
		std::cout << green << "OK" << cend << std::endl;
	else
	{
		std::cout << red << "False" << cend << std::endl;
		return ;
	}

	std::cout << "Test 2: ";
	for (; my_i != my_a.end() || std_i != std_a.end(); my_i++, std_i++)
	{
		if (*my_i != *std_i)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;

	std::cout << "Test 3: ";
	my_i = my_b.begin();
	std_i = std_b.begin();
	for (; my_i != my_b.end() || std_i != std_b.end(); my_i++, std_i++)
	{
		if (*my_i != *std_i)
		{
			std::cout << red << "False" << cend << std::endl;
			return ;
		}
	}
	std::cout << green << "OK" << cend << std::endl;	
}

void	test_relational_operators()
{
	std::cout << blue << "TEST RELATIONAL OPERATORS" << cend << std::endl;

	ft::list<int>	my_a;
	ft::list<int>	my_b;
	std::list<int>	std_a;
	std::list<int>	std_b;

	for (int i = 0; i < 10; i++)
	{
		my_a.push_back(i);
		my_a.push_back(i * 3);
		my_b.push_back(i);
		my_b.push_back(i * 3);

		std_a.push_back(i);
		std_a.push_back(i * 3);
		std_b.push_back(i);
		std_b.push_back(i * 3);
	}

	std::cout << "TEST 1: ";
	if (my_a == my_b && std_a == std_b)
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;
	
	my_b.assign(5, 1);
	std_b.assign(5, 1);

	std::cout << "TEST 2: ";
	if (my_a != my_b && std_a != std_b)
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;
	
	std::cout << "TEST 3: ";
	if (my_b > my_a && std_b > std_a)
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;
	
	std::cout << "TEST 4: ";
	if (my_b >= my_a && std_b >= std_a)
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;

	std::cout << "TEST 5: ";
	if (my_a < my_b && std_a < std_b)
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;

	std::cout << "TEST 6: ";
	if (my_a <= my_b && std_a <= std_b)
		std::cout << green << "OK" << cend << std::endl;
	else
		std::cout << red << "False" << cend << std::endl;
}

int		main(void)
{
	test_iterator();
	test_fill_constructor();
	test_range_constructor();
	test_copy_constructor();
	test_assign_content();
	test_reverse_iter();
	test_const_iterator();
	test_capacity();
	test_element_access();
	test_assign();
	test_push_front();
	test_pop_front();
	test_pop_back();
	test_insert_and_erase();
	test_swap();	
	test_resize();
	test_clear();
	test_splice();
	test_remove();
	test_remove_if();
	test_unique();
	test_reverse();
	test_sort();
	test_merge();
	test_relational_operators();
	test_non_member_swap();

	getchar();

	return (0);
}
