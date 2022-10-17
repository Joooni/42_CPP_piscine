#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &ct);
		ScavTrap& operator=(const ScavTrap &src);
		~ScavTrap();

		void	attack(const std::string &target);
		void	guardGate() const;
		void	setHP();
		void	setEP();
		void	setAD();
};

#endif
