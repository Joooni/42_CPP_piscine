#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Abstract Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	this->_type = src._type;
	std::cout << "Abstract Animal copy constructor called" << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &rhs)
{
	this->_type = rhs._type;
	std::cout << "Abstract Animal copy assignment operator called" << std::endl;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "Destructor Abstract Animal called" << std::endl;
}

const std::string	&AAnimal::getType() const
{
	return (this->_type);
}
