#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "Standard Dog Constructor called, borf." << std::endl;
}

Dog::Dog(const Dog &rhs): Animal()
{
	this->_type = rhs.getType();
	this->_brain = new Brain;
	*(this->_brain) = (*rhs._brain);
	std::cout << "Dog Copy Constructor called, borf borf." << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	this->_type = rhs.getType();
	*(this->_brain) = (*rhs._brain);
	std::cout << "Assignment operator Cat called" << std::endl;
	return (*this);
}

// AAnimal &Dog::operator=(const AAnimal &rhs)
// {
// 	this->type = rhs.getType();
// 	*(this->_brain) = *(rhs.getBrain());
// 	std::cout << "Abstract Animal Assignment operator for Dog called" << std::endl;
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
