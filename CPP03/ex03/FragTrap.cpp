#include "FragTrap.hpp"


FragTrap::FragTrap()
{
	this->name = "Fragziska";
	this->setHP();
	this->setEP();
	this->setAD();
	std::cout << "Standard FragStructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->setHP();
	this->setEP();
	this->setAD();
	std::cout << "FragStructor with name parameter called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ct): ClapTrap(ct.name)
{
	this->name = ct.name;
	this->HP = ct.HP;
	this->EP = ct.EP;
	this->AD = ct.AD;
	std::cout << "copy FragStructor called" << std::endl;
	*this = ct;
}

FragTrap& FragTrap::operator=(const FragTrap &src)
{
	std::cout << "copy assignment operator called" << std::endl;
	name = src.name;
	HP = src.HP;
	EP = src.EP;
	AD = src.AD;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragDestructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " raises his hand in happy anticipation of the most epic high five to have ever been hit!" << std::endl;
}

void	FragTrap::setHP()
{
	this->HP = 100;
}

void	FragTrap::setEP()
{
	this->EP = 100;
}

void	FragTrap::setAD()
{
	this->AD = 30;
}
