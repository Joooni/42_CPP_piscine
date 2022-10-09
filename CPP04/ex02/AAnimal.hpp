#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class AAnimal
{
	public:
		virtual AAnimal();

		virtual ~AAnimal();
		virtual AAnimal		&operator=(const AAnimal &rhs);

		const std::string	&getType() const;
		virtual void		makeSound() const = 0;

	protected:
		std::string			type;
};

std::ostream	&operator<<(std::ostream &os, const AAnimal &aanimal);

#endif
