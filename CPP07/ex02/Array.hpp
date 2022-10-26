
#ifndef ARRAY_HPP
# define ARRAY_HPP


template <typename T>
class Array
{
	public:
		Array(): _size(0), _content(new T[_size]){};
		Array(size_t n): _size(n), _content(new T[_size]){};
		Array(const Array &src): _size(src._size), _content(new T[_size])
		{
			if (this->_size > 0)
			{
				for (size_t i = 0; i < this->_size; i++)
					this->_content[i] = src._content[i];
			}
		};

		Array &operator=(Array rhs)
		{
			arr_swap(*this, rhs);
			return (*this);
		};

		~Array()
		{
			delete[] (this->_content);
		};

		size_t size()
		{
			return (this->_size);
		};

		void arr_swap(Array &first, Array &second)
		{
			std::swap(first._size, second._size);
			std::swap(first._content, second._content);
		};

		T	&operator[](size_t index)
		{
			if (this->_size < 1 || index > this->_size - 1)
				throw IndexOutOfBoundsException();
			return (this->_content[index]);
		};

		class IndexOutOfBoundsException: public std::exception
		{
			const char *what() const throw() {return ("Exception: Index out of bounds");}
		};

	private:
		size_t	_size;
		T		*_content;
};


#endif
