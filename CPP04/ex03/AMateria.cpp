#include "AMateria.hpp"

// Constrcutors, destructors, OCCF stuff

AMateria::AMateria(): _type("AMaterium")
{
	if (M_DEBUG)
		std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria( std::string const&type): _type(type)
{
	if (M_DEBUG)
		std::cout << "AMateria name constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &src): _type(src._type)
{
	if (M_DEBUG)
		std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria()
{
	if (M_DEBUG)
		std::cout << "AMateria destructor called" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &rhs)
{
	this->_type = rhs.getType();
	return (*this);
	if (M_DEBUG)
		std::cout << "AMateria copy assignment called" << std::endl;
}

// member functions

const std::string	&AMateria::getType() const
{
	return (this->_type);
}
