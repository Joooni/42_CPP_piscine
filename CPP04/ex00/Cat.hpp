#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class	Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat &src);
		Cat	&operator=(const Cat& rhs);
		~Cat();

		virtual void	makeSound() const;
};

#endif
