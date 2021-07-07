#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <strings.h>
# include <iterator>
# include <stdexcept>
# include <cstring>

# include "../reverse_iterator.hpp"
# include "vector_iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;
		typedef ft::vector_iterator<T> iterator;
		typedef ft::vector_const_iterator<T> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		allocator_type	_my_alloc;
		size_t			_capacity;
		size_t			_size;
		T				*_v;
	
	public:
	// Constructors
		explicit vector(const allocator_type& alloc = allocator_type())
		{
			this->_my_alloc = alloc;
			this->_capacity = 0;
			this->_size = 0;
			this->_v = NULL;
		}
		
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			this->_my_alloc = alloc;
			this->_size = n;
			this->_capacity = n * 2;
			this->_v = new T[this->_capacity];

			T	*tmp = this->_v;

			bzero(tmp, this->_capacity);
			for (size_type i = 0; i < n; i++)
			{
				*tmp = val;
				tmp++;
			}
		}
		
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename std::iterator_traits<InputIterator>::iterator_category* = NULL)
		{
			this->_my_alloc = alloc;
			this->_size = std::distance(first, last);
			this->_capacity = this->_size * 2;
			this->_v = new T[this->_capacity];

			T	*tmp = this->_v;

			for (; first != last; first++)
			{
				*tmp = *first;
				tmp++;
			}
		}
		
		vector(const vector& x)
		{
			this->_v = NULL;
			this->_size = 0;
			this->_capacity = 0;
			if (this != &x)
				*this = x;
		}
	
	// Destructor
		~vector()
		{
			this->clear();
		}
	
	// Assign operator
		vector& operator=(const vector& x)
		{
			if (this->_v != NULL)
				this->clear();
			this->_my_alloc = x._my_alloc;
			this->_size = x._size;
			this->_capacity = x._capacity;
			this->_v = new T[this->_capacity];
			bzero(this->_v, this->_capacity);

			T	*tmp = this->_v;

			for (size_type i = 0; i < x._size; i++)
			{
				tmp[i] = x[i];
			}

			return (*this);
		}
	
	// Iterators
		iterator begin()
		{
			return (iterator(this->_v));
		}
		
		const_iterator begin() const
		{
			return (const_iterator(this->_v));
		}

		iterator end()
		{
			return (this->_v + this->_size);
		}
		
		const_iterator end() const
		{
			return (const_iterator(this->_v + this->_size));
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(this->end()));
		}
		
		const_reverse_iterator rbegin() const
		{
			return (reverse_iterator(this->end()));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(this->begin()));
		}
		
		const_reverse_iterator rend() const
		{
			return (reverse_iterator(this->begin()));
		}

	// Capacity
		size_type size() const
		{
			return (this->_size);
		}

		size_type max_size() const
		{
			return (std::numeric_limits<size_t>::max() / sizeof(T));
		}
	
		void resize(size_type n, value_type val = value_type())
		{
			while (n > this->_capacity)
				this->reserve(this->_capacity * 2);
			if (n < this->_size)
			{
				size_type	t = this->_size;
				while (n > t)
				{
					this->pop_back();
					n--;
				}
			}
			else if (n > this->_size)
			{
				this->reserve(n);
				while (this->_size < n)
					this->push_back(val);
			}
		}

		size_type capacity() const
		{
			return (this->_capacity);
		}
	
		bool empty() const
		{
			return (this->_size == 0);
		}
	
		void reserve(size_type n)
		{
			if (n > this->_capacity)
			{
				T	*tmp = new T[n];
				size_type	tmp_size = this->_size;

				bzero(tmp, n);
				for (size_type i = 0; i < this->_size; i++)
				{
					tmp[i] = this->_v[i];
				}
				this->clear();
				this->_capacity = n;
				this->_size = tmp_size;
				this->_v = tmp;
			}
		}

	// Element access:
		reference operator[](size_type n)
		{
			T	*tmp = this->_v;

			for (size_type i = 0; i < n; i++)
				tmp++;
			return (*tmp);
		}
		
		const_reference operator[](size_type n) const
		{
			T	*tmp = this->_v;

			for (size_type i = 0; i < n; i++)
				tmp++;
			return (*tmp);
		}
	
		reference at(size_type n)
		{
			if (n >= this->_size)
				throw std::out_of_range("range");
			return (this->_v[n]);
		}
		
		const_reference at(size_type n) const
		{
			if (n >= this->_size)
				throw std::out_of_range("range");
			return (this->_v[n]);
		}
	
		reference front()
		{
			return (*this->_v);
		}
		
		const_reference front() const
		{
			return (*this->_v);
		}
	
		reference back()
		{
			return (*(this->_v + (this->_size - 1)));
		}

		const_reference back() const
		{
			return (*(this->_v + (this->_size - 1)));
		}

	// Modifiers
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last, typename std::iterator_traits<InputIterator>::iterator_category* = NULL)
		{
			this->clear();
			this->_size = std::distance(first, last);
			this->_capacity = this->_size * 2;
			this->_v = new T[this->_capacity];
			bzero(this->_v, this->_capacity);

			T	*tmp = this->_v;

			for (; first != last; first++)
			{
				*tmp = *first;
				tmp++;
			}
		}
		
		void assign(size_type n, const value_type& val)
		{
			this->clear();
			this->_size = n;
			this->_capacity = this->_size * 2;
			this->_v = new T[this->_capacity];
			bzero(this->_v, this->_capacity);

			T	*tmp = this->_v;

			for (size_type i = 0; i < n; i++)
			{
				*tmp = val;
				tmp++;
			}
		}

		void push_back(const value_type& val)
		{
			if (this->_size + 1 > this->_capacity)
			{
				this->reserve(this->_capacity * 2);
			}
			*(this->_v + this->_size) = val;
			this->_size++;
		}

		void pop_back()
		{
			T	*tmp;

			tmp = this->_v + this->_size - 1;
			tmp = NULL;
			this->_size--;
		}

		iterator insert(iterator position, const value_type& val)
		{
			size_type	p = std::distance(this->begin(), position);
			
			if (this->_size == 0)
			{
				assign(1, val);
				return (this->begin());
			}
			if (this->_size + 1 > this->_capacity)
				this->reserve(this->_capacity * 2);

			iterator	it(this->_v + p);
			iterator	i_end = this->end();

			for (; i_end != it;)
			{
				--i_end;
				*(i_end + 1) = *i_end; 
			}
			*it = val;
			this->_size++;
			return (it);
		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			size_type	p = std::distance(this->begin(), position);

			if (this->_size == 0)
			{
				assign(n, val);
				return ;
			}
			while (this->_size + 1 > this->_capacity)
				this->reserve(this->_capacity * 2);
		
			iterator	it(this->_v + p);
			iterator	i_end = this->end();

			for (; i_end != it;)
			{
				--i_end;
				*(i_end + n) = *i_end; 
			}

			for (size_type i = 0; i < n; i++)
			{
				*it = val;
				it++;
				this->_size++;
			}
		}
		
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, typename std::iterator_traits<InputIterator>::iterator_category* = NULL)
		{
			size_type	len = std::distance(first, last);
			size_type	p = std::distance(this->begin(), position);

			if (this->_size == 0)
			{
				this->_capacity = len * 2;
				this->_v = new T[this->_capacity];
			}
			while (this->_size + len > this->_capacity)
				this->reserve(this->_capacity * 2);
		
			iterator	it(this->_v + p);
			iterator	i_end = this->end();

			for (; i_end != it;)
			{
				--i_end;
				*(i_end + len) = *i_end; 
			}

			for (; first != last; first++)
			{
				*it = *first;
				it++;
				this->_size++;
			}
		}

		iterator erase (iterator position)
		{
			iterator	res = position;

			res++;
			for (; position != this->end(); position++)
			{
				*position = *(position + 1);
			}
			this->_size--;
			return (res);
		}
		
		iterator erase (iterator first, iterator last)
		{
			iterator	res = last;
			size_type	len = std::distance(first, last);

			for (; first != last; first++)
			{
				*first = *(first + 1);
			}
			this->_size -= len;
			return (res);
		}

		void swap (vector& x)
		{
			T	*tmp_v;
			size_type	tmp_size;
			size_type	tmp_capacity;
			allocator_type	tmp_alloc;

			tmp_v = this->_v;
			tmp_size = this->_size;
			tmp_capacity = this->_capacity;
			tmp_alloc = this->_my_alloc;

			this->_v = x._v;
			this->_size = x._size;
			this->_capacity = x._capacity;
			this->_my_alloc = x._my_alloc;

			x._v = tmp_v;
			x._size = tmp_size;
			x._capacity = tmp_capacity;
			x._my_alloc = tmp_alloc;
		}

		void clear()
		{
			if (this->_v != NULL)
				delete[]	this->_v;
			this->_size = 0;
		}

	// Allocator
		allocator_type get_allocator() const
		{
			return (allocator_type());
		}
	};

	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
    	return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}
};

#endif
