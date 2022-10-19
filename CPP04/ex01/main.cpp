#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#define	NUMBER_OF_ANIMALS	10

int main()
{
	{
	std::cout << std::string(50, '-') << std::endl;
	std::cout << "Creation of Animal Array" << std::endl;
	std::cout << std::string(50, '-') << std::endl;
	Animal	*animals[NUMBER_OF_ANIMALS];

	for (int i = 0; i < NUMBER_OF_ANIMALS; i++)
	{
		if (i < NUMBER_OF_ANIMALS / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << animals[i]->getType() << std::endl;
	}
	std::cout << std::string(50, '-') << std::endl;
	std::cout << "Check if Brain works" << std::endl;
	std::cout << std::string(50, '-') << std::endl;
	Dog	*Doggo = new Dog();
	Dog *Borfer = new Dog();
	Doggo->getBrain()->setIdea("Where food", 0);
	Doggo->getBrain()->setIdea("Where mate", 1);
	Doggo->getBrain()->setIdea("Where sun", 2);
	Doggo->getBrain()->setIdea("Where bed", 3);
	std::cout << std::endl << "####################" << std::endl << std::endl;
	std::cout << "Doggos first thought is about food:" << std::endl;
	std::cout << Doggo->getBrain()->getIdea(0) << std::endl;
	std::cout << "Borfers first thought:" << std::endl;
	std::cout << Borfer->getBrain()->getIdea(0) << std::endl;

	std::cout << std::string(50, '-') << std::endl;
	std::cout << "Check for deepest of copies" << std::endl;
	std::cout << std::string(50, '-') << std::endl;
	(*Borfer) = (*Doggo);

	std::cout << "Doggos fourth thought:" << std::endl;
	std::cout << Doggo->getBrain()->getIdea(3) << std::endl;
	std::cout << "Borfers fourth thought is about sleep:" << std::endl;
	std::cout << Borfer->getBrain()->getIdea(3) << std::endl;
	std::cout << std::endl << "####################" << std::endl << std::endl;
	std::cout << "Set first idea of doggo to Butterflies" << std::endl;
	Doggo->setIdea("Butterflies", 0);
	std::cout << "Doggos first thought:" << std::endl;
	std::cout << Doggo->getBrain()->getIdea(0) << std::endl;
	std::cout << "Borfers first thought:" << std::endl;
	std::cout << Borfer->getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl << std::string(50, '-') << std::endl << std::endl;
	delete Borfer;
	delete Doggo;
	for (int i = 0; i < NUMBER_OF_ANIMALS; i++)
		delete animals[i];
	}
	{
		std::cout << std::string(80, '-') << std::endl;
		std::cout << "TEST FROM SUBJECT" << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	{
		std::cout << std::string(80, '-') << std::endl;
		std::cout << "MY OWN TESTS" << std::endl;
	Animal *arr[10];
		for (int i = 0; i < 5; i++)
		{
			arr[i] = new Cat();
			arr[i+5] = new Dog();
		}
	// 	int index = 5;
	// 	std::cout << "\x1B[32m" << static_cast<Cat*>(arr[0])->getIdea(index) << "\033[0m" << std::endl;
	// 	std::cout << "\x1B[33m" << static_cast<Dog*>(arr[5])->getIdea(index) << "\033[0m" << std::endl;
	// 	static_cast<Cat*>(arr[0])->setIdea("YOU KNOW WHAT I'LL JUST SLEEP", index);
	// 	std::cout << "\x1B[32m" << static_cast<Cat*>(arr[0])->getIdea(index) << "\033[0m" << std::endl;
	// 	std::cout << "\x1B[33m" << static_cast<Dog*>(arr[5])->getIdea(index) << "\033[0m" << std::endl;
		Dog tempDog(*static_cast<Dog*>(arr[0]));
	// 	std::cout << "\x1B[32m" << tempDog.getIdea(index) << "\033[0m" <<std::endl;
		Dog tempDog2;
	// 	std::cout << "\x1B[32m" << tempDog2.getIdea(index) << "\033[0m" << std::endl;
		tempDog2 = tempDog;
		Dog tempDog3;
		tempDog3 = tempDog2;
	// 	std::cout << "\x1B[32m" << tempDog2.getIdea(index) << "\033[0m" << std::endl;
		for (int i = 0; i < 10; i++)
			delete arr[i];
	}
}
