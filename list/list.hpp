#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include <iostream>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > class list;
}

# include "list_iterator.hpp"
# include "../reverse_iterator.hpp"

namespace ft
{
	template < class T, class Alloc > class list
	{
	public:
	// Member types
		typedef	T value_type;
		typedef	Alloc allocator_type;
		typedef	value_type& reference;
		typedef	const value_type& const_reference;
		typedef	value_type* pointer;
		typedef const value_type* const_pointer;
		typedef	ft::list_iterator<T> iterator;
		typedef ft::list_const_iterator<T> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef	size_t	size_type;

	private:
		size_type		_size;
		list_node<T>		*_tail;
		allocator_type	_my_alloc;

		void	_delete_this(bool delete_tail = true)
		{
			list_node<T>	*tmp;
			list_node<T>	*next;

			if (this->_size == 0)
				return ;
			tmp = this->_tail->next;

			while (tmp != this->_tail)
			{
				next = tmp->next;
				tmp->next = NULL;
				tmp->prev = NULL;
				delete tmp;
				tmp = next;
				this->_tail->data--;
				this->_size--;
			}
			this->_reset_tail();
			if (delete_tail)
			{
				this->_tail->next = NULL;
				this->_tail->prev = NULL;
			}
		}

		void	_reset_tail()
		{
			this->_tail->data = 0;
			this->_tail->prev = this->_tail;
			this->_tail->next = this->_tail;
			this->_size = 0;
		}

		void	_link_nodes(list_node<T> *pos, list_node<T> *f, list_node<T> *l)
		{
			pos->prev->next = f;
			f->prev = pos->prev;
			pos->prev = l;
			l->next = pos;
		}

		void	_unlink_nodes(list_node<T> *f, list_node<T> *l)
		{
			f->prev->next = l->next;
			l->next->prev = f->prev;
		}

		void	_split_list(list_node<T> *src, list_node<T> **fRef, list_node<T> **bRef)
		{
			list_node<T>	*fast;
			list_node<T>	*slow;

			slow = src;
			fast = src->next;

			while (fast != NULL)
			{
				fast = fast->next;
				if (fast != NULL)
				{
					slow = slow->next;
					fast = fast->next;
				}
			}
			*fRef = src;
			*bRef = slow->next;
			slow->next = NULL;
		}

		template <class Compare>
		list_node<T>	*_merge_sorted_lists(list_node<T> *head1, list_node<T> *head2, Compare comp)
		{
			if (head1 == NULL)
				return head2;
			if (head2 == NULL)
				return head1;
			if (comp(head1->data, head2->data))
			{
				head1->next = _merge_sorted_lists(head1->next, head2, comp);
				head1->next->prev = head1;
				head1->prev = NULL;
				return head1;
			}
			else
			{
				head2->next = _merge_sorted_lists(head1, head2->next, comp);
				head2->next->prev = head2;
				head2->prev = NULL;
				return head2;
			}
		}

		template <class Compare>
		void	_merge_sort(list_node<T> **head, Compare comp)
		{
			list_node<T> 	*p = *head;
			list_node<T>	*a = NULL;
			list_node<T>	*b = NULL;

			if (p == NULL || p->next == NULL)
				return ;
			
			this->_split_list(p, &a, &b);
			this->_merge_sort(&a, comp);
			this->_merge_sort(&b, comp);
			*head = this->_merge_sorted_lists(a, b, comp);
		}

	public:
	// Constructors:
		// Default:
		explicit list(const allocator_type& alloc = allocator_type())
		{
			_my_alloc = alloc;
			this->_tail = new list_node<T>;
			this->_reset_tail();
		}
		
		// Fill
		explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			this->_my_alloc = alloc;
			this->_tail = new list_node<T>;
			this->_reset_tail();
			for (; n > 0; n--)
				this->push_back(val);
		}
		
