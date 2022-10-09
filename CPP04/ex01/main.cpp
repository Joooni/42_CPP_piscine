#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#define	NUMBER_OF_ANIMALS	10

int main()
{
	Animal	*animals[NUMBER_OF_ANIMALS];

	for (int i = 0; i < NUMBER_OF_ANIMALS; i++)
	{
		if (i < NUMBER_OF_ANIMALS / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << animals[i]->getType() << std::endl;
	}

	Dog	*Doggo = new Dog();
	Dog *Borfer = new Dog();
	Doggo->getBrain()->setIdea("Where food", 0);
	Doggo->getBrain()->setIdea("Where mate", 1);
	Doggo->getBrain()->setIdea("Where sun", 2);
	Doggo->getBrain()->setIdea("Where bed", 3);
	std::cout << std::endl << "####################" << std::endl << std::endl;
	std::cout << "Doggos first thought is about food:" << std::endl;
	std::cout << Doggo->getBrain()->ideas[0] << std::endl;
	std::cout << "Borfers first thought:" << std::endl;
	std::cout << Borfer->getBrain()->ideas[0] << std::endl;

	(*Borfer) = (*Doggo);

	std::cout << "Doggos third thought:" << std::endl;
	std::cout << Doggo->getBrain()->ideas[3] << std::endl;
	std::cout << "Borfer fourth thought is about sleep:" << std::endl;
	std::cout << Borfer->getBrain()->ideas[3] << std::endl;
	std::cout << std::endl << "####################" << std::endl << std::endl;
	Doggo->setIdea("Butterflies", 0);
	std::cout << Doggo->getBrain()->ideas[0] << std::endl;
	std::cout << Borfer->getBrain()->ideas[0] << std::endl;
	delete Borfer;
	delete Doggo;
	for (int i = 0; i < NUMBER_OF_ANIMALS; i++)
		delete animals[i];
}
