#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	this->_brain = new Brain;
	std::cout << "Standard Cat Constructor called, meow." << std::endl;
}

Cat::Cat(const Cat &rhs): Animal()
{
	this->_type = rhs.getType();
	this->_brain = new Brain;
	*(this->_brain) = (*rhs._brain);
	std::cout << "Cat Copy Constructor called, meow meow." << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	this->_type = rhs.getType();
	*(this->_brain) = (*rhs._brain);
	std::cout << "Assignment operator Cat called" << std::endl;
	return (*this);
}

// Animal &Cat::operator=(const Animal &rhs)
// {
// 	this->_type = rhs.getType();
// 	*(this->_brain) = *(rhs.getBrain());
// 	std::cout << "Animal Assignment operator for Cat called" << std::endl;
// 	return (*this);
// }

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

std::string	Cat::getIdea(int i) const
{
	return (this->_brain->getIdea(i));
}

void		Cat::setIdea(std::string idea, int i)
{
	this->_brain->setIdea(idea, i);
}
