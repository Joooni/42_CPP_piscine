#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>

class NoOccurenceException: public std::exception
{
	const char *what() const throw() {return ("Value does not occur in container");}
};

template <typename T>
typename T::iterator	easyfind(T container, int i)
{
	typename T::iterator it = find(container.begin(), container.end(), i);
	if (it == container.end())
		throw NoOccurenceException();
	return (it);
}

#endif
