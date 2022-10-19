#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "Standard Cat Constructor called, meow." << std::endl;
}

Cat::Cat(const Cat &src): Animal()
{
	*this = src;
	std::cout << "Cat Copy Constructor called, meow meow." << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat copy assigment operator" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called, sad meow :(" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meeeeeowwwwwwwww" << std::endl;
}
