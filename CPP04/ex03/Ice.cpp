#include "Ice.hpp"

Ice::Ice()
{
	this->_type = "ice";
	if (M_DEBUG)
		std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &src): AMateria()
{
	this->_type = src.getType();
	if (M_DEBUG)
		std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice()
{
	if (M_DEBUG)
		std::cout << "Ice destructor called" << std::endl;
}

Ice	&Ice::operator=(const Ice &rhs)
{
	this->_type = rhs.getType();
	return (*this);
	if (M_DEBUG)
		std::cout << "Ice copy assignment operator called" << std::endl;
}

AMateria	*Ice::clone() const
{
	AMateria *newIce = new Ice();
	return (newIce);
}


void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
