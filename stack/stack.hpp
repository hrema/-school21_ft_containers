#ifndef STACK_HPP
# define STACK_HPP

# include <deque>

namespace ft
{
	template <class T, class Container = std::deque<T> >
	class stack
	{
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

	private:
		container_type	_my_cont_type;

	public:
		explicit stack(const container_type& ctnr = container_type())
		{
			this->_my_cont_type = ctnr;
		}

		stack(stack<T, Container> const &other)
		{
			this->_my_cont_type = other._my_cont_type;
		}

		~stack()
		{
		}

		stack	&operator=(stack const &other)
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

		value_type& top()
		{
			return (this->_my_cont_type.back());
		}
		
		const value_type& top() const
		{
			return (this->_my_cont_type.back());
		}

		void push (const value_type& val)
		{
			return (this->_my_cont_type.push_back(val));
		}

		void pop()
		{
			return (this->_my_cont_type.pop_back());
		}
	};

	template <class T, class Container>
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._my_cont_type == rhs._my_cont_type);
	}
	
	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._my_cont_type != rhs._my_cont_type);
	}
	
	template <class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._my_cont_type < rhs._my_cont_type);
	}
	
	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._my_cont_type <= rhs._my_cont_type);
	}
	
	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._my_cont_type > rhs._my_cont_type);
	}
	
	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._my_cont_type >= rhs._my_cont_type);
	}
}

#endif
