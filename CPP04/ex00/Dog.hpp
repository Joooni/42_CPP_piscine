#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class	Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog &src);
		Dog	&operator=(const Dog& rhs);
		~Dog();

		virtual void makeSound() const;
};

#endif
