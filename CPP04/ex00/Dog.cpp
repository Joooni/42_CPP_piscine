#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	if (M_DEBUG)
		std::cout << "Standard Dog Constructor called, borf." << std::endl;
}

Dog::Dog(const Dog &src): Animal()
{
	*this = src;
	if (M_DEBUG)
		std::cout << "Dog Copy Constructor called, borf borf." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (M_DEBUG)
		std::cout << "Dog copy assigment operator" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

Dog::~Dog()
{
	if (M_DEBUG)
		std::cout << "Dog Destructor called, sad borf :(" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bork bork bork" << std::endl;
}
