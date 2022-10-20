#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <string>
# include "AMateria.hpp"

# ifndef M_DEBUG
#  define M_DEBUG	0
# endif
class IMateriaSource
{
	public:
		virtual				~IMateriaSource() {}
		virtual void 		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
		virtual AMateria	*getKnownMateria(int idx) const = 0;
};

#endif
