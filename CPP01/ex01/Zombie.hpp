#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
	public:
		Zombie();
		~Zombie();
		void		announce();
		std::string	getName();
		void		setName(std::string name);

	private:
		std::string	name;
};


Zombie	*zombieHorde( int N, std::string name );

#endif
