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
		victim.use(1, d);
		std::cout << std::string(50, '-') << std::endl;
		victim.use(0, d);
		victim.equip(&b);
		victim.equip(&b);
		std::cout << std::string(10, '=') << std::endl;
		victim.unequip(0);
		victim.unequip(1);
		victim.unequip(2);
		victim.unequip(3);
		std::cout << std::string(50, '-') << std::endl;
	}
	{
		std::cout << "TEST FROM SUBJECT" << std::endl;
		IMateriaSource* src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << std::string(50, '-') << std::endl;
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "MY TEST" << std::endl;
		IMateriaSource *icesrc = new MateriaSource();
		MateriaSource mixedsrc;
		for (int i = 0; i < 4; i++)
			icesrc->learnMateria(new Ice());
		mixedsrc.learnMateria(new Ice());
		mixedsrc.learnMateria(new Cure());
		mixedsrc.learnMateria(new Ice());
		mixedsrc.learnMateria(new Cure());
		icesrc->learnMateria(new Ice());
		mixedsrc.learnMateria(new Ice());
		MateriaSource mixedsrc2(mixedsrc);
		MateriaSource mixedsrc3;
		mixedsrc3 = mixedsrc2;
		ICharacter *phil = new Character("phil");
		Character bob("bob");
		Character bobcopy;
		phil->use(0, bob);
		bob.use(0, *phil);
		Cure	tmpCure;
		Ice tmpIce;
		bob.equip(&tmpIce);
		// std::cout << std::string(10, '~') << std::endl;
		// bob.equip(mixedsrc3.createMateria("not actually a materia"));
		// std::cout << std::string(10, '~') << std::endl;
		// AMateria *tmp;
		// for (int i = 0; i < 5; i++)
		// {
		// 	tmp = mixedsrc.createMateria("cure");
		// 	bobcopy.equip(tmp);
		// }
		// bobcopy.use(0, bob);
		// bobcopy = bob;
		// bobcopy.use(0, bob);
		// std::cout << std::string(10, '~') << std::endl;
		// bob.equip(NULL);
		// std::cout << std::string(10, '~') << std::endl;
		// bob.use(0, *phil);
		// bob.use(1, *phil);
		// bob.use(2, *phil);
		// bob.use(3, *phil);
		// std::cout << std::string(10, '~') << std::endl;
		// std::cout << "equipping 4 more tmpIce to bob" << std::endl;
		bob.equip(&tmpIce);
		bob.equip(&tmpIce);
		bob.equip(&tmpIce);
		bob.equip(&tmpIce);
		// std::cout << std::string(10, '~') << std::endl;
		// bob.use(0, *phil);
		// bob.use(1, *phil);
		// bob.use(2, *phil);
		// bob.use(3, *phil);
		bob.unequip(0);
		bob.unequip(1);
		bob.unequip(2);
		bob.unequip(3);
		bob.unequip(5);
		// bob.use(0, *phil);
		delete icesrc;
		delete phil;
	}
	return (0);
}



