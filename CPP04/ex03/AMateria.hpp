#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

# include "ICharacter.hpp"

# ifndef M_DEBUG
#  define M_DEBUG	0
# endif

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;

	public:
					AMateria();
					AMateria( std::string const &type);
					AMateria(const AMateria &src);
		virtual		~AMateria();
		AMateria	&operator=(const AMateria &rhs);

		const std::string	&getType() const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target) = 0;
};

#endif
