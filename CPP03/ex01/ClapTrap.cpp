#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : name("Claprich"), HP(10), EP(10), AD(0)
{
	std::cout << "Standard ClapStructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), HP(10), EP(10), AD(0)
{
	std::cout << "ClapStructor with name parameter called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ct)
{
	std::cout << "copy ClapStructor called" << std::endl;
	*this = ct;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "copy assignment operator called" << std::endl;
	name = src.name;
	HP = src.HP;
	EP = src.EP;
	AD = src.AD;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapDestructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->EP > 0 && this->HP > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->AD << " point of damage!" << std::endl;
		this->EP--;
	}
	else
		std::cout << "ClapTrap " << this->name << " has no " << (this->EP ? "HP left!" : "EP left!") << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " is hit and loses " << amount << " HP!" << std::endl;
	this->HP -= amount;
	if (this->HP <= 0)
		std::cout << "ClapTrap " << this->name << " falls unconscious!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EP > 0 && this->HP > 0)
	{
		std::cout << "ClapTrap " << this->name << " repairs " << amount << " points of damage!" << std::endl;
		this->HP += amount;
		this->EP--;
	}
	else
		std::cout << "ClapTrap " << this->name << " has no " << (this->EP ? "HP left!" : "EP left!") << std::endl;

}

std::string	ClapTrap::getName(void) const
{
	return (this->name);
}

std::ostream	&operator<<( std::ostream &ostream, ClapTrap const &ct)
{
	ostream << ct.getName();
	return (ostream);
}
