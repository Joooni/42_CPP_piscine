#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T>
void	iter(T *addr, int len, void (*f)(T&))
{
	for (int i = 0; i < len; i++)
		(*f)(addr[i]);
}

template <typename T>
void	iter(const T *arr, int len, void (*f)(const T&)) {
	int	index = 0;

	while (index < len)
		(*f)(arr[index++]);
}

template <typename T>
void	print(T out)
{
	std::cout << out << std::endl;
}

template <typename T>
void	double_it(T &input)
{
	input *= 2;
}

template <typename T>
void	substract_one(T &input)
{
	input--;
}


void add_one(int &input) {
	input++;
}

void capitalization(char &input) {
	input = std::toupper(input);
	return;
}

#endif
