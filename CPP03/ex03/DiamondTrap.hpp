#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &dt);
		DiamondTrap& operator=(const DiamondTrap &src);
		~DiamondTrap();

		void	whoAmI();

	private:
		std::string	name;
};

#endif
