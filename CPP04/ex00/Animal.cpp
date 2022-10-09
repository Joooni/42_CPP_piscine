#include "Animal.hpp"

Animal::Animal() : _type("nondescript animal")
{
	std::cout << "Animal standard constructor called" << std::endl;
}

Animal::Animal(const Animal &src)
{
	*this = src;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	this->_type = src.getType();
	std::cout << "Animal assignment operator called" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "beep boop, I am an actual totally not robot animal that makes the universal animal sound, boop beep" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Animal &animal)
{
	os << animal.getType();
	return (os);
}
