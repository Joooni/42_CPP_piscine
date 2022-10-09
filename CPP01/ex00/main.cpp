#include "Zombie.hpp"

int	main(void)
{
	std::cout << "Creating Zombie Robert manually" << std::endl;
	Zombie	robert("Robert");
	robert.announce();
	std::cout << std::endl << "Creating Zombie Jeeves using the function newZombie" << std::endl << std::endl;
	Zombie	*Jeeves = newZombie("Jeeves");
	Jeeves->announce();
	delete Jeeves;
	std::cout << std::endl << "Creating the third Zombie, Mark, using the function randomChump" << std::endl << std::endl;
	randomChump("Mark");
	return (0);
}
