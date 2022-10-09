#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
	public:
		Zombie(std::string);
		~Zombie();
		std::string	getName();
		void		announce();

	private:
		std::string	name;
};


void		randomChump(std::string name);
Zombie		*newZombie(std::string name);

#endif
