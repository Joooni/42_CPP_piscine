#include "Zombie.hpp"

Zombie::Zombie(std::string name): name(name)
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
