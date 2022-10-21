#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	if (M_DEBUG)
		std::cout << "Standard Cat Constructor called, meow." << std::endl;
}

Cat::Cat(const Cat &rhs): AAnimal()
{
	this->_type = rhs.getType();
	this->_brain = new Brain;
	*(this->_brain) = (*rhs._brain);
	if (M_DEBUG)
		std::cout << "Cat Copy Constructor called, meow meow." << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	this->_type = rhs.getType();
	*(this->_brain) = (*rhs._brain);
	if (M_DEBUG)
		std::cout << "Assignment operator Cat called" << std::endl;
	return (*this);
}


/* AAnimal &Cat::operator=(const AAnimal &rhs)
{
	this->type = rhs.getType();
	*(this->_brain) = *(rhs.getBrain());
	std::cout << "Abstract Animal Assignment operator for Cat called" << std::endl;
	return (*this);
} */

Cat::~Cat()
{
	delete this->_brain;
	if (M_DEBUG)
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

std::string	Cat::getIdea(int i) const
{
	return (this->_brain->getIdea(i));
}

void		Cat::setIdea(std::string idea, int i)
{
	this->_brain->setIdea(idea, i);
}
