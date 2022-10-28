template <typename T>
Array<T>::Array(): _size(0), _content(new T[_size])
{

}

template <typename T>
Array<T>::Array(size_t n): _size(n), _content(new T[_size])
{

}

template <typename T>
Array<T>::Array(const Array &src): _size(src._size), _content(new T[_size])
{
	if (this->_size > 0)
	{
		for (size_t i = 0; i < this->_size; i++)
			this->_content[i] = src._content[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(Array rhs)
{
	arr_swap(*this, rhs);
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] (this->_content);
}

template <typename T>
size_t Array<T>::size()
{
	return (this->_size);
}

template <typename T>
void Array<T>::arr_swap(Array &first, Array &second)
{
	std::swap(first._size, second._size);
	std::swap(first._content, second._content);
}

template <typename T>
T	&Array<T>::operator[](size_t index)
{
	if (this->_size < 1 || index > this->_size - 1)
		throw IndexOutOfBoundsException();
	return (this->_content[index]);
}
