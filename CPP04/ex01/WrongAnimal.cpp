#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("nondescript WrongAnimal")
{
	if (M_DEBUG)
		std::cout << "WrongAnimal standard constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
	if (M_DEBUG)
		std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	this->type = src.getType();
	if (M_DEBUG)
		std::cout << "WrongAnimal assignment operator called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	if (M_DEBUG)
		std::cout << "Standard destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "beep boop, I am an actual totally not robot WrongAnimal that makes the universal WrongAnimal sound, boop beep" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const WrongAnimal &WrongAnimal)
{
	os << WrongAnimal.getType();
	return (os);
}
