#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class	Dog: public AAnimal
{
	public:
		Dog();
		Dog(const Dog &src);
		~Dog();
		Dog &operator=(const Dog &rhs);
		virtual AAnimal& operator=(const AAnimal &src);
		virtual void	makeSound() const;
		virtual Brain	*getBrain() const;

	private:
		Brain	*_brain;
};

#endif
