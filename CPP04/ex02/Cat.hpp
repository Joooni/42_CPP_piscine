#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class	Cat: public AAnimal
{
	public:
		Cat();
		Cat(const Cat &src);
		~Cat();
		Cat &operator=(const Cat &rhs);
		virtual AAnimal& operator=(const AAnimal &src);
		virtual void	makeSound() const;
		virtual Brain	*getBrain() const;

	private:
		Brain	*_brain;
};

#endif
