#ifndef REVERSE_ITERATOR
# define REVERSE_ITERATOR

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
	protected:
		Iterator	_curr;

	public:
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef Iterator iterator_type;
		typedef typename Iterator::iterator_category	iterator_category;

		reverse_iterator(): _curr()
		{
		}

		explicit reverse_iterator(iterator_type it): _curr(it)
		{
		}
		
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_it): _curr(rev_it.base())
		{
		}

		reverse_iterator&	operator=(const reverse_iterator &iter)
		{
			this->_curr = iter.base();
			return (*this);	
		}

		~reverse_iterator()
		{
		}

		iterator_type base() const
		{
			return (this->_curr);
		}

		reference operator*() const
		{
			Iterator	tmp(this->_curr);
			return (*--tmp);
		}

		reverse_iterator& operator++()
		{
			--this->_curr;
			return (*this);
		}

		reverse_iterator operator++(int)
		{
  			reverse_iterator tmp(*this);
  			--this->_curr;
  			return tmp;
		}

		reverse_iterator& operator--()
		{
			++this->_curr;
			return (*this);
		}

		reverse_iterator operator--(int)
		{
  			reverse_iterator tmp = *this;
  			++this->_curr;
  			return tmp;
		}

		pointer operator->() const
		{
  			return &(operator*());
		}

		reverse_iterator	operator+ (difference_type n) const
		{
			return (reverse_iterator(this->_curr - n));
		}

		reverse_iterator&	operator+= (difference_type n)
		{
			this->_curr -= n;
			return (*this);
		}

		reverse_iterator	operator- (difference_type n) const
		{
			return (reverse_iterator(this->_curr + n));
		}

		reverse_iterator&	operator-= (difference_type n)
		{
			this->_curr += n;
			return (*this);
		}

		reference operator[] (difference_type n) const
		{
			return *(*this + n);
		}
	};

	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}
	
	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}
	
	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	}
	
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	
	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}
	
	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
	reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n,
											const reverse_iterator<Iterator>& rev_it)
	{
		return reverse_iterator<Iterator>(rev_it.base() - n);
	}
	
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs,
																		const reverse_iterator<Iterator>& rhs)
	{
		return (rhs.base() - lhs.base());
	}
}

#endif
