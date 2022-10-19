#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"


int main()
{
	std::cout << std::string(25, '-') << "TEST 1" << std::string(25, '-') << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		AMateria *IceBase = new Ice;
		AMateria *CureBase = new Cure;
		src->learnMateria(IceBase);
		src->learnMateria(CureBase);
		src->learnMateria(IceBase);
		src->learnMateria(CureBase);
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
		delete IceBase;
		delete CureBase;
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
		victim.unequip(0);
		victim.unequip(1);
		victim.unequip(2);
		victim.unequip(3);
		std::cout << std::string(50, '-') << std::endl;
	}
	{
		std::cout << "TEST FROM SUBJECT" << std::endl;
		IMateriaSource* src = new MateriaSource();
		Ice *newIce = new Ice;

		src->learnMateria(newIce);
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		Ice iceT;
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
		std::cout << std::string(50, '~') << std::endl;
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
		bob.equip(mixedsrc3.createMateria("ice"));
		bob.equip(mixedsrc3.createMateria("cure"));
		bob.equip(mixedsrc3.createMateria("ultima"));
		AMateria *tmp;
		for (int i = 0; i < 5; i++)
		{
			tmp = mixedsrc.createMateria("cure");
			bobcopy.equip(tmp);
		}
		bobcopy = bob;
		bob.equip(NULL);
		bob.use(0, *phil);
		bob.use(1, *phil);
		bob.unequip(0);
		bob.unequip(5);
		bob.use(0, *phil);
		delete tmp;
		delete icesrc;
		delete phil;
	}
	return (0);
}



