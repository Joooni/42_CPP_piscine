#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	if (M_DEBUG)
		std::cout << "Standard Cat Constructor called, meow." << std::endl;
}

Cat::Cat(const Cat &src): Animal()
{
	*this = src;
	if (M_DEBUG)
		std::cout << "Cat Copy Constructor called, meow meow." << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (M_DEBUG)
		std::cout << "Cat copy assigment operator" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

Cat::~Cat()
{
	if (M_DEBUG)
		std::cout << "Cat Destructor called, sad meow :(" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meeeeeowwwwwwwww" << std::endl;
}
