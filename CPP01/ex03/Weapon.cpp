#include "Weapon.hpp"

Weapon::Weapon(std::string type): type(type)
{

}

Weapon::~Weapon(void)
{

}

const std::string	&Weapon::getType() const
{
	return (this->type);
}

bool	Weapon::setType(const std::string &weaponType)
{
	if (weaponType == "")
	{
		std::cerr << "Can't input empty weapon" << std::endl;
		return (false);
	}
	this->type = weaponType;
	return (true);
}
