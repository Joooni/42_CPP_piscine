#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
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
	this->_type = rhs.getType();
	delete this->_brain;
	this->_brain = new Brain(*rhs._brain);
	std::cout << "Assignment operator Dog called" << std::endl;
	return (*this);
}

// Animal &Dog::operator=(const Animal &rhs)
// {
// 	this->_type = rhs.getType();
// 	*(this->_brain) = *(rhs.getBrain());
// 	std::cout << "Animal Assignment operator for Dog called" << std::endl;
// 	return (*this);
// }

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

std::string	Dog::getIdea(int i) const
{
	return (this->_brain->getIdea(i));
}

void		Dog::setIdea(std::string idea, int i)
{
	this->_brain->setIdea(idea, i);
}
