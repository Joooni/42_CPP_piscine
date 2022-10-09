#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#define	NUMBER_OF_ANIMALS	10

int main()
{
	AAnimal	*animals[NUMBER_OF_ANIMALS];

	for (int i = 0; i < NUMBER_OF_ANIMALS; i++)
	{
		if (i < NUMBER_OF_ANIMALS / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << animals[i]->getType() << std::endl;
	}

	Brain	*brain;
	brain = animals[4]->getBrain();
	brain->setIdea("Where food", 0);
	brain->setIdea("Where mate", 1);
	brain->setIdea("Where sun", 2);
	brain->setIdea("Where bed", 3);
	std::cout << std::endl << "####################" << std::endl << std::endl;
	std::cout << "Animal at Index 4 first thought is about food:" << std::endl;
	std::cout << animals[4]->getBrain()->ideas[0] << std::endl;

	*(animals[9]) = *(animals[4]);
	std::cout << "Animal at index 9 fourth thought is about sleep:" << std::endl;
	std::cout << animals[9]->getBrain()->ideas[3] << std::endl;
	std::cout << std::endl << "####################" << std::endl << std::endl;
	for (int i = 0; i < NUMBER_OF_ANIMALS; i++)
		delete animals[i];
}
