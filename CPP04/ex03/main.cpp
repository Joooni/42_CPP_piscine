#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	std::cout << std::string(25, '-') << "TEST 1" << std::string(25, '-') << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		std::cout << std::string(50, '-') << std::endl;
		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << std::string(50, '-') << std::endl;
		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::string(25, '-') << "TEST 2" << std::string(25, '-') << std::endl;
	{
		//uncomment to check for an abstract class
		// AMateria a;
		Ice a;
		Cure b;
		Character victim("Burney");
		Character d;
		std::cout << std::string(50, '-') << std::endl;
		a.use(victim);
		b.use(victim);
		std::cout << std::string(50, '-') << std::endl;
		victim.unequip(0);
		victim.equip(&a);
		victim.equip(&a);
		victim.equip(&a);
		victim.equip(&a);
		std::cout << std::string(50, '-') << std::endl;
		victim.use(0, d);
		std::cout << std::string(50, '-') << std::endl;
		victim.unequip(0);
		victim.unequip(1);
		victim.unequip(2);
		victim.unequip(3);
		std::cout << std::string(50, '-') << std::endl;
	}
}