		// Range
		template <class InputIterator>
		list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename std::iterator_traits<InputIterator>::iterator_category* = NULL)
		{
			this->_my_alloc = alloc;
			this->_tail = new list_node<T>;
			this->_reset_tail();
			for (; first != last; first++)
				this->push_back(*first);
		}
		
		// Copy
		list(const list& x)
		{
			this->_tail = new list_node<T>;
			this->_size = 0;
			if (this != &x)
				*this = x;
		}

	//  Destructor
		~list()
		{
			this->_delete_this();
			delete this->_tail;
		}

	// Assign content
		list& operator=(const list& x)
		{
			this->_delete_this();

			this->_my_alloc = x._my_alloc;
			this->_reset_tail();
			for (const_iterator i = x.begin(); i != x.end(); i++)
				this->push_back(*i);
			return (*this);
		}

	// Member function: Iterators
		iterator begin()
		{
			return (iterator(this->_tail->next));
		}

		iterator end()
		{
			return (iterator(this->_tail));
		}

		const_iterator begin() const
		{
			return (const_iterator(this->_tail->next));
		}

		const_iterator end() const
		{
			return (const_iterator(this->_tail));
		}

	    reverse_iterator rbegin()
		{
			return (reverse_iterator(this->_tail));
		}
		
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(this->_tail));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(this->_tail->next));
		}

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(this->_tail->next));
		}

	// Member function: Capacity
		bool empty() const
		{
			return (this->_size == 0);
		}

		size_type size() const
		{
			return (this->_size);
		}

		size_type max_size() const
		{
			return (std::numeric_limits<size_t>::max() / sizeof(list_node<T>));
		}

	// Member function: Element access
		reference front()
		{
			return (this->_tail->next->data);
		}

		const_reference front() const
		{
			return (this->_tail->next->data);
		}

		reference back()
		{
			return (this->_tail->prev->data);
		}

		const_reference back() const
		{
			return (this->_tail->prev->data);
		}

	// Member function: Modifiers
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last, typename std::iterator_traits<InputIterator>::iterator_category* = NULL)
		{
			this->_delete_this(false);
			for (; first != last; first++)
				this->push_back(*first);
		}
		
		void assign(size_type n, const value_type& val)
		{
			this->_delete_this(false);
			for (; n > 0; n--)
				this->push_back(val);
		}

		void push_front (const value_type& val)
		{
			list_node<T>	*new_el = new list_node<T>;
			new_el->data = val;
			_link_nodes(this->_tail->next, new_el, new_el);
			this->_tail->data++;
			this->_size++;
		}

		void pop_front()
		{
			list_node<T>	*tmp = this->_tail->next;

			this->_unlink_nodes(tmp, tmp);
			this->_tail->data--;
			this->_size--;
			delete tmp;
			tmp->next = NULL;
			tmp->prev = NULL;
		}

		void push_back(const value_type& val)
		{
			list_node<T> *new_el = new list_node<T>;
			new_el->data = val;
			_link_nodes(this->_tail, new_el, new_el);
			this->_size++;
			this->_tail->data++;
		}

		void pop_back()
		{
			list_node<T>	*tmp = this->_tail->prev;

			this->_unlink_nodes(tmp, tmp);
			tmp->prev = NULL;
			tmp->next = NULL;
			delete tmp;
			this->_tail->data--;
			this->_size--;
		}

		iterator insert (iterator position, const value_type& val)
		{
			list_node<T>	*new_el = new list_node<T>;
			new_el->data = val;
			this->_link_nodes(position._p_data, new_el, new_el);
			this->_tail->data++;
			this->_size++;
			return position;
		}
		
		void insert (iterator position, size_type n, const value_type& val)
		{
			for (; n > 0; n--)
			{
				list_node<T>	*new_el = new list_node<T>;
				new_el->data = val;
				this->_link_nodes(position._p_data, new_el, new_el);
				this->_tail->data++;
				this->_size++;
			}
		}
		
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, typename std::iterator_traits<InputIterator>::iterator_category* = NULL)
		{
			for (; first != last; first++)
			{
				list_node<T>	*new_el = new list_node<T>;
				new_el->data = *first;
				this->_link_nodes(position._p_data, new_el, new_el);
				this->_tail->data++;
				this->_size++;
			}
		}

		iterator erase (iterator position)
		{
			list_node<T>	*tmp;
			list_node<T>	*ret;

			tmp = position._p_data;
			ret = tmp->next;
			this->_unlink_nodes(tmp, tmp);
			tmp->next = NULL;
			tmp->prev = NULL;
			delete tmp;
			this->_tail->data--;
			this->_size--;
			return ret;
		}

		iterator erase (iterator first, iterator last)
		{
			list_node<T>	*tmp;

			tmp = first._p_data;
			this->_unlink_nodes(tmp, last._p_data->prev);
			for (list_node<T>	*next = first._p_data->next; next != last._p_data;)
			{
				next = first._p_data->next;
				first._p_data->next = NULL;
				first._p_data->prev = NULL;
				delete first._p_data;
				this->_tail->data--;
				this->_size--;
				first._p_data = next;
			}
			return last;	
		}

		void swap (list& x)
		{
			list_node<T>	*tmp;
			size_type	i;

			tmp = this->_tail;
			i = this->_size;
			this->_tail = x._tail;
			this->_size = x.size();
			x._tail = tmp;
			x._size = i;
		}

		void resize (size_type n, value_type val = value_type())
		{
			size_type size = this->_size;

			if (n < this->_size)
			{
				for (size_type i = 0; i < (size - n); i++)
					this->pop_back();
			}
			else
			{
				for (size_type i = 0; i < (n - size); i++)
					this->push_back(val);
			}
		}

		void clear()
		{
			this->_delete_this(false);
		}

		// Member functions: Operations
		void splice (iterator position, list& x)
		{
			this->_link_nodes(position._p_data, x._tail->next, x._tail->prev);
			this->_tail->data += x.size();
			this->_size += x.size();
			x._reset_tail();
		}

		void splice (iterator position, list& x, iterator i)
		{
			i._p_data->prev->next = i._p_data->next;
			i._p_data->next->prev = i._p_data->prev;

			this->_link_nodes(position._p_data, i._p_data, i._p_data);

			x._tail->data--;
			x._size--;
			this->_tail->data++;
			this->_size++;
		}

		void splice (iterator position, list& x, iterator first, iterator last)
		{
			size_type	between_fitst_last = 0;
			iterator	tmp_last = last;

			tmp_last--;

			for (iterator tmp = first; tmp != last; tmp++)
				between_fitst_last++;

			first._p_data->prev->next = last._p_data;
			last._p_data->prev = first._p_data->prev;
			x._tail->data -= between_fitst_last;
			x._size -= between_fitst_last;

			this->_link_nodes(position._p_data, first._p_data, tmp_last._p_data);
			this->_tail->data += between_fitst_last;
			this->_size += between_fitst_last;
		}

		void remove (const value_type& val)
		{
			for (iterator i = this->begin(); i != this->end(); )
			{
				if (*i == val)
				{
					i = this->erase(i);
					continue ;
				}
				i++;
			}
		}

		template <class Predicate>
		void remove_if (Predicate pred)
		{
			for (iterator i = this->begin(); i != this->end(); )
			{
				if (pred(*i))
				{
					i = this->erase(i);
					continue ;
				}
				i++;
			}		
		}

		void unique()
		{
			unique(std::equal_to<T>());
		}

		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred)
		{
			iterator	tmp;
			iterator i = this->begin();

			i++;
			for (; i != this->end(); )
			{
				tmp = i;
				--tmp;
				if (binary_pred(*tmp, *i))
				{
					i = this->erase(i);
					continue ;
				}
				i++;
			}	
		}

		void merge (list& x)
		{
			this->merge(x, std::less<T>());
		}
		
		template <class Compare>
		void merge (list& x, Compare comp)
		{
			list_node<T>	*head1 = this->_tail->next;
			list_node<T>	*head2 = x._tail->next;
			size_type	s = x.size();

			head1->prev = this->_tail->prev;
			head2->prev = x._tail->prev;
			this->_tail->prev->next = head1;
			x._tail->prev->next = head2;

			if (!head1)
			{
				this->_tail->next = head2;
				return ;
			}
			
			if (!head2)
			{
				this->_tail->next = head1;
				return ;
			}
			
			list_node<T>	*last_node;
			if (comp(head1->prev->data, head2->prev->data))
				last_node = head2->prev;
			else
				last_node = head1->prev;
			
			head1->prev->next = NULL;
			head2->prev->next = NULL;

			list_node<T>	*finalHead = this->_merge_sorted_lists(head1, head2, comp);

			finalHead->prev = this->_tail;
			last_node->next = this->_tail;
			this->_tail->next = finalHead;
			this->_tail->prev = last_node;

			this->_tail->data += s;
			this->_size += s;

			x._reset_tail();
		}

		void sort()
		{
			this->sort(std::less<T>());
		}

		template <class Compare>
		void sort (Compare comp)
		{
			list_node<T>	*head;

			head = this->_tail->next;
			head->prev = NULL;
			this->_tail->next = NULL;
			this->_tail->prev->next = NULL;
			this->_tail->prev = NULL;

			this->_merge_sort(&head, comp);

			this->_tail->next = head;
			head->prev = this->_tail;

			while (head->next != NULL)
				head = head->next;
			
			this->_tail->prev = head;
			head->next = this->_tail;
		}

		void reverse()
		{
			list_node<T>	*p = this->_tail->prev;
			list_node<T>	*tmp;

			while (p != this->_tail)
			{
				tmp = p->next;
				p->next = p->prev;
				p->prev = tmp;
				p = p->next;
			}
			tmp = this->_tail->next;
			this->_tail->next = this->_tail->prev;
			this->_tail->prev = tmp;
		}
		
	// Allocator
		allocator_type get_allocator() const
		{
			return (allocator_type());
		}

	// My test function
		// void	_print()
		// {
		// 	for (iterator i = this->begin(); i != this->end(); i++)
		// 	{
		// 		std::cout << *i << " ";
		// 	}
		// 	std::cout << std::endl;
		// }
	};
	
	template <class T, class Alloc>
	bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator< (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator> (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void swap (list<T,Alloc>& x, list<T,Alloc>& y)
	{
		x.swap(y);
	}
};

#endif
