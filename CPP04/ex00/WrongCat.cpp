#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	if (M_DEBUG)
		std::cout << "Standard WrongCat Constructor called, meow." << std::endl;
}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal()
{
	*this = src;
	if (M_DEBUG)
		std::cout << "WrongCat Copy Constructor called, meow meow." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	if (M_DEBUG)
		std::cout << "WrongCat copy assigment operator" << std::endl;
	this->_type = rhs._type;
	return (*this);
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
