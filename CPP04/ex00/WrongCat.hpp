#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

# ifndef M_DEBUG
#  define M_DEBUG	0
# endif


class	WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &src);
		WrongCat &operator=(const WrongCat &rhs);
		~WrongCat();

		void makeSound() const;
};

#endif
