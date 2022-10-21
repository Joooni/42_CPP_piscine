#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

# ifndef M_DEBUG
#  define M_DEBUG	0
# endif


class	Animal
{
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &ct);
		virtual Animal& operator=(const Animal &src);
		virtual ~Animal();

		const std::string	getType() const;
		virtual void		makeSound() const;
		// virtual Brain		*getBrain() const;

	protected:
		std::string _type;
};

std::ostream &operator<<(std::ostream &os, const Animal &animal);

#endif
