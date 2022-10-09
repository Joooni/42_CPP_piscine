#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << "Standard Dog Constructor called, borf." << std::endl;
}

Dog::Dog(const Dog &src)
{
	*this = src;
	std::cout << "Dog Copy Constructor called, borf borf." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog copy assigment operator" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called, sad borf :(" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bork bork bork" << std::endl;
}
