#ifndef QUEUE_HPP
# define QUEUE_HPP

# include <deque>

namespace ft
{
	template <class T, class Container = std::deque<T> >
	class queue
	{
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

	private:
		container_type	_my_cont_type;

	public:
		explicit queue(const container_type& ctnr = container_type())
		{
			this->_my_cont_type = ctnr;
		}

		queue(queue<T, Container> const &other)
		{
			this->_my_cont_type = other._my_cont_type;
		}

		~queue()
		{
		}

		queue	&operator=(queue const &other)
		{
			this->_my_cont_type = other._my_cont_type;
			return (*this);
		}

		bool empty() const
		{
			return (this->_my_cont_type.empty());
		}

		size_type size() const
		{
			return (this->_my_cont_type.size());
		}

		value_type& front()
		{
			return (this->_my_cont_type.front());
		}
		
		const value_type& front() const
		{
			return (this->_my_cont_type.front());
		}

		value_type& back()
		{
			return (this->_my_cont_type.back());
		}
		
		const value_type& back() const
		{
			return (this->_my_cont_type.back());
		}

		void push (const value_type& val)
		{
			return (this->_my_cont_type.push_back(val));
		}

		void pop()
		{
			return (this->_my_cont_type.pop_front());
		}
	};

	template <class T, class Container>
	bool operator==(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs._my_cont_type == rhs._my_cont_type);
	}
	
	template <class T, class Container>
	bool operator!=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs._my_cont_type != rhs._my_cont_type);
	}
	
	template <class T, class Container>
	bool operator<(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs._my_cont_type < rhs._my_cont_type);
	}
	
	template <class T, class Container>
	bool operator<=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs._my_cont_type <= rhs._my_cont_type);
	}
	
	template <class T, class Container>
	bool operator>(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs._my_cont_type > rhs._my_cont_type);
	}
	
	template <class T, class Container>
	bool operator>=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs._my_cont_type >= rhs._my_cont_type);
	}
}

#endif
