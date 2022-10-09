#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{

}

HumanB::~HumanB()
{

}

void	HumanB::attack() const
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with their bare (or bear) hands!" << std::endl;
}

Weapon&	HumanB::getWeapon() const
{
	return (*(this->_weapon));
}

bool	HumanB::setWeapon(Weapon &newWeapon)
{
	if (newWeapon.getType() == "")
	{
		std::cerr << "Can't input empty weapon" << std::endl;
		return (false);
	}
	this->_weapon = &newWeapon;
	return (true);
}
