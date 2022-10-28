#include "iter.hpp"
#include <iostream>
#include "colors.hpp"

class Awesome {
	public:
		Awesome(void) : _n(42) {
			return;
		}
		int get(void) const {
			return this->_n;
		}
	private:
		int _n;
};

std::ostream & operator<<(std::ostream& o, const Awesome& rhs) {
	o << rhs.get();
	return o;
}



template <typename T>
void print(const T& x) {
	std::cout << x << " ";
	return;
}

int main(void)
{
	int length = 5;
	int num[5] = {1, 2, 3, 4, 5};
	char letter[5] = {'a', 'b', '1', '!', 'f'};
	std::cout << COLOR_RED << "--- removed new line from print() ---" << END << std::endl;

	std::cout << std::endl << COLOR_CYAN << "<<<< Function iter() and print() on num array >>>>" << END << std::endl;
	iter(num, length, print);
	std::cout << std::endl << "Executing Function add_one() on num array..." << std::endl;
	iter(num, length, add_one);
	std::cout << COLOR_GREEN << "num array is now: " << END << std::endl;
	iter(num, length, print);
	std::cout << std::endl << "Executing Function double_it() on num array..." << std::endl;
	iter(num, length, double_it);
	std::cout << COLOR_GREEN << "num array is now: " << END << std::endl;
	iter(num, length, print);
	std::cout << std::endl;

	std::cout << std::endl << COLOR_CYAN << "<<<< Function iter() and print() on letter array >>>>" << END << std::endl;
	iter(letter, length, print);
	std::cout << std::endl << "Executing Function capitalization() on letter array..." << std::endl;
	iter(letter, length, capitalization);
	std::cout << COLOR_GREEN << "letter array is now: " << END << std::endl;
	iter(letter, length, print);
	std::cout << std::endl;

	std::cout << std::endl << COLOR_YELLOW << "<<<< Testing with the Awesome class from the eval sheet >>>>" << END << std::endl;
	int tab[] = {0, 1, 2, 3, 4};
	Awesome tab2[5];
	std::cout << COLOR_GREEN << "Number array from eval sheet: " << END << std::endl;
	iter(tab, length, print);
	std::cout << std::endl;
	std::cout << COLOR_GREEN << "Awesome class array: " << END << std::endl;
	iter(tab2, length, print);
	std::cout << std::endl << std::endl;
	return (0);
}
