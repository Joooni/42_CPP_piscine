#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	if (M_DEBUG)
		std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &src): AMateria()
{
	this->_type = src.getType();
	if (M_DEBUG)
		std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure	&Cure::operator=(const Cure &rhs)
{
	this->_type = rhs.getType();
	return (*this);
	if (M_DEBUG)
		std::cout << "Cure copy assignment operator called" << std::endl;
}

AMateria	*Cure::clone() const
{
	AMateria *newCure = new Cure;
	return (newCure);
}


void		Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "`s wounds *" << std::endl;
}
