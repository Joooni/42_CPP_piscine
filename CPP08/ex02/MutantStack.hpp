#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>

# include <algorithm>

# define DELIM	std::cout << std::string(80, '-') << std::endl;
template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src;}
	MutantStack<T>& operator=(const MutantStack<T>& rhs)
	{
		std::stack<T>::operator=(rhs);
		return *this;
	}
	~MutantStack() {}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() { return (this->c.begin()); }
	iterator end() { return (this->c.end()); }
};

#endif
