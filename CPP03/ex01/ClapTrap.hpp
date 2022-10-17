#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class	ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &ct);
		ClapTrap& operator=(const ClapTrap &src);
		~ClapTrap();

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string	getName(void) const;

	protected:
		std::string	name;
		int			HP;
		int			EP;
		int			AD;
};

std::ostream	&operator<<( std::ostream &ostream, const ClapTrap &ct);

#endif
