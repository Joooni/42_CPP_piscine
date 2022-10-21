#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	if (M_DEBUG)
		std::cout << "Standard WrongCat Constructor called, meow." << std::endl;
}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal()
{
	*this = src;
	if (M_DEBUG)
		std::cout << "WrongCat Copy Constructor called, meow meow." << std::endl;
}

WrongCat::~WrongCat()
{
	if (M_DEBUG)
		std::cout << "WrongCat Destructor called, sad meow :(" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Wǝǝǝǝǝoʍʍʍʍʍʍʍʍʍ" << std::endl;
}
