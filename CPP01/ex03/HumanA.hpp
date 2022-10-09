#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA {

	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void		attack() const;
		Weapon		&getWeapon() const;

	private:
		std::string	_name;
		Weapon		&_weapon;

};

#endif
