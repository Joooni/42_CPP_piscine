#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "Standard Dog Constructor called, borf." << std::endl;
}

Dog::Dog(const Dog &rhs)
{
	*this = rhs;
	this->_brain = rhs.getBrain();
	std::cout << "Dog Copy Constructor called, borf borf." << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	this->type = rhs.getType();
	*(this->_brain) = *(rhs.getBrain());
	std::cout << "Assignment operator Dog called" << std::endl;
	return (*this);
}

AAnimal &Dog::operator=(const AAnimal &rhs)
{
	this->type = rhs.getType();
	*(this->_brain) = *(rhs.getBrain());
	std::cout << "Abstract Animal Assignment operator for Dog called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog Destructor called, sad borf :(" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bork bork bork" << std::endl;
}

Brain *Dog::getBrain() const
{
	return (this->_brain);
}
