#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &ct);
		FragTrap& operator=(const FragTrap &src);
		~FragTrap();

		void	highFivesGuys(void);
		void	setHP();
		void	setEP();
		void	setAD();
};

#endif
