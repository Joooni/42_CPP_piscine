#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
{
	std::cout << "Animal without type:" << std::endl;
	const Animal* Randimal = new Animal();
	std::cout << std::endl << "Animal type Dog:" << std::endl;
	const Animal* Kluntje = new Dog();
	std::cout << std::endl << "Animal type Cat:" << std::endl;
	const Animal* Felix = new Cat();

	std::cout << Kluntje->getType() << std::endl;
	std::cout << Felix->getType() << std::endl;
	Randimal->makeSound();
	Felix->makeSound();
	Kluntje->makeSound();
	std::cout << std::endl << "Animal destruction:" << std::endl;
	delete Randimal;
	std::cout << std::endl << "Cat destruction:" << std::endl;
	delete Felix;
	std::cout << std::endl << "Dog destruction:" << std::endl;
	delete Kluntje;
}
{
	std::cout << std::endl << "WrongAnimal without type:" << std::endl;
	const WrongAnimal metaWrong;
	std::cout << std::endl << "WrongAnimal type WrongCat:" << std::endl;
	const WrongAnimal* catWrong = new WrongCat();
	const WrongCat	justawrongcat;

	std::cout << catWrong->getType() << std::endl;
	std::cout << "WrongAnimal, make a sound: " << std::endl;
	metaWrong.makeSound();
	std::cout << "WrongAnimal instanced as WrongCat, make a sound: " << std::endl;
	catWrong->makeSound();
	std::cout << "Just a WrongCat, making a sound: " << std::endl;
	justawrongcat.makeSound();

	std::cout << std::endl << "WrongCat destruction:" << std::endl;
	delete catWrong;
}
	return (0);
}
