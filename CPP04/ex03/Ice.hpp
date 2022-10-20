#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

# ifndef M_DEBUG
#  define M_DEBUG	0
# endif
class Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice &src);
		~Ice();
		Ice	&operator=(const Ice &rhs);

		virtual AMateria	*clone() const;
		virtual void		use(ICharacter &target);
};

#endif
