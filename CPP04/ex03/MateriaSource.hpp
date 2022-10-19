#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

# ifndef M_DEBUG
#  define M_DEBUG	1
# endif
class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &src);
		MateriaSource &operator=(const MateriaSource &rhs);
		~MateriaSource();

		void		learnMateria(AMateria *);
		AMateria 	*createMateria(std::string const &type);

		AMateria	*getKnownMateria(int idx) const;

	private:
		static const int	_known_materias_size = 4;
		AMateria			*_known_materias[MateriaSource::_known_materias_size];
		int					_num_known_materias;
};

#endif
