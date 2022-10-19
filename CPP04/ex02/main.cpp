#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
	{
		Dog Borfer;
		Borfer.getBrain()->setIdea("where food", 0);
		std::cout << "Idea[0]: " << Borfer.getBrain()->getIdea(0) << std::endl;
	}
	std::cout << std::string(50, '-') << std::endl;
	{
		Cat Felix;
		std::cout << "Idea[0]: " << Felix.getBrain()->getIdea(0) << std::endl;
		Felix.getBrain()->setIdea("where bed", 0);
		std::cout << "Idea set" << std::endl;
		std::cout << "Idea[0]: " << Felix.getBrain()->getIdea(0) << std::endl;
	}
	std::cout << std::string(50, '-') << std::endl;
	std::cout << "shallow copy test"  << std::endl;
	std::cout << std::string(50, '-') << std::endl;
	{
		std::cout << "Check if Brain works" << std::endl;
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

		std::cout << std::string(50, '-') << std::endl;
		std::cout << "Check for deepest of copies" << std::endl;
		std::cout << std::string(50, '-') << std::endl;
		(*Borfer) = (*Doggo);

		std::cout << "Doggos fourth thought:" << std::endl;
		std::cout << Doggo->getBrain()->ideas[3] << std::endl;
		std::cout << "Borfers fourth thought should be the same:" << std::endl;
		std::cout << Borfer->getBrain()->ideas[3] << std::endl;
		std::cout << std::endl << "####################" << std::endl << std::endl;
		std::cout << "Set first idea of doggo to Butterflies" << std::endl;
		Doggo->setIdea("Butterflies", 0);
		std::cout << "Doggos first thought:" << std::endl;
		std::cout << Doggo->getBrain()->ideas[0] << std::endl;
		std::cout << "Borfers first thought:" << std::endl;
		std::cout << Borfer->getBrain()->ideas[0] << std::endl;
		std::cout << std::endl << std::string(50, '-') << std::endl << std::endl;
		delete Borfer;
		delete Doggo;
	}
	std::cout << std::string(50, '-') << std::endl;
	{
		// uncomment for demonstrating that it is an abstract class
		// AAnimal a = new AAnimal;
	}
	return (0);
}
