
#ifndef ARRAY_HPP
# define ARRAY_HPP
template <typename T>
class Array
{
	public:
		Array();
		Array(size_t n);
		Array(const Array &src);
		Array &operator=(Array rhs);
		~Array();

		size_t size();
		void arr_swap(Array &first, Array &second);

		T	&operator[](size_t index);
		class IndexOutOfBoundsException: public std::exception
		{
			const char *what() const throw() {return ("Exception: Index out of bounds");}
		};

	private:
		size_t	_size;
		T		*_content;
};

# include "Array.tpp"

#endif
