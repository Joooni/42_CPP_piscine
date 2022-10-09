#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("nondescript WrongAnimal")
{
	std::cout << "WrongAnimal standard constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	this->_type = src.getType();
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Standard destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
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
