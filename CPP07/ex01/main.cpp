#include "iter.hpp"
#include <iostream>
int main(void)
{
	int numbers[5] = {5, 2, 3, 13, 9};
	int *numptrs[5];
	char chars[5] = {'h', 'm', 's', 'b', 'c'};
	char *charptrs[5];
	for (int i = 0; i < 5; i++)
	{
		numptrs[i] = &numbers[i];
		charptrs[i] = &chars[i];
	}
	iter<int>(numbers, 5, print);
	std::cout << std::string(10, '-') << std::endl;
	iter<int*>(numptrs, 5, double_it);
	iter<int>(numbers, 5, print);
	std::cout << std::string(10, '-') << std::endl;
	iter<char>(chars, 5, print);
	std::cout << std::string(10, '-') << std::endl;
	iter<char*>(charptrs, 5, substract_one);
	iter<char>(chars, 5, print);
	return (0);
}
