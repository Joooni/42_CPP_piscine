#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(const Character &src);
		Character &operator=(const Character &rhs);
		~Character();

		virtual std::string const	&getName() const;
		virtual void				equip(AMateria *m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter &target);

	private:
		static const int	_inventory_size = 4;

		std::string	_name;
		AMateria	*_inventory[Character::_inventory_size];
		int			_num_equipped;
		AMateria	*_trash[100];
		int			_num_trash;
};

#endif
