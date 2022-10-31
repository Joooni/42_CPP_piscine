#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <string>

int main(void)
{
	std::vector<int>	int_vector;
	std::list<int>		int_list;
	srand(time(NULL));   // Initialization, should only be called once.
	int rando;
	for (int i = 0; i < 20; i++)
	{
		rando = rand() + (i * 7);
		int_vector.push_back(rando % 40);
		int_list.push_back(i);
	}
	std::cout << "Let's try to find a number between 0 and 21 in list:" << std::endl;
	for (int i = 0; i < 21; i++)
	{
		try
		{
			std::cout << *(easyfind(int_list, i)) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "Let's try to shuffle and find the numbers in vector:" << std::endl;
	std::random_shuffle(int_vector.begin(), int_vector.end());
	for (int i = 0; i < 20; i++)
		std::cout << "vector[" << i << "]:\t" << int_vector[i] << std::endl;
	for (int i = 0; i < 21; i++)
	{
		try
		{
			std::cout << "Found " << *(easyfind(int_vector, i)) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
