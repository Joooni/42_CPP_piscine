#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::~Zombie()
{
	std::cout << this->name << ": *crumbles to dust as it dies*" << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName()
{
	return (this->name);
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
