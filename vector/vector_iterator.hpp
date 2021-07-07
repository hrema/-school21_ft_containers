#ifndef VECTOR_ITERATOR
# define VECTOR_ITERATOR

# include <iterator>

namespace ft
{
	template <class T>
	class vector_iterator
	{
		public:
    		typedef T			value_type;
    		typedef ptrdiff_t 	difference_type;
    		typedef T*			pointer;
    		typedef T&			reference;
			typedef std::random_access_iterator_tag	iterator_category;
		
		protected:
			pointer	_p;

		public:
			vector_iterator()
			{
				this->_p = NULL;
			}

			vector_iterator(pointer b)
			{
				this->_p = b;
			}

			vector_iterator(const vector_iterator &iter)
			{
				*this = iter;
			}

			vector_iterator&	operator=(const vector_iterator &iter)
			{
				this->_p = iter._p;
				return (*this);	
			}

			~vector_iterator()
			{
			}

			bool			operator==(const vector_iterator &iter)
			{
				return (this->_p == iter._p);
			}

			bool			operator!=(const vector_iterator &iter)
			{
				return (this->_p != iter._p);
			}

			reference 		operator*()
			{
				return (*this->_p);
			}

			pointer			operator->()
			{
				return (&this->_p);
			}

			vector_iterator				&operator++()
			{
				++this->_p;
				return (*this);
			}

			vector_iterator				operator++(int)
			{
				vector_iterator	temp(this->_p);

				++(*this);
				return (temp);
			}
			
			vector_iterator				&operator--()
			{
				--this->_p;
				return (*this);
			}

			vector_iterator				operator--(int)
			{
				vector_iterator	temp(this->_p);

				--(*this);
				return (temp);
			}

			vector_iterator	operator+(int value) const
			{
				vector_iterator	tmp(this->_p);

				tmp += value;
				return (tmp);
			}

			vector_iterator	operator-(int value) const
			{
				vector_iterator	tmp(this->_p);

				tmp -= value;
				return (tmp);
			}

			difference_type	operator-(vector_iterator const &other) const
			{
				return (this->_p - other._p);
			}

			bool	operator<(vector_iterator const &other) const
			{
				return (this->_p < other._p);
			}

			bool	operator>(vector_iterator const &other) const
			{
				return (this->_p > other._p);
			}

			bool	operator<=(vector_iterator const &other) const
			{
				return (this->_p <= other._p);
			}

			bool	operator>=(vector_iterator const &other) const
			{
				return (this->_p >= other._p);
			}

			vector_iterator	operator+=(int value)
			{
				this->_p += value;
				return (*this);
			}

			vector_iterator	operator-=(int value)
			{
				this->_p -= value;
				return (*this);
			}

			reference	operator[](int val)
			{
				return (*(this->_p + val));
			}
  	};

	template <class T>
	class vector_const_iterator: public vector_iterator<T>
	{
		public:
    		typedef T			value_type;
    		typedef ptrdiff_t 	difference_type;
    		typedef T*			pointer;
    		typedef T&			reference;
			typedef std::random_access_iterator_tag	iterator_category;
		
		protected:
			pointer	_p;

		public:
			vector_const_iterator()
			{
				this->_p = NULL;
			}

			vector_const_iterator(pointer b)
			{
				this->_p = b;
			}

			vector_const_iterator(const vector_const_iterator &iter)
			{
				*this = iter;
			}

			vector_const_iterator&	operator=(const vector_const_iterator &iter)
			{
				this->_p = iter._p;
				return (*this);	
			}

			~vector_const_iterator()
			{
			}

			reference 		operator*() const
			{
				return (*this->_p);
			}

			pointer			operator->() const
			{
				return (&this->_p);
			}

			reference	operator[](int val) const
			{
				return (*(this->_p + val));
			}
  	};
};

#endif
