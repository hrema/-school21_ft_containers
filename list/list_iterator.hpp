#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

# include <iterator>

namespace ft
{
	template <typename T>
	struct	list_node
	{
		T		data;
		list_node	*prev;
		list_node	*next;
	};

	template <class T>
	class list_iterator
	{
		protected:
			list_node<T>	*_p_data;

		public:
			friend class ft::list<T>;

    		typedef T			value_type;
    		typedef ptrdiff_t 	difference_type;
    		typedef T*			pointer;
    		typedef T&			reference;
			typedef std::bidirectional_iterator_tag	iterator_category;

			list_iterator()
			{
			}

			list_iterator(const list_iterator &iter)
			{
				this->_p_data = iter._p_data;
			}

			list_iterator(list_node<T> *node)
			{
				this->_p_data = node;
			}

			list_iterator(list_node<T> &node)
			{
				this->_p_data = node;
			}

			list_iterator&	operator=(const list_iterator &iter)
			{
				this->_p_data = iter._p_data;
				return (*this);	
			}

			~list_iterator()
			{
			}

			bool			operator==(const list_iterator &iter)
			{
				if (this->_p_data == iter._p_data)
					return (true);
				else
					return (false);
			}

			bool			operator!=(const list_iterator &iter)
			{
				if (this->_p_data != iter._p_data)
					return (true);
				else
					return (false);
			}

			reference 		operator*()
			{
				return (this->_p_data->data);
			}

			pointer			operator->()
			{
				return (&this->_p_data->data);
			}

			list_iterator				&operator++()
			{
				this->_p_data = this->_p_data->next;
				return (*this);
			}

			list_iterator				operator++(int)
			{
				list_iterator	temp(this->_p_data);

				++(*this);
				return (temp);
			}
			
			list_iterator				&operator--()
			{
				this->_p_data = this->_p_data->prev;
				return (*this);
			}

			list_iterator				operator--(int)
			{
				list_iterator	temp(this->_p_data);

				--(*this);
				return (temp);
			}
  	};

	template <class T>
	class list_const_iterator: public list_iterator<T>
	{
		public:
			typedef T			value_type;
    		typedef ptrdiff_t 	difference_type;
    		typedef const T*	pointer;
    		typedef const T&	reference;
			typedef std::bidirectional_iterator_tag	iterator_category;
	
			list_const_iterator(): list_iterator<T>()
			{
			}

			list_const_iterator(const list_const_iterator &iter): list_iterator<T>(iter)
			{
			}

			list_const_iterator(list_node<T> *node)
			{
				this->_p_data = node;
			}

			list_const_iterator(list_node<T> &node)
			{
				this->_p_data = node;
			}

			list_const_iterator&	operator=(const list_const_iterator &iter)
			{
				this->_p_data = iter._p_data;
				return (*this);	
			}

			~list_const_iterator()
			{
			}

			reference 		operator*() const
			{
				return (this->_p_data->data);
			}

			pointer			operator->() const
			{
				return (&this->_p_data->data);
			}
  	};
};

#endif
