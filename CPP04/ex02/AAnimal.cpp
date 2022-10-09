#include "AAnimal.hpp"

AAnimal::~AAnimal(void)
{
	std::cout << "Destructor Abstract Animal called" << std::endl;
}

const std::string	&AAnimal::getType() const
{
	return (this->type);
}
