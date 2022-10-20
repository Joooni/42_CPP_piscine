#include "Character.hpp"


Character::Character(): _name("Tim the Wizard")
{
	for (int i = 0; i < Character::_inventory_size; i++)
		this->_inventory[i] = NULL;
	if (M_DEBUG)
		std::cout << "Default constructor Character called" << std::endl;
}

Character::Character(std::string name): _name(name)
{
	for (int i = 0; i < Character::_inventory_size; i++)
		this->_inventory[i] = NULL;
	if (M_DEBUG)
		std::cout << "Name parameter constructor Character called" << std::endl;
}

Character::Character(const Character &src): _name(src._name)
{
	for (int i = 0; i < Character::_inventory_size; i++)
	{
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
	}
}

Character &Character::operator=(const Character &rhs)
{
	for (int i = 0; i < Character::_inventory_size; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;

	}
	this->_name = rhs.getName();
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < Character::_inventory_size; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	if (M_DEBUG)
		std::cout << "Character Destructor called" << std::endl;
}


std::string const	&Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	int i = 0;

	if (!m)
		return ;
	while (i < Character::_inventory_size && this->_inventory[i])
		i++;
	if (i >= Character::_inventory_size)
		std::cout << this->getName() << " cannot equip new Materia, inventory is full" << std::endl;
	else
	{
		this->_inventory[i] = m;
		std::cout << this->_name << " equipped " << m->getType() << " materia in slot [" << i << "]" <<  std::endl;
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 4)
	{
		std::cout << this->getName() << "s' inventory does not hold that much Materia" << std::endl;
		return ;
	}
	if (this->_inventory[idx])
	{
		if (M_DEBUG)
			std::cout << this->_name << " unequipped Materia " << this->_inventory[idx]->getType() << " at Index [" << idx << "]!" << std::endl;
		this->_inventory[idx] = 0;
	}
	else
		std::cout << this->getName() << " cannot unequip Materia it does not have" << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (this->_inventory[idx] && idx < 4)
		this->_inventory[idx]->use(target);
	else
		std::cout << "No Materia equipped at slot " << idx << std::endl;
}
