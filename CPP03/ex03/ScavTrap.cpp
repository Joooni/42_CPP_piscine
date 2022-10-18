#include "ScavTrap.hpp"


ScavTrap::ScavTrap()
{
	this->name = "Scavalier";
	this->setHP();
	this->setEP();
	this->setAD();
	std::cout << "Standard ScavStructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->setHP();
	this->setEP();
	this->setAD();
	std::cout << "ScavStructor with name parameter called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ct): ClapTrap(ct.name)
{
	this->name = ct.name;
	this->HP = ct.HP;
	this->EP = ct.EP;
	this->AD = ct.AD;
	std::cout << "copy ScavStructor called" << std::endl;
	*this = ct;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "copy assignment operator called" << std::endl;
	name = src.name;
	HP = src.HP;
	EP = src.EP;
	AD = src.AD;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavDestructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->EP > 0 && this->HP > 0)
	{
		std::cout << "ScavTrap " << this->name << " scavs " << target << " right across the face, causing " << this->AD << " point of damage!" << std::endl;
		this->EP--;
	}
	else
		std::cout << "ScavTrap " << this->name << " has no " << (this->EP ? "HP left!" : "EP left!") << std::endl;
}

void	ScavTrap::guardGate() const
{
	std::cout << "ScavTrap " << this->name << " has entered guard mode!" << std::endl;
}

void	ScavTrap::setHP()
{
	this->HP = 100;
}

void	ScavTrap::setEP()
{
	this->EP = 50;
}

void	ScavTrap::setAD()
{
	this->AD = 20;
}
