#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

namespace ft
{
	enum	Colors
	{
		RED,
		BLACK,
		NON_COLOR,
		TAIL_COLOR,
	};

	template <typename Key, typename T>
	struct	map_node
	{
		std::pair<Key, T>	data;
		Colors		color;
		map_node		*left;
		map_node		*right;
		map_node		*root;
	};

	template <class Key, class T>
	class map_iterator
	{
		protected:
			map_node<Key, T>	*_p_data;
			map_node<Key, T>	_null_node;

			void	_init_null_node()
			{
				this->_null_node.color = NON_COLOR;
				this->_null_node.left = NULL;
				this->_null_node.right = NULL;
				this->_null_node.root = NULL;
			}

		public:
			friend class ft::map<Key, T>;

    		typedef std::pair<Key, T>	value_type;
    		typedef ptrdiff_t 	difference_type;
    		typedef std::pair<Key, T>*			pointer;
    		typedef std::pair<Key, T>&			reference;
			typedef std::bidirectional_iterator_tag	iterator_category;

			map_iterator()
			{
				this->_init_null_node();
			}

			map_iterator(const map_iterator &iter)
			{
				this->_p_data = iter._p_data;
				this->_init_null_node();
			}


			map_iterator(map_node<Key, T> *node)
			{
				this->_p_data = node;
				this->_init_null_node();
			}

			map_iterator(map_node<Key, T> &node)
			{
				this->_p_data = node;
				this->_init_null_node();
			}

			map_iterator&	operator=(const map_iterator &iter)
			{
				this->_p_data = iter._p_data;
				this->_init_null_node();
				return (*this);	
			}

			~map_iterator()
			{
			}

			bool			operator==(const map_iterator &iter)
			{
				if (this->_p_data == iter._p_data)
					return (true);
				else
					return (false);
			}

			bool			operator!=(const map_iterator &iter)
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

			map_iterator				&operator++()
			{
				map_node<Key, T>	*tmp;
				map_node<Key, T>	*tmp2;

				tmp = this->_p_data;
				if (tmp->right->color != this->_null_node.color)
				{
					tmp = tmp->right;
					if (tmp->color == TAIL_COLOR)
					{
						*this = tmp;
						return (*this);
					}
					while (tmp->left->color != this->_null_node.color)
						tmp = tmp->left;
				}
				else if (tmp->right->color == this->_null_node.color && tmp->root && tmp->data.first > tmp->root->data.first)
				{
					tmp2 = tmp->root;

					while (tmp->data.first > tmp2->data.first)
						tmp2 = tmp2->root;
					tmp = tmp2;
				}
				else if (tmp->right->color == this->_null_node.color && tmp->root && tmp->data.first < tmp->root->data.first)
				{
					tmp = tmp->root;
				}
				else if (tmp->right->color != this->_null_node.color)
					tmp = tmp->right;
				this->_p_data = tmp;
				return (*this);
			}

			map_iterator				operator++(int)
			{
				map_iterator	temp(this->_p_data);

				++(*this);
				return (temp);
			}
			
			map_iterator				&operator--()
			{
				map_node<Key, T>	*tmp;

				tmp = this->_p_data;
				if (tmp->color == TAIL_COLOR)
					tmp = tmp->root;
				else if (tmp->left->color != this->_null_node.color)
				{
					tmp = tmp->left;
					// if (tmp->color == TAIL_COLOR)
					// {
					// 	*this = tmp;
					// 	return (*this);
					// }
					while (tmp->right->color != this->_null_node.color)
						tmp = tmp->right;
				}
				else if (tmp->left->color == this->_null_node.color && tmp->root && tmp->data.first > tmp->root->data.first)
				{
					tmp = tmp->root;
				}
				else if (tmp->left->color == this->_null_node.color && tmp->root && tmp->root->root)
				{
					while (tmp->root && tmp->data.first < tmp->root->data.first)
						tmp = tmp->root;
					tmp = tmp->root;
				}
				else if (tmp->left->color != this->_null_node.color)
					tmp = tmp->left;
				this->_p_data = tmp;
				return (*this);
			}

			map_iterator				operator--(int)
			{
				map_iterator	temp(this->_p_data);

				--(*this);
				return (temp);
			}
  	};
	
	template <class Key, class T>
	class map_const_iterator: public map_iterator<Key, T>
	{
		public:
    		typedef std::pair<Key, T>	value_type;
    		typedef ptrdiff_t 	difference_type;
    		typedef const std::pair<Key, T>*			pointer;
    		typedef const std::pair<Key, T>&			reference;
			typedef std::bidirectional_iterator_tag	iterator_category;
	
			map_const_iterator(): map_iterator<Key, T>()
			{
			}

			map_const_iterator(const map_const_iterator &iter): map_iterator<Key, T>(iter)
			{
			}

			map_const_iterator(map_node<Key, T> *node)
			{
				this->_p_data = node;
				this->_init_null_node();
			}

			map_const_iterator(map_node<Key, T> &node)
			{
				this->_p_data = node;
				this->_init_null_node();
			}

			map_const_iterator&	operator=(const map_const_iterator &iter)
			{
				this->_p_data = iter._p_data;
				this->_init_null_node();
				return (*this);
			}

			~map_const_iterator()
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
}

#endif
