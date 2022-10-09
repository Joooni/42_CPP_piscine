#include "Zombie.hpp"

void	announceZombiesHorde( Zombie *zombieHorde, int	n)
{
	for (int i = 0; i < n; i++)
		zombieHorde[i].announce();
}

int	main(void)
{
	std::cout << "Creating Horde of Greg zombies" << std::endl;
	Zombie	*zombieHordePtr = zombieHorde(10, "Greg");
	announceZombiesHorde(zombieHordePtr, 10);

	delete[] zombieHordePtr;
	return (0);
}
