#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

# ifndef M_DEBUG
#  define M_DEBUG	0
# endif

class Character: public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(const Character &src);
		Character &operator=(const Character &rhs);
		~Character();

		std::string const	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

	private:
		static const int	_inventory_size = 4;

		std::string	_name;
		AMateria	*_inventory[Character::_inventory_size];
		// AMateria	*_trash[100];
		// int			_num_trash;
};

#endif
