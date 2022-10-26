#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

template <typename T>
void	swap(T &first, T &second)
{
	T	tmp;
	tmp = first;
	first = second;
	second = tmp;
}

template <typename T>
T	const &min(const T &first,const T &second)
{
	return ((first < second ? first : second));
}

template <typename T>
T	const &max(T const &first,T const &second)
{
	return ((first > second ? first : second));
}



#endif
