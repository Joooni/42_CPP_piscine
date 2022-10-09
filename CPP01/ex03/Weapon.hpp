#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon {

	public:
		Weapon(std::string type);
		~Weapon();
		const std::string	&getType() const;
		bool				setType(const std::string &weaponType);

	private:
		std::string	type;

};

#endif
