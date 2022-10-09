#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("other type of club");
		jim.attack();
	}
	{
		HumanB peter_zwegat("Peter Zwegat");
		Weapon bag_of_money = Weapon("giant bag of money");
		peter_zwegat.attack();
		peter_zwegat.setWeapon(bag_of_money);
		peter_zwegat.attack();
	}
	return 0;
}
