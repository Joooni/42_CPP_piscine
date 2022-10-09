#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "Standard WrongCat Constructor called, meow." << std::endl;
}

WrongCat::WrongCat(const WrongCat &src)
{
	*this = src;
	std::cout << "WrongCat Copy Constructor called, meow meow." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called, sad meow :(" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Wǝǝǝǝǝoʍʍʍʍʍʍʍʍʍ" << std::endl;
}
