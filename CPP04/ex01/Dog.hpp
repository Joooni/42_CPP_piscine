#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

# ifndef M_DEBUG
#  define M_DEBUG	0
# endif


class	Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog &src);
		~Dog();
		Dog &operator=(const Dog &rhs);
		// virtual Animal& operator=(const Animal &src);
		virtual void	makeSound() const;
		virtual Brain	*getBrain() const;
		std::string		getIdea(int i) const;
		void			setIdea(std::string idea, int i);

	private:
		Brain	*_brain;
};

#endif
