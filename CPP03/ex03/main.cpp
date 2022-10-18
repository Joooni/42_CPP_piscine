#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << std::string(50, '-') << std::endl;
	{
	std::cout << std::endl << "Creating ClapTrap: " << std::endl;
	ClapTrap	Bratan("Bratan");
	std::cout << std::endl << "Creating ScavTrap: " << std::endl;
	ScavTrap	Bruh("Bruh");
	std::cout << std::endl << "Creating FragTrap: " << std::endl;
	FragTrap	Bre("Der Bre");
	std::cout << std::endl << "Creating DiamondTrap: " << std::endl;
	DiamondTrap	Brudi("Brudi");
	std::cout << std::endl;

	Bruh.beRepaired(1);
	Bratan.attack("den Bre");
	Bre.takeDamage(0);
	Bre.highFivesGuys();
	Bre.beRepaired(2);
	Bratan.takeDamage(6);
	Bratan.attack("Bruh");
	Bruh.takeDamage(0);
	Bruh.takeDamage(10);
	Bruh.beRepaired(10);
	Bruh.attack("den Bre");
	Bre.takeDamage(20);
	Bre.highFivesGuys();
	Bre.beRepaired(2);
	Bruh.attack("Bratan");
	Bratan.takeDamage(20);
	Bratan.beRepaired(4);
	Bratan.takeDamage(3);
	Bratan.beRepaired(8);
	Bratan.takeDamage(17);
	Bratan.beRepaired(10);
	Bruh.guardGate();
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	Bruh.beRepaired(10);
	}
	std::cout << std::string(50, '-') << std::endl;
	{
	std::cout << "and now for some diamond sheeeet" << std::endl;
	DiamondTrap DT;
	DT.attack("den Bratan");
	DT.beRepaired(5);
	DT.guardGate();
	DT.highFivesGuys();
	DT.takeDamage(5);
	DT.whoAmI();
	}
	return (0);
}
