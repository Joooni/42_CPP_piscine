#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal &src);
		AAnimal	&operator=(const AAnimal &rhs);
		virtual	~AAnimal();

		const std::string	&getType() const;
		virtual void		makeSound() const = 0;

	protected:
		std::string			_type;
};

std::ostream	&operator<<(std::ostream &os, const AAnimal &aanimal);

#endif
