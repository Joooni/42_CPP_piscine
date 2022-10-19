#include "Character.hpp"


Character::Character(): _name("Tim the Wizard"), _num_equipped(0)//, _num_trash(0)
{
	for (int i = 0; i < Character::_inventory_size; i++)
		this->_inventory[i] = NULL;
	if (M_DEBUG)
		std::cout << "Default constructor Character called" << std::endl;
}

Character::Character(std::string name): _name(name), _num_equipped(0)//, _num_trash(0)
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
	this->_num_equipped = 0;
	for (int i = 0; i < Character::_inventory_size; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (rhs._inventory[i])
		{
			this->_inventory[i] = rhs._inventory[i]->clone();
			this->_num_equipped++;
		}
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
	// for (int i = 0; i < this->_num_trash; i++)
	// 	delete this->_trash[i];
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
	if (this->_num_equipped >= Character::_inventory_size)
		std::cout << this->getName() << " cannot equip new Materia, inventory is full" << std::endl;
	else
	{
		while (i < Character::_inventory_size && this->_inventory[i])
			i++;
		this->_inventory[i] = m;
		this->_num_equipped++;
		std::cout << this->_name << " equipped " << m->getType() << " materia!" <<  std::endl;
	}

}

void	Character::unequip(int idx)
{

	if (this->_inventory[idx])
	{
		this->_inventory[idx] = NULL;
		this->_num_equipped--;
	}
	else
		std::cout << this->getName() << " cannot unequip Materia it does not have" << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (this->_inventory[idx] == NULL)
		std::cout << "No Materia equipped at slot " << idx << std::endl;
	else
		this->_inventory[idx]->use(target);
}
