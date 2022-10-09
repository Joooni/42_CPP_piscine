#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class	Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat &src);
		~Cat();
		Cat &operator=(const Cat &rhs);
		// virtual Animal& operator=(const Animal &src);
		virtual void	makeSound() const;
		Brain			*getBrain() const;
		std::string		getIdea(int i) const;
		void			setIdea(std::string idea, int i);

	private:
		Brain	*_brain;
};

#endif
