#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

# ifndef M_DEBUG
#  define M_DEBUG	0
# endif

class	Cat: public AAnimal
{
	public:
		Cat();
		Cat(const Cat &src);
		~Cat();
		Cat &operator=(const Cat &rhs);
		// virtual AAnimal& operator=(const AAnimal &src);
		virtual void	makeSound() const;
		virtual Brain	*getBrain() const;
		std::string		getIdea(int i) const;
		void			setIdea(std::string idea, int i);


	private:
		Brain	*_brain;
};

#endif
