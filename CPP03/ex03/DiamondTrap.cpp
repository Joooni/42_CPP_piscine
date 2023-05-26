#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap()
{
	this->name = "Frankentrap";
	this->ClapTrap::name = this->name + "_clap_name";
	this->FragTrap::setHP();
	this->ScavTrap::setEP();
	this->FragTrap::setAD();
	std::cout << "Standard DiamondStructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): name(name)
{
	this->ClapTrap::name = this->name + "_clap_name";
	this->FragTrap::setHP();
	this->ScavTrap::setEP();
	this->FragTrap::setAD();
	std::cout << "DiamondStructor with name parameter called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ct): ClapTrap(ct.name),  ScavTrap(ct.name), FragTrap(ct.name)
{
	HP = ct.HP;
	EP = ct.EP;
	AD = ct.AD;
	std::cout << "copy DiamondStructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "copy assignment operator called" << std::endl;
	name = src.name;
	HP = src.HP;
	EP = src.EP;
	AD = src.AD;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondDestructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondName is " << this->name;
	std::cout << " ...but his ClapName is (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ " << this->ClapTrap::name << " ✧ﾟ･: *ヽ(◕ヮ◕ヽ)" << std::endl;
}
