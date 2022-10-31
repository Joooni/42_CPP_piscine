#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <cstdlib>
# include <algorithm>
# include <iostream>
# include <vector>
# include "colors.hpp"

# ifndef M_DEBUG
#  define M_DEBUG	0
# endif

class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		Span &operator=(const Span &rhs);
		~Span();

		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		void			addNumber(int nbr);
		void			fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void			replace(int oldValue, int newValue);
		class OutOfCapacityException: public std::exception{
			const char *what() const throw();
		};
		class SizeTooSmallException: public std::exception{
			const char *what() const throw();
		};
	private:
		std::vector<int>	_content;
		unsigned int		_N;
};

#endif
