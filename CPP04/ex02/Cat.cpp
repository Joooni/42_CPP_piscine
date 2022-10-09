#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << "Standard Cat Constructor called, meow." << std::endl;
}

Cat::Cat(const Cat &rhs)
{
	*this = rhs;
	this->_brain = rhs.getBrain();
	std::cout << "Cat Copy Constructor called, meow meow." << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	this->type = rhs.getType();
	*(this->_brain) = *(rhs.getBrain());
	std::cout << "Assignment operator Cat called" << std::endl;
	return (*this);
}

AAnimal &Cat::operator=(const AAnimal &rhs)
{
	this->type = rhs.getType();
	*(this->_brain) = *(rhs.getBrain());
	std::cout << "Abstract Animal Assignment operator for Cat called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat Destructor called, sad meow :(" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meeeeeowwwwwwwww" << std::endl;
}

Brain *Cat::getBrain() const
{
	return (this->_brain);
}
