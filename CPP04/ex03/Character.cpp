#include "Character.hpp"


Character::Character(): _name("Tim the Wizard"), _num_equipped(0), _num_trash(0)
{
	for (int i = 0; i < Character::_inventory_size; i++)
		this->_inventory[i] = NULL;
	std::cout << "Default constructor Character called" << std::endl;
}

Character::Character(std::string name): _name(name), _num_equipped(0), _num_trash(0)
{
	for (int i = 0; i < Character::_inventory_size; i++)
		this->_inventory[i] = NULL;
	std::cout << "Name parameter constructor Character called" << std::endl;
}

Character::Character(const Character &src)
{
	this->_name = src.getName();
	for (int i = 0; i < Character::_inventory_size; i++)
	{
		this->_inventory[i] = src._inventory[i];
	}
}

Character &Character::operator=(const Character &rhs)
{
	this->_num_equipped = 0;
	for (int i = 0; i < Character::_inventory_size; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
		this->_inventory[i] = rhs._inventory[i]->clone();
		if (rhs._inventory[i] != NULL)
			this->_num_equipped++;
	}
	this->_name = rhs.getName();
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < this->_num_trash; i++)
		delete this->_trash[i];
	std::cout << "Character Destructor called" << std::endl;
}


std::string const	&Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	if (this->_num_equipped >= Character::_inventory_size)
		std::cout << this->getName() << " cannot equip new Materia, inventory is full" << std::endl;
	else
	{
		this->_inventory[this->_num_equipped] = m;
		this->_num_equipped++;
		std::cout << this->_name << " equipped " << m->getType() << " materia!" <<  std::endl;
	}

}

void	Character::unequip(int idx)
{
	if (this->_num_equipped == 0 || this->_inventory[idx] == NULL)
	{
		std::cout << this->getName() << " cannot unequip Materia it does not have" << std::endl;
		return ;
	}
	else
	{
		this->_trash[_num_trash] = this->_inventory[idx];
		this->_num_trash++;
		this->_inventory[idx] = NULL;
		this->_num_equipped--;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (this->_inventory[idx] == NULL)
		std::cout << "No Materia equipped at slot " << idx << std::endl;
	else
	{
		this->_inventory[idx]->use(target);
		this->unequip(idx);
	}
}
