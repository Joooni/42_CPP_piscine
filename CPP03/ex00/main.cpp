#include "ClapTrap.hpp"

int	main(void)
{

	{
		ClapTrap	Bratan("Bratan");
		ClapTrap	Ulf;
		Ulf.beRepaired(1);
		Ulf = Bratan;
		Bratan.attack("den Bre");
		Bratan.takeDamage(6);
		Bratan.beRepaired(4);
		Bratan.takeDamage(3);
		Bratan.beRepaired(8);
		Bratan.takeDamage(17);
		Bratan.attack(Ulf.getName());
	}
	std::cout << std::string(50, '-') << std::endl;
	{
		ClapTrap	Bre("Bre");
		ClapTrap	Bro;
		Bro = ClapTrap("habibi");
	}
	std::cout << std::string(50, '-') << std::endl;
	{
		ClapTrap	Alpha("Bre");
		ClapTrap	Beta = ClapTrap();
	}
}
