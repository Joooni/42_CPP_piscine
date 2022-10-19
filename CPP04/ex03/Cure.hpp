#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

# ifndef M_DEBUG
#  define M_DEBUG	1
# endif

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure &src);
		Cure	&operator=(const Cure &rhs);
		~Cure();

		virtual AMateria	*clone() const;
		virtual void		use(ICharacter &target);
};

#endif
